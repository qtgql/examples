import strawberry
from typing_extensions import Self

from backend.apps.books.db import Book
from backend.gql import DTOMixin, Node


@strawberry.type(name="Book")
class BookGQL(Node, DTOMixin[Book]):
    title: str
    author: str
    content: str

    @classmethod
    def from_orm(cls, model: Book) -> Self:
        return BookGQL(
            _id=strawberry.ID(str(model.id)),
            title=model.title,
            author=model.author,
            content=model.content,
        )
