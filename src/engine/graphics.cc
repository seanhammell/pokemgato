#include "src/engine/graphics.h"

#include <assert.h>
#include <stdio.h>

#include "SDL2/SDL.h"

namespace engine {

bool Graphics::kInstantiated = false;

Graphics::Graphics() : window_(nullptr), renderer_(nullptr) {
  assert(!kInstantiated);
  kInstantiated = Init();
  if (!kInstantiated) {
    Destroy();
  }
}

Graphics::~Graphics() { Destroy(); }

bool Graphics::Init() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
    return false;
  }

  SDL_Rect monitor;
  SDL_GetDisplayBounds(SDL_GetNumVideoDisplays() - 1, &monitor);
  monitor.x += (monitor.w - kWindowWidth) / 2;
  monitor.y += (monitor.h - kWindowHeight) / 2;
  window_ = SDL_CreateWindow("Pokémon MGato", monitor.x, monitor.y,
                             kWindowWidth, kWindowHeight, SDL_WINDOW_SHOWN);
  if (!window_) {
    fprintf(stderr, "Error creating window: %s\n", SDL_GetError());
    return false;
  }

  renderer_ = SDL_CreateRenderer(
      window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!renderer_) {
    fprintf(stderr, "Error creating renderer: %s\n", SDL_GetError());
    return false;
  }

  if (SDL_RenderSetLogicalSize(renderer_, kRendererLogicalWidth,
                               kRendererLogicalHeight) != 0) {
    fprintf(stderr, "Error setting logical renderer dimensions: %s\n",
            SDL_GetError());
    return false;
  }

  return true;
}

void Graphics::Destroy() {
  SDL_DestroyRenderer(renderer_);
  SDL_DestroyWindow(window_);
  SDL_Quit();

  renderer_ = nullptr;
  window_ = nullptr;
  kInstantiated = false;
}

}  // namespace engine
