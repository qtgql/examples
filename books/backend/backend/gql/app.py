from __future__ import annotations

from strawberry.fastapi.router import GraphQLRouter

from .context import Context
from .dataloaders import create_dataloaders
from .schema import schema


def get_context(
    **kwargs: dict,
) -> Context:
    return Context(
        **kwargs,
        loaders=create_dataloaders(),
    )


def create_graphql_app() -> GraphQLRouter[Context, None]:
    return GraphQLRouter(
        context_getter=get_context,
        schema=schema,
    )
