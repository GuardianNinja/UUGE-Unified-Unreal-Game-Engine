// main.cpp (Engine launcher)
#include "Core/Application/UApplication.h"

class UUGEGameApp : public UApplication
{
protected:
    bool Init() override
    {
        if (!UApplication::Init())
            return false;

        // TODO: Create world, spawn initial actors
        return true;
    }

    void Tick(float deltaTime) override
    {
        // TODO: Update world, render
        UApplication::Tick(deltaTime);
    }
};

int main()
{
    UUGEGameApp app;
    return app.Run();
}
