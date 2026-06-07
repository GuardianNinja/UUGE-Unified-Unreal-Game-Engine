from __future__ import annotations

from .sdk import Agent # pyright: ignore[reportUnknownVariableType, reportAttributeAccessIssue]


class WriterAgent(Agent): # pyright: ignore[reportUntypedBaseClass]
    def __init__(self) -> None:
        super().__init__(name="Writer") # pyright: ignore[reportUnknownMemberType]

    def create_content(self, user_request: str) -> str:
        prompt = user_request.strip()
        if not prompt:
            prompt = "Write a polished summary for a new product launch."

        return (
            f"{prompt.capitalize()}\n\n"
            "This first draft is structured to deliver an engaging and clear response to the user's request."
        )

    def revise_content(self, draft: str, feedback: str) -> str:
        revised = [line.strip() for line in draft.splitlines() if line.strip()]
        review_lines = [line.strip() for line in feedback.splitlines() if line.strip()]

        if review_lines:
            revised.append("\nRevised to incorporate reviewer suggestions:")
            revised.extend(review_lines)

        return "\n".join(revised)


class ReviewerAgent(Agent): # pyright: ignore[reportUntypedBaseClass]
    def __init__(self) -> None:
        super().__init__(name="Reviewer") # pyright: ignore[reportUnknownMemberType]

    def provide_feedback(self, draft: str) -> str:
        if not draft.strip():
            return "The draft is empty. Please provide a clear request and a first draft."

        return (
            "Reviewer Feedback:\n"
            "- Keep the structure focused on the core message.\n"
            "- Use more concrete examples when possible.\n"
            "- Tighten wording to improve readability and flow.\n"
            "- Confirm that the tone matches the requested audience."
        )
