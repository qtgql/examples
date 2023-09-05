from datetime import datetime

from sqlalchemy import DateTime, MetaData
from sqlalchemy.ext.asyncio import async_sessionmaker, create_async_engine
from sqlalchemy.orm import DeclarativeBase, registry

from .settings import DatabaseSettings, get_settings

meta = MetaData(
    naming_convention={
        "ix": "ix_%(column_0_label)s",
        "uq": "uq_%(table_name)s_%(column_0_name)s",
        "ck": "ck_%(table_name)s_%(constraint_name)s",
        "fk": "fk_%(table_name)s_%(column_0_name)s_%(referred_table_name)s",
        "pk": "pk_%(table_name)s",
    },
)


class BaseTable(DeclarativeBase):
    metadata = meta

    registry = registry(
        type_annotation_map={
            datetime: DateTime(timezone=True),
        },
    )


_settings = get_settings(DatabaseSettings)

engine = create_async_engine(
    _settings.DATABASE_URL,
    echo=_settings.ECHO,
)
async_session_factory = async_sessionmaker(bind=engine)
