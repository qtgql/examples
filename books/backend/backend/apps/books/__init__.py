from backend.apps.books import db
from backend.apps.books.db import providers
from backend.apps.books.gql import graphql_config
from backend.core import AppConfig

config = AppConfig(
    graphql_config=graphql_config,
    providers=providers,
    tables=[db.Book],
)

__all__ = ["config"]
