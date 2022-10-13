#pragma once
#include <cinttypes>
class Renderer{
public:
    virtual void drawTex(uint64_t textureTicket, uint32_t x, uint16_t y, uint16_t w, uint16_t h)=0;
    virtual void clear()=0;
    virtual void present()=0;
};

/*
class Renderer{
    virtual void drawTex()
};
pub trait Renderer{
    fn draw_tex(&mut self, texture_ticket : u64, x : i32, y : i32, w : u32, h: u32);
    fn clear(&mut self);
    fn present(&mut self);
}*/