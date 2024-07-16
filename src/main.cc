#include "SDL2/SDL.h"
#include "src/engine/graphics.h"

int main() {
  SDL_Event e;
  while (true) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) {
        return 0;
      }
    }

    SDL_SetRenderDrawColor(engine::Graphics::GetInstance().renderer_, 0x00,
                           0x00, 0x00, 0xFF);
    SDL_RenderClear(engine::Graphics::GetInstance().renderer_);
    SDL_RenderPresent(engine::Graphics::GetInstance().renderer_);
  }

  return 0;
}
