#include "SDL2/SDL.h"
#include "src/engine/graphics.h"

int main() {
  engine::Graphics& graphics = engine::Graphics::GetInstance();

  SDL_Event e;
  while (true) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) {
        return 0;
      }
    }

    graphics.Clear();
    graphics.Present();
  }

  return 0;
}
