#pragma once
#include <SDL2/SDL.h>
#include "../../libs/rendering/resource_registry.h"
#include <unordered_map>
#include "../../libs/math/random.h"

class SDLResourceRegistry : ResourceRegistry{
private:
    SDL_Renderer &renderer;
    std::unordered_map<uint64_t, SDL_Texture*> textures;
    Random random;
public:
    explicit SDLResourceRegistry(SDL_Renderer &renderer) : renderer(renderer) {}

    uint64_t registerTexture(const ImageRaw &image) override {
        auto ticket = random.u64();
        ImageRaw imageCopy(image);
        auto surface = SDL_CreateRGBSurfaceWithFormatFrom(imageCopy.data.data(), image.width, image.height, 8, image.pitch, (image.format == RGB ? SDL_PIXELFORMAT_RGB888 : SDL_PIXELFORMAT_RGBA8888));
        this->textures.emplace(ticket, SDL_CreateTextureFromSurface(&renderer, surface));
        SDL_FreeSurface(surface);
        return ticket;
    }

    SDL_Texture* checkout(uint64_t ticket){
        return this->textures.at(ticket);
    }

    ~SDLResourceRegistry(){
        for(auto& elem : this->textures){
            SDL_DestroyTexture(elem.second);
        }
    }
};