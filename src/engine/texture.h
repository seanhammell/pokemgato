#ifndef SRC_ENGINE_TEXTURE_H_
#define SRC_ENGINE_TEXTURE_H_

#include "SDL2/SDL.h"

namespace engine {

class Texture {
 public:
  explicit Texture(const char *image_path);

  Texture(const Texture &) = delete;
  Texture operator=(const Texture &) = delete;

  ~Texture();

  SDL_Texture *GetTexture() const;
  int GetWidth() const;
  int GetHeight() const;

 private:
  bool Init(SDL_Surface *surface);
  void Destroy();

  SDL_Texture *texture_;
  int width_;
  int height_;
};

}  // namespace engine

#endif  // SRC_ENGINE_TEXTURE_H_
