from __future__ import annotations

import contextlib
import glob
import os
import subprocess
from functools import cached_property
from pathlib import Path
from typing import ClassVar

from conan import ConanFile
from conan.tools.cmake import CMake, CMakeDeps, CMakeToolchain, cmake_layout


class PATHS:
    PROJECT_ROOT: ClassVar[Path] = Path(__file__).parent


ConanBool = [True, False]


class CountriesRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    name = "countries"
    license = "MIT"
    author = "Nir Benlulu nrbnlulu@gmail.com"
    url = "https://github.com/qtgql/examples"
    description = "GraphQL codegen client library for Qt"
    topics = ("GraphQL", "Qt", "codegen")
    version = "0.1.0"
    build_policy = "missing"
    options = {"qt_version": ["6.5.0"]}  # noqa
    default_options = {  # noqa
        "qt_version": "6.5.0",
    }

    exports_sources = "CMakeLists.txt", "include/*", "pyproject.toml"

    def requirements(self) -> None:
        ...

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
        qt_version = self.options.qt_version.value
        if self.is_windows() and "6.5" in qt_version:
            return "6.5.0"
        return qt_version

    @property
    def qt_arch(self) -> str:
        if self.is_linux():
            return "gcc_64"
        elif self.is_windows():
            return "win64_mingw"
        return None

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
            prev = Path.cwd()
            os.chdir(relative_to)
            res = glob.glob("**/Qt6Config.cmake", recursive=True)
            os.chdir(prev)
            with contextlib.suppress(IndexError):
                p = (relative_to / res[0]).resolve(True)
                return p.parent
        return None

    def generate(self) -> None:
        if not self.qt6_install_dir:
            subprocess.run(
                f"poetry run aqt install-qt {self.os_name} "
                f"desktop {self.qt_version} {self.qt_arch} "
                f"--outputdir {self.aqt_install_dir} "
                f"-m qtwebsockets".split(" "),
            ).check_returncode()
        os.environ.setdefault(
            "QT_PLUGIN_PATH",
            (self.qt6_install_dir.parent.parent.parent / "plugins").resolve(True).as_uri(),
        )
        os.environ.setdefault(
            "LD_LIBRARY_PATH",
            (self.qt6_install_dir.parent.parent.parent / "lib").resolve(True).as_uri(),
        )
        paths = os.environ.get("PATH").split(":")
        paths.append((self.qt6_install_dir.parent.parent.parent / "bin").resolve(True).as_uri())
        os.environ.setdefault("PATH", ":".join(paths))
        assert self.qt6_install_dir
        assert self.qt6_install_dir.exists()
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.cache_variables["Qt6_DIR"] = str(self.qt6_install_dir)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()
