#include "SDL2/SDL.h"
#include "src/engine/graphics.h"

int main() {
  engine::Graphics kGraphics;

  SDL_Event e;
  while (true) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) {
        return 0;
      }
    }

    SDL_SetRenderDrawColor(kGraphics.renderer_, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderClear(kGraphics.renderer_);
    SDL_RenderPresent(kGraphics.renderer_);
  }

  return 0;
}
