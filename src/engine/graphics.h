#ifndef SRC_ENGINE_GRAPHICS_H_
#define SRC_ENGINE_GRAPHICS_H_

#include "SDL2/SDL.h"

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

  SDL_Window *window_;
  SDL_Renderer *renderer_;

 private:
  Graphics();

  bool Init();
  void Destroy();
};

}  // namespace engine

#endif  // SRC_ENGINE_GRAPHICS_H_
