from __future__ import annotations

from .sdk import Workflow
from .agents import WriterAgent, ReviewerAgent


class WriterReviewerWorkflow(Workflow):
    def __init__(self) -> None:
        super().__init__(name="WriterReviewerWorkflow")
        self.writer = WriterAgent()
        self.reviewer = ReviewerAgent()

    def execute(self, user_request: str) -> str:
        draft = self.writer.create_content(user_request)
        feedback = self.reviewer.provide_feedback(draft)
        refined = self.writer.revise_content(draft, feedback)

        return (
            "Refined Content After Writer-Reviewer Collaboration:\n\n"
            f"{refined}"
        )
