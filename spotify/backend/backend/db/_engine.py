from sqlalchemy.ext.asyncio import async_sessionmaker, create_async_engine

from backend.settings import DatabaseSettings, get_settings

_settings = get_settings(DatabaseSettings)

engine = create_async_engine(
    _settings.DATABASE_URL,
    echo=_settings.ECHO,
)
async_session_factory = async_sessionmaker(bind=engine)
