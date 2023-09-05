import strawberry
from strawberry.type import get_object_definition


@strawberry.interface
class Node:
    _id: strawberry.Private[str]

    @strawberry.field()
    def id(self) -> strawberry.ID:
        td = get_object_definition(self, strict=True)
        return strawberry.ID(f"{td.name}{self._id}")
