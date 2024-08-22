#include "application.h"
#include "sparseset.hpp"

int main()
{

    Application app("Application", 800, 600);
    app.setFramerate(100);
    app.loop();

    return 0;
}
