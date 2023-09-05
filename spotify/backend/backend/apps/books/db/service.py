from __future__ import annotations

from sqlalchemy import Select, select
from sqlalchemy.ext.asyncio import AsyncSession

from ._tables import Book


class BookService:
    def __init__(self, session: AsyncSession) -> None:
        self._session = session

    @property
    def _books(self) -> Select[tuple[Book]]:
        return select(Book)

    async def book_by_id(self, book_id: int) -> Book | None:
        stmt = self._books.where(Book.id == book_id)
        return (await self._session.scalars(stmt)).one_or_none()

    async def all_books(self) -> list[Book]:
        return list(await self._session.scalars(self._books))

    async def create_book(self, content: str, author: str, title: str) -> Book:
        book = Book(
            content=content,
            author=author,
            title=title,
        )
        self._session.add(book)
        await self._session.flush()
        return book
