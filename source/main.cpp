#include "components/material_component.h"
#include "components/texture_component.h"
#include "GUI/GUI.h"
#include "GUI/UIRenderer.h"
#include "libs/ecs/component_pool.h"
#include "libs/ecs/entity_component_hash_map.h"
#include "libs/ecs/entity_component_map.h"
#include "libs/ecs/system.h"
#include "libs/input/impl/sdl/sdl_input_provider.h"
#include "libs/input/action.h"
#include "libs/input/input.h"
#include "libs/input/input_identifier.h"
#include "libs/input/input_provider.h"
#include "libs/loading/image_loader.h"
#include "libs/loading/loader.h"
#include "libs/loading/resource.h"
#include "libs/math/floating_point.h"
#include "libs/pump/pump.h"
#include "libs/pump/pumper.h"
#include "libs/rendering/display.h"
#include "libs/rendering/renderer.h"
#include "libs/rendering/resource_registry.h"
#include "libs/rendering/scene.h"
#include "libs/tracker/Tracker.h"
#include "rendering/sdl2/sdl_renderer.h"
#include "rendering/sdl2/sdl_resource_registry.h"
#include "systems/QuadRenderSystem.h"
#include "quad.h"
#include <SDL2/SDL.h>
#include "libs/ecs/component_pool_hash_map.h"
#include "components/data_component.h"
#include <filesystem>

class Game{
public:
    int pressed;
    int released;
    void main(){
        SDL_Init(SDL_INIT_EVERYTHING);
        auto window = SDL_CreateWindow("my window", 0, 0, 300, 300, 0);
        auto sdlrenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        auto quad_component_pool = ComponentPoolHashMap<DataComponent<Quad<float>>>();
        auto ticket_component_pool = ComponentPoolHashMap<DataComponent<uint64_t>>();
        auto resource_reg = SDLResourceRegistry(*sdlrenderer);
        auto renderer = SDLRenderer(resource_reg, sdlrenderer);

        auto texture_id = resource_reg.registerTexture(ImageLoader().load(FileResource(std::filesystem::path("/home/biggest/git/KITC/source/file.png"))));
        auto texture_ticket_comp = DataComponent<uint64_t>();
        texture_ticket_comp.setTypeId(123);
        texture_ticket_comp.setData(texture_id);
        auto texture_comp_id = ticket_component_pool.reserve(std::move(texture_ticket_comp));
        renderer.clear();
        renderer.drawTex(texture_id, 0,0, 300, 300);
        renderer.present();
        while(true){
            SDL_Event event;
            SDL_PollEvent(&event);
        }
    }
};
/*
struct Game{
    pressed : i32,
    released : i32
}

impl Game{
    pub fn main(&mut self){
        let sdl_context = sdl2::init().unwrap();
        let video_subsystem = sdl_context.video().unwrap();

        let window = video_subsystem.window("rust-sdl2 demo", 800, 600)
            .position_centered()
            .build()
            .unwrap();

        let mut canvas = window.into_canvas().build().map_err(|e| e.to_string()).unwrap();

        let mut i = 0;
        let mut pumper = SDLInputProvider::new(self, &sdl_context, Game::on_button_pressed, Game::on_button_released);

        let mut quad_pool : ComponentPoolLifeguard<QuadComponent> = ComponentPoolLifeguard::new();
        let mut quad_pool_lock = Arc::new(RwLock::new(quad_pool));

        let mut resource_reg  = Arc::new(RwLock::new(SDLResourceRegistry::new(canvas.texture_creator())));
        let mut renderer = Arc::new(RwLock::new(SDLRenderer::new(canvas, resource_reg.clone())));
        let mut texture_pool: ComponentPoolLifeguard<TextureComponent> = ComponentPoolLifeguard::new();
        let mut texture_pool_lock = Arc::new(RwLock::new(texture_pool));

        let texture_id = {
            let mut reggi = resource_reg.write().unwrap();
            texture_pool_lock.write().unwrap().reserve(TextureComponent::initialize, (&mut FileResource::new(Box::from(Path::new("/home/biggest/Downloads/unnamed.png"))), reggi.deref_mut()))
        };

        let mut quad_render_system = QuadRenderSystem::new(quad_pool_lock.clone(), texture_pool_lock.clone(), renderer.clone());

        while i < 10000000{
            /*pumper.pump();
            let mut rendererLck = renderer.write().unwrap();
            rendererLck.clear();
            let texture_comp = texture_pool.checkout(texture_id);
            if let Some(texture_id) = texture_comp.as_ref().unwrap().texture_ticket{
                rendererLck.draw_tex(texture_id, 255, 255, 100, 100);
                rendererLck.present();
                i+=1;
            }*//*
        }
    }
    pub fn on_button_pressed(&mut self, input: &dyn Input){
        self.pressed += 1;
        println!("{} | TOTAL PRESSES {}", input.to_string(), self.pressed)
    }
    pub fn on_button_released(&mut self, input: &dyn Input){
        self.released += 1;
        println!("{} | TOTAL RELEASES {}", input.to_string(), self.released)
    }
}

fn main() {
    let mut game = Game {pressed: 0, released: 0};
    game.main();
}*/

int main(){
    Game game;
    game.main();
}

