from __future__ import annotations

import dataclasses
from dataclasses import dataclass
from typing import TYPE_CHECKING

from aioinject import Provider
from typing_extensions import Any

if TYPE_CHECKING:
    from backend.core import BaseTable


@dataclass
class GraphQLConfig:
    query: type | None = None
    mutation: type | None = None
    subscriptions: type | None = None
    types: list[type] = dataclasses.field(default_factory=list)


@dataclass
class AppConfig:
    providers: list[Provider[Any]] = dataclasses.field(default_factory=list)
    graphql_config: GraphQLConfig | None = None
    tables: list[BaseTable] = dataclasses.field(default_factory=list)
