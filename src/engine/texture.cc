#include "src/engine/texture.h"

#include <stdio.h>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "src/engine/graphics.h"

namespace engine {

Texture::Texture(const char *image_path)
    : texture_(nullptr), width_(0), height_(0) {
  SDL_Surface *image = IMG_Load(image_path);
  if (!Init(image)) {
    Destroy();
  }
}

Texture::~Texture() { Destroy(); }

SDL_Texture *Texture::GetTexture() const { return texture_; }

int Texture::GetWidth() const { return width_; }

int Texture::GetHeight() const { return height_; }

bool Texture::Init(SDL_Surface *surface) {
  if (!surface) {
    fprintf(stderr, "Error creating surface: %s\n", IMG_GetError());
    return false;
  }

  texture_ = Graphics::GetInstance().CreateTextureFromSurface(surface);
  width_ = surface->w;
  height_ = surface->h;

  SDL_FreeSurface(surface);
  if (!texture_) {
    fprintf(stderr, "Error creating texture: %s\n", SDL_GetError());
    return false;
  }

  return true;
}

void Texture::Destroy() {
  if (texture_) {
    SDL_DestroyTexture(texture_);
    texture_ = nullptr;
  }

  width_ = 0;
  height_ = 0;
}

}  // namespace engine
