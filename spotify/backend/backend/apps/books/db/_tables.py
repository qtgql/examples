from sqlalchemy.orm import Mapped, mapped_column
from sqlalchemy.types import UnicodeText

from backend.core.db import BaseTable


class Book(BaseTable):
    __tablename__ = "book"
    id: Mapped[int] = mapped_column(primary_key=True)
    title: Mapped[str]
    author: Mapped[str]
    content: Mapped[str] = mapped_column(UnicodeText)
