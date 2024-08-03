#include "src/engine/graphics.h"

#include <stdio.h>

#include "SDL2/SDL.h"

namespace engine {

Graphics& Graphics::GetInstance() {
  static Graphics kInstance;
  return kInstance;
}

Graphics::~Graphics() { Destroy(); }

SDL_Texture *Graphics::CreateTextureFromSurface(SDL_Surface *surface) {
  return SDL_CreateTextureFromSurface(renderer_, surface);
}

void Graphics::Clear() {
  SDL_SetRenderDrawColor(renderer_, 0x00, 0x00, 0x00, 0xFF);
  SDL_RenderClear(renderer_);
}

void Graphics::Present() { SDL_RenderPresent(renderer_); }

Graphics::Graphics() : window_(nullptr), renderer_(nullptr) {
  if (!Init()) {
    Destroy();
  }
}

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
  if (renderer_) {
    SDL_DestroyRenderer(renderer_);
    renderer_ = nullptr;
  }

  if (window_) {
    SDL_DestroyWindow(window_);
    window_ = nullptr;
  }

  SDL_Quit();
}

}  // namespace engine
