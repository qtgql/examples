from collections.abc import Iterable
from typing import Any

import aioinject
from aioinject import Provider

from backend import core
from backend.apps import books

providers: Iterable[Provider[Any]] = [
    *core.providers,
    *books.config.providers,
]

container = aioinject.Container()

for provider in providers:
    container.register(provider)


__all__ = ["container"]
