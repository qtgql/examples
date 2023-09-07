from collections.abc import Iterable
from typing import Any

import aioinject
from aioinject import Provider

from backend.apps import books
from backend.db import create_engine, create_session

providers: Iterable[Provider[Any]] = [
    *books.config.providers,
    aioinject.Singleton(create_engine),
    aioinject.Callable(create_session),
]

container = aioinject.Container()

for provider in providers:
    container.register(provider)


__all__ = ["container"]
