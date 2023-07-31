import os
from conan.cli.cli import main

if __name__ == "__main__":
    os.environ.setdefault("NOT_ON_C3I", "1")
    os.environ.setdefault("CMAKE_STD_NAMESPACE", "ON")
    main("install . --build=missing --profile=profiles/Linux".split(" "))