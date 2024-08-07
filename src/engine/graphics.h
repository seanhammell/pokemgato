#ifndef SRC_ENGINE_GRAPHICS_H_
#define SRC_ENGINE_GRAPHICS_H_

#include "SDL2/SDL.h"
#include "src/engine/texture.h"

namespace engine {

class Graphics {
 public:
  static constexpr int kWindowWidth = 720;
  static constexpr int kWindowHeight = 480;

  static constexpr int kRendererLogicalWidth = 240;
  static constexpr int kRendererLogicalHeight = 160;

  static Graphics &GetInstance();

  Graphics(const Graphics &) = delete;
  Graphics operator=(const Graphics &) = delete;

  ~Graphics();

  SDL_Texture *CreateTextureFromSurface(SDL_Surface *surface);
  void RenderTexture(const Texture &texture, const int x, const int y);

  void Clear();
  void Present();

 private:
  Graphics();

  bool Init();
  void Destroy();

  SDL_Window *window_;
  SDL_Renderer *renderer_;
};

}  // namespace engine

#endif  // SRC_ENGINE_GRAPHICS_H_
