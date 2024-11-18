#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <memory>
#include "ui_elements/ui_element.h"
#include "window.h"
#include "states/state.h"

const int INIT_WINDOW_WIDTH = 640;
const int INIT_WINDOW_HEIGHT = 480;

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

    window = SDL_CreateWindow("FreePitch",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        INIT_WINDOW_WIDTH, INIT_WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
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

void Window::GetSize(int* w, int* h) {
    SDL_GetWindowSize(window, w, h);
}

void Window::DrawStateContents(State& state) {
    SDL_RenderClear(this->renderer);
    for (UIElement* obj : state.GetUIElements()) {
        obj->Draw(this->renderer);
    }
}