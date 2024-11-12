#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <string>
#include "ui_element.h"
#include "window.h"
#include "state.h"

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

void Window::Open() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return;
    }

    if (TTF_Init() == -1) {
        std::cerr << "Failed to initialize TTF: " << TTF_GetError() << std::endl;
        SDL_Quit();
        return;
    }

    window = SDL_CreateWindow("SDL2 Button Example",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return;
    }

    SDL_SetWindowResizable(window, SDL_TRUE);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }
}
void Window::Close() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
void Window::Render() {
    SDL_RenderPresent(this->renderer);
}
void Window::Draw(UIElement* obj) {
    SDL_RenderPresent(this->renderer);
}
void Window::Write(const char* text, SDL_Color color, SDL_Rect rect) 
{
    TTF_Font* font = TTF_OpenFont("../resources/fonts/UbuntuMono-Regular.ttf", 24);
    if (!font) {
        std::cout << "Failed to load font: " << TTF_GetError() << std::endl;
        return;
    }

    SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);
    SDL_Texture* message = SDL_CreateTextureFromSurface(renderer, surface);
    if (rect.h == 0) rect.h = rect.w / sizeof(text);
    SDL_RenderCopy(renderer, message, NULL, &rect);
}

void Window::DrawStateContents(State* state) {
    for (UIElement obj : state->GetUIElements()) {
        this->Draw(obj);
    }
}