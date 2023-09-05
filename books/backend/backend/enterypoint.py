import contextlib
from collections.abc import AsyncIterator

import fastapi
from aioinject.ext.fastapi import InjectMiddleware
from strawberry.fastapi.router import GraphQLRouter

from backend.di import container
from backend.gql.schema import schema


@contextlib.asynccontextmanager
async def lifespan(_: fastapi.FastAPI) -> AsyncIterator[None]:
    async with contextlib.aclosing(container):
        yield


app = fastapi.FastAPI(lifespan=lifespan)
app.include_router(
    GraphQLRouter(schema=schema, allow_queries_via_get=True),
    prefix="/graphql",
)
app.add_middleware(
    InjectMiddleware,
    container=container,
)


def enterypoint() -> fastapi.FastAPI:
    return app


if __name__ == "__main__":
    import uvicorn

    uvicorn.run(app, host="0.0.0.0", port=8000)  # noqa: S104
