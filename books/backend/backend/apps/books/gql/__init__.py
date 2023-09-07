from backend.core.appconfig import GraphQLConfig

from ._mutations import BookMutation
from ._query import BookQuery

graphql_config = GraphQLConfig(
    query=BookQuery,
    mutation=BookMutation,
)

__all__ = [
    "graphql_config",
]
