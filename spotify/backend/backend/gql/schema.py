from aioinject.ext.strawberry import ContainerExtension
from strawberry import Schema
from strawberry.extensions import ParserCache, ValidationCache
from strawberry.tools import merge_types

from backend.apps import books
from backend.di import container

query = merge_types(
    name="Query",
    types=(books.config.graphql_config.query,),
)

mutation = merge_types(
    name="Mutation",
    types=(books.config.graphql_config.mutation,),
)

schema = Schema(
    query=query,
    mutation=mutation,
    extensions=[
        ParserCache(maxsize=128),
        ValidationCache(maxsize=128),
        ContainerExtension(container=container),
    ],
)
