#include "application.h"

void windowErrorCallback(int code, const char *description);

int main()
{

    Window ctx;

    ctx.open(800, 600, "Application");
    ctx.setErrorCallback(windowErrorCallback);

    Application app(std::make_shared<Window>(ctx));

    app.loop();

    return 0;
}

void windowErrorCallback(int code, const char *description)
{
    std::cout << "Error " << code << " : " << description << std::endl;
}
