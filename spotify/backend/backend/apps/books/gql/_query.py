from __future__ import annotations

from typing import Annotated

import strawberry
from aioinject import Inject
from aioinject.ext.strawberry import inject

from backend.apps.books.db.service import BookService

from .types import BookGQL


@strawberry.type()
class BookQuery:
    @strawberry.field()
    @inject
    @staticmethod
    async def book_by_id(
        book_id: strawberry.ID,
        book_service: Annotated[BookService, Inject],
    ) -> BookGQL | None:
        try:
            if ret := await book_service.book_by_id(int(book_id)):
                return BookGQL.from_orm(ret)
        except ValueError:
            return None
