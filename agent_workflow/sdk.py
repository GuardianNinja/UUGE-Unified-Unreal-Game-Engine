from typing import Any

try:
    # Replace this import with the real Microsoft Agent Framework SDK package when available.
    from agent_framework import Agent # pyright: ignore[reportMissingImports, reportUnknownVariableType, reportUnusedImport]
except ImportError:
    class Agent:
        """Fallback Agent base for local execution when the SDK is not installed."""

        def __init__(self, name: str = "Agent"):
            self.name = name

        def execute(self, *args: Any, **kwargs: Any) -> Any:
            raise NotImplementedError(
                "Agent Framework SDK is not installed. Install the SDK or replace this fallback."
            )

    class Workflow:
        """Fallback Workflow base for local execution when the SDK is not installed."""

        def __init__(self, name: str = "Workflow"):
            self.name = name

        def execute(self, *args: Any, **kwargs: Any) -> Any:
            raise NotImplementedError(
                "Agent Framework SDK is not installed. Install the SDK or replace this fallback."
            )
