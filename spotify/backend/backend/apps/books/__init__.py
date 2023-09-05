from backend.apps.books.db import providers
from backend.apps.books.gql import graphql_config
from backend.core import AppConfig

config = AppConfig(
    graphql_config=graphql_config,
    providers=providers,
)

__all__ = ["config"]
