#pragma once

#include <SDL.h>
#include <SDL_opengl.h>
#include <iostream>

class Platform
{
public:
	SDL_Window* window;

	bool keep_window_open = true;

	void startUp() {
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			std::cout << "Failed to initialize the SDL2 library\n";
		//	return -1;
		}

		window = SDL_CreateWindow("SDL2 Window",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			680, 480,
			0);

		if (!window)
		{
			std::cout << "Failed to create window\n";
		//	return -1;
		}

		SDL_Surface* window_surface = SDL_GetWindowSurface(window);

		if (!window_surface)
		{
			std::cout << "Failed to get the surface from the window\n";
		//	return -1;
		}

		SDL_UpdateWindowSurface(window);

		
	}

	void runLoop() {
		
		while (keep_window_open)
		{
			SDL_Event e;
			while (SDL_PollEvent(&e) > 0)
			{
				switch (e.type)
				{
				case SDL_QUIT:
					keep_window_open = false;
					break;
				}
				SDL_UpdateWindowSurface(window);
			}
		}
	}

	void shutDown() {
		SDL_DestroyWindow(window);

		// Clean up
		SDL_Quit();
	}
};

