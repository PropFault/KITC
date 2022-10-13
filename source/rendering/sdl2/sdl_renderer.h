#pragma once

#include "../../libs/rendering/renderer.h"
#include "sdl_resource_registry.h"
class SDLRenderer : public Renderer{
private:
    SDLResourceRegistry &registry;
    SDL_Renderer* renderer;
public:
    SDLRenderer(SDLResourceRegistry &registry, SDL_Renderer *renderer) : registry(registry), renderer(renderer) {}

    void drawTex(uint64_t textureTicket, uint32_t x, uint16_t y, uint16_t w, uint16_t h) override {
        SDL_Rect dest{(int)x, (int)y, (int)w, (int)h};
        SDL_RenderCopy(this->renderer, this->registry.checkout(textureTicket), nullptr, &dest);
    }

    void clear() override {
        SDL_RenderClear(this->renderer);
    }

    void present() override {
        SDL_RenderPresent(this->renderer);
    }
};