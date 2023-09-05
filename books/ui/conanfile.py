from __future__ import annotations

import contextlib
import os
import subprocess
from functools import cached_property
from pathlib import Path
from typing import ClassVar

from conan import ConanFile
from conan.tools.cmake import CMake
from conan.tools.cmake import cmake_layout
from conan.tools.cmake import CMakeDeps
from conan.tools.cmake import CMakeToolchain


ConanBool = [True, False]


__version__: str = "0.133.1"


class T5HOBRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    name = "t5hob"
    license = "MIT"
    description = "t5hob native client with qt qml"
    version = __version__
    build_policy = "missing"
    options: ClassVar[dict] = {"verbose": ConanBool, "test": ConanBool}
    default_options: ClassVar[dict] = {
        "verbose": False,
        "test": False,
    }

    exports_sources = "CMakeLists.txt", "include/*", "pyproject.toml"

    def requirements(self) -> None:
        ...

    def build_requirements(self) -> None:
        self.test_requires("catch2/3.4.0")

    def layout(self) -> None:
        cmake_layout(self)

    @property
    def os_name(self):
        return self.settings.os.value.lower()

    def is_windows(self) -> bool:
        return self.os_name == "windows"

    def is_linux(self) -> bool:
        return self.os_name == "linux"

    @cached_property
    def qt_version(self) -> str:
        return "6.5.0"

    @property
    def qt_arch(self) -> str:
        if self.is_linux():
            return "gcc_64"
        elif self.is_windows():
            return "win64_mingw"

    @cached_property
    def aqt_install_dir(self) -> Path:
        ret = Path.home() / "MyConnandeps" / "Qt"

        if not ret.exists():
            ret.mkdir(parents=True)
        return ret

    @property
    def qt6_install_dir(self) -> Path | None:
        relative_to = self.aqt_install_dir / self.qt_version
        if relative_to.exists():
            with contextlib.suppress(StopIteration):
                res = next(relative_to.rglob("Qt6Config.cmake"))
                p = res.resolve(True)
                return p.parent

    @property
    def should_test(self) -> bool:
        return False

    def generate(self) -> None:
        if not self.qt6_install_dir:
            subprocess.run(
                f"poetry run aqt install-qt {self.os_name} "  # noqa
                f"desktop {self.qt_version} {self.qt_arch} "
                f"--outputdir {self.aqt_install_dir} "
                f"-m qtwebsockets qtlocation qtpositioning".split(" "),
                check=True,
            )
        paths = os.environ.get("PATH").split(":")
        paths.append(
            (self.qt6_install_dir.parent.parent.parent / "bin").resolve(True).as_uri(),
        )
        os.environ.setdefault("PATH", ":".join(paths))
        assert self.qt6_install_dir
        assert self.qt6_install_dir.exists()
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.cache_variables["T5HOB_TESTING"] = self.should_test
        tc.cache_variables["Qt6_DIR"] = str(self.qt6_install_dir)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["5hob"]  # checks that can link against this lib name.
