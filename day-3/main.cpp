#include "SDL.h"
#include "color.h"
#include <iostream>

SDL_Window *window;

int main(int argc, char* argv[]) {

	Color red("#FF0000");
	red.print_color();
	Color blue("#0000FF");
	blue.print_color();
	Color blended_color;
	blended_color = red + blue;
	blended_color.print_color();
	//Color new_color = red.blend(blue);
	Color darken_new_color = red.blend(blue);
	//new_color.print_color();
	darken_new_color.darken(0.3);
	darken_new_color.print_color();
	Color lighten_new_color = red.blend(blue);
	lighten_new_color.lighten(0.3);
	lighten_new_color.print_color();
/*	Color my_color(88, 20, 200);
	++my_color;
	my_color.print_color();

	Color my_color2(88, 20, 200);
	my_color2--;
	my_color2.print_color();
	*/

	SDL_Window* window;
	SDL_Renderer* renderer;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return 1;
	}
	window = SDL_CreateWindow("Colors", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 200, 200, 0);
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, *red.get_red(), *red.get_green(), *red.get_blue(), 0);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(3000);
	SDL_SetRenderDrawColor(renderer, *blue.get_red(), *blue.get_green(), *blue.get_blue(), 0);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(3000);
	SDL_SetRenderDrawColor(renderer, *blended_color.get_red(), *blended_color.get_green(), *blended_color.get_blue(), 0);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(3000);
	SDL_SetRenderDrawColor(renderer, *darken_new_color.get_red(), *darken_new_color.get_green(), *darken_new_color.get_blue(), 0);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(3000);
	SDL_SetRenderDrawColor(renderer, *lighten_new_color.get_red(), *lighten_new_color.get_green(), *lighten_new_color.get_blue(), 0);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(3000);
	SDL_Quit();
	return 0;
}