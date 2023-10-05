
#include "OpenGLMain.h"

int main()
{
    if (!pop::ogl::Init()) return -1;

    while (!pop::ogl::ToClose())
    {
        pop::ogl::Update();
    }
    pop::ogl::Clear();
    return 0;
}
