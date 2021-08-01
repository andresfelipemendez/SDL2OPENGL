#include "platform.h"
#include "renderer.h"

Platform gPlatform;
Renderer gRenderer;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    gPlatform.startUp();
    gRenderer.startUp();

    while (gPlatform.isRunning) 
    {
		gPlatform.runLoop();
        gRenderer.startUp();
    }

	gRenderer.startUp();
    gPlatform.shutDown();
}
