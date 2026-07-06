#pragma once

#include "RenderTypes.h"

#include <cstddef>
#include <vector>

class RenderPipeline
{
public:
    void BeginFrame();
    void Submit(const Renderable& renderable);
    void ExecuteFrame();
    void EndFrame();

    std::size_t GetDrawCountLastFrame() const;

private:
    void PrepareStage();
    void CullingStage();
    void DrawStage();

private:
    RenderFrame CurrentFrame{};
    std::vector<const Renderable*> CulledRenderables{};
    std::size_t LastDrawCount = 0;
};
