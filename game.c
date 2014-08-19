#include "game.h"

int quit = 0;

void gameLoop() {
	SDL_Event e;

	while (quit == 0) {
		while (SDL_PollEvent(&e) != 0) {
			switch (e.type) {
			case SDL_QUIT:
				eventQuit();
				quit = 1;
				break;
			case SDL_KEYDOWN:
				eventKeyDown(e.key.keysym.sym);
				break;
			case SDL_KEYUP:
				eventKeyUp(e.key.keysym.sym);
				break;
			}
		}

		eventDraw();
	}
}

void quitGame() {
	quit = 1;
}

SDL_Surface* loadBMP(const char *path) {
	return SDL_LoadBMP(path);
}
