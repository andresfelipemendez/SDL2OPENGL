#include "platform.h"
#include "renderer.h"
#include "types/scene.h"

Platform gPlatform;
Renderer gRenderer;

scene gScene;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    gPlatform.startUp();
    gRenderer.startUp();

    gScene.open("scene1.db");

    while (gPlatform.isRunning) 
    {
		gPlatform.runLoop();
        gRenderer.startUp();
    }

	gRenderer.startUp();
    gPlatform.shutDown();
}
