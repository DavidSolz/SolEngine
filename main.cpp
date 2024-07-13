#include "window.h"
#include "texture2d.h"
#include "framebuffer.h"
#include "scenemanager.h"

void windowErrorCallback(int code, const char * description);

int main(){

    Window ctx;

    ctx.open(800, 600, "Application");
    ctx.setErrorCallback(windowErrorCallback);

    Scene scene;

    Mesh mesh = Mesh::genQuad(1, 1);
    scene.addMesh(mesh);

    Entity e;
    scene.addEntity(e);

    SceneManager manager(scene);

    while ( !ctx.shouldClose() ) {

        ctx.updateFramebufferSize();
        ctx.update();
        ctx.clearBuffers();

        manager.render();

        float time = glfwGetTime();

        e.transform.setLocalPosition(Vector3(cos(time), sin(time), 0.0f));
        e.transform.setLocalScale(Vector3(0.5f, 0.5f, 0.5f));
    }

    return 0;
}

void windowErrorCallback(int code, const char * description){
    std::cout << "Error " << code << " : " << description << std::endl;
}
