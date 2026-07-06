#include "RenderPipeline.h"

#include <iostream>

void RenderPipeline::BeginFrame()
{
    CurrentFrame.Renderables.clear();
    CulledRenderables.clear();
}

void RenderPipeline::Submit(const Renderable& renderable)
{
    CurrentFrame.Renderables.push_back(renderable);
}

void RenderPipeline::ExecuteFrame()
{
    PrepareStage();
    CullingStage();
    DrawStage();
}

void RenderPipeline::EndFrame()
{
    std::cout << "[RenderPipeline] Frame complete. Draw calls: " << LastDrawCount << "\n";
}

std::size_t RenderPipeline::GetDrawCountLastFrame() const
{
    return LastDrawCount;
}

void RenderPipeline::PrepareStage()
{
    // In a real engine this would build GPU command data and sort batches.
}

void RenderPipeline::CullingStage()
{
    CulledRenderables.clear();
    for (const Renderable& renderable : CurrentFrame.Renderables)
    {
        if (renderable.Visible)
        {
            CulledRenderables.push_back(&renderable);
        }
    }
}

void RenderPipeline::DrawStage()
{
    LastDrawCount = CulledRenderables.size();
}
