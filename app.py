import os
from pathlib import Path

from dotenv import load_dotenv
from fastapi import FastAPI
from pydantic import BaseModel

from agent_workflow.workflow import WriterReviewerWorkflow

BASE_DIR = Path(__file__).resolve().parent
load_dotenv(BASE_DIR / ".env")

APP_HOST = os.getenv("APP_HOST", "127.0.0.1")
APP_PORT = int(os.getenv("APP_PORT", "8000"))

app = FastAPI(
    title="Writer-Reviewer Content Collaboration",
    description="A multi-agent workflow where a Writer and Reviewer collaborate to refine content.",
    version="0.1.0",
)
workflow = WriterReviewerWorkflow()


class CollaborateRequest(BaseModel):
    prompt: str


class CollaborateResponse(BaseModel):
    output: str


@app.post("/collaborate", response_model=CollaborateResponse)
def collaborate(request: CollaborateRequest) -> CollaborateResponse:
    output = workflow.execute(request.prompt)
    return CollaborateResponse(output=output)


def main() -> None:
    import uvicorn

    uvicorn.run(
        "app:app",
        host=APP_HOST,
        port=APP_PORT,
        reload=True,
    )


if __name__ == "__main__":
    main()
