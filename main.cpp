// SDL2OPENGL.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Resource.h"

#include <GL/gl.h>
#include <stdio.h>
#include "platform.h"
#include "renderer.h"

#define MAX_LOADSTRING 100



Platform gPlatform;
Renderer gRenderer;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    gPlatform.startUp();

    /// run

    while (gPlatform.isRunning) {
		gPlatform.runLoop();

    }

    /// shutdown
    
    gPlatform.shutDown();


}
