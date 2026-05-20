// Core/Application/UApplication.h
#pragma once

class UApplication
{
public:
    UApplication();
    virtual ~UApplication();

    int Run();

protected:
    virtual bool Init();
    virtual void Shutdown();
    virtual void Tick(float deltaTime);

private:
    bool bIsRunning;
};
