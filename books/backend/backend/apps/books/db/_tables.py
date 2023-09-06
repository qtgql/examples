from sqlalchemy.orm import Mapped, mapped_column
from sqlalchemy.types import UnicodeText

from backend.db import Base


class Book(Base):
    __tablename__ = "book"
    id: Mapped[int] = mapped_column(primary_key=True, autoincrement=True)
    title: Mapped[str]
    author: Mapped[str]
    content: Mapped[str] = mapped_column(UnicodeText)
