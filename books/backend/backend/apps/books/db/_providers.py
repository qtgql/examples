import aioinject

from backend.apps.books.db.service import BookService

providers = [
    aioinject.Callable(BookService),
]
