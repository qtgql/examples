from pathlib import Path

import requests
from graphql import build_client_schema, get_introspection_query, print_schema

res = requests.post(
    "https://countries.trevorblades.com/",
    json={"query": get_introspection_query()},
)
res.raise_for_status()
d = res.json()["data"]

client_schema = build_client_schema(d)
schema_file = Path(__file__).parent / "schema.graphql"
schema_file.resolve(True).write_text(print_schema(client_schema))
