from __future__ import annotations

from typing import Annotated

import strawberry
from aioinject import Inject
from aioinject.ext.strawberry import inject

from backend.apps.books.db import BookService
from backend.apps.books.gql.types import BookGQL
from backend.gql.errors import EntityAlreadyExistsErrorGQL


@strawberry.input()
class CreateBookInput:
    title: str
    author: str
    content: str


@strawberry.type(name="BookCreatePayload")
class BookCreatePayload:
    result: BookGQL | None
    error: BookCreateErrors | None


BookCreateErrors = Annotated[
    EntityAlreadyExistsErrorGQL,
    strawberry.union(name="BookCreateErrors"),
]


@strawberry.type()
class BookMutation:
    @strawberry.mutation()
    @inject
    async def create_book(
        self,
        input: CreateBookInput,
        book_service: Annotated[BookService, Inject],
    ) -> BookCreatePayload:
        result = await book_service.create_book(
            content=input.content,
            author=input.author,
            title=input.title,
        )
        return BookCreatePayload(
            result=BookGQL.from_orm(result.unwrap()),
            error=None,
        )
