#include "application.h"

int main()
{

    Application app("Application", 800, 600);
    app.setFramerate(100);
    app.loop();

    return 0;
}
