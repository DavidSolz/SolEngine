#include "window.h"
#include "scenemanager.h"

void windowErrorCallback(int code, const char *description);

int main()
{

    Window ctx;

    ctx.open(800, 600, "Application");
    ctx.setErrorCallback(windowErrorCallback);

    while (!ctx.shouldClose())
    {
        ctx.updateFramebufferSize();
        ctx.update();
        ctx.clearBuffers();
    }

    return 0;
}

void windowErrorCallback(int code, const char *description)
{
    std::cout << "Error " << code << " : " << description << std::endl;
}
