import strawberry
from strawberry.type import get_object_definition


@strawberry.interface
class Node:
    _id: strawberry.Private[str]

    @strawberry.field()
    def id(self) -> strawberry.ID:
        td = get_object_definition(self.__class__, strict=True)
        return strawberry.ID(f"{td.name}{self._id}")

    @classmethod
    def get_raw_id(cls, id: str) -> int:
        td = get_object_definition(cls, strict=True)
        return int(id.strip(td.name))
