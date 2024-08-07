#include "SDL2/SDL.h"
#include "src/engine/graphics.h"
#include "src/engine/texture.h"

int main() {
  engine::Graphics& graphics = engine::Graphics::GetInstance();

  engine::Texture title("../title_background.png");

  SDL_Event e;
  while (true) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) {
        return 0;
      }
    }

    graphics.Clear();
    graphics.RenderTexture(title, 0, 0);
    graphics.Present();
  }

  return 0;
}
