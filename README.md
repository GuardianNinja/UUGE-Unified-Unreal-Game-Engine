# Writer-Reviewer Content Collaboration Workflow

This project contains a multi-agent workflow application built around a Writer and Reviewer collaboration pattern.

## What it does

- `WriterAgent` receives a user prompt and generates initial content.
- `ReviewerAgent` evaluates the draft and gives concise, actionable feedback.
- `WriterReviewerWorkflow` combines both agents and produces refined plain text output.

## Files

- `app.py` - FastAPI app exposing the workflow via `/collaborate`.
- `agent_workflow/agents.py` - Writer and Reviewer agent implementations.
- `agent_workflow/workflow.py` - Workflow orchestration logic.
- `agent_workflow/sdk.py` - Agent Framework SDK integration point with a fallback stub.
- `requirements.txt` - Runtime dependencies.
- `.env.template` - Environment configuration template.

## Setup

1. Create and activate a Python environment.
2. Install dependencies:

   ```bash
   /usr/bin/python3 -m pip install -r requirements.txt
   ```

3. Copy `.env.template` to `.env` and customize if desired.

## Run locally

```bash
/usr/bin/python3 app.py
```

Then POST to `http://127.0.0.1:8000/collaborate`.

Example request body:

```json
{
  "prompt": "Write a launch announcement for a new productivity app."
}
```

## Notes

- The current implementation includes a local SDK fallback in `agent_workflow/sdk.py`.
- Replace the fallback import with the real Microsoft Agent Framework SDK package once it is available.
