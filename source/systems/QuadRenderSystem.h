#pragma once
/*use stb::cell::RefCell;
use stb::sync::{Arc, RwLock};
use crate::{Renderer, TextureComponent};
use crate::components::quad_component::QuadComponent;
use crate::libs::ecs::component_pool::{Component, ReadableComponentPool};
use crate::libs::ecs::system::System;

pub struct QuadRenderSystem{
    quad_pool : Arc<RwLock<dyn ReadableComponentPool<QuadComponent>>>,
    tex_pool : Arc<RwLock<dyn ReadableComponentPool<TextureComponent>>>,
    renderer: Arc<RwLock<dyn Renderer>>
}

impl System for QuadRenderSystem{
    fn think(&mut self, entity_ticket: u64, component_ticket: u64, delta: f64) {
        let mut quad_pool_lock = self.quad_pool.write().unwrap();
        let mut texture_pool_lock = self.tex_pool.write().unwrap();
        match quad_pool_lock.checkout(component_ticket) {
            Some(qc) =>
                match texture_pool_lock.checkout(qc.material) {
                    Some(mat) =>
                        match &qc.quad {
                            Some(quad) =>
                                match mat.texture_ticket {
                                    Some(ticket)=>
                                        self.renderer.write().unwrap().draw_tex(ticket, quad.get_x() as i32, quad.get_y() as i32, quad.get_width() as u32, quad.get_height() as u32),
                                    None => {}
                                }
                            None => {}
                        },
                    None => {}
                }
            ,
            None => {}
        }
    }

    fn get_handled_type(&self) -> u64 {
        return QuadComponent::get_type_id();
    }
}

impl QuadRenderSystem{
    pub fn new(quad_pool: Arc<RwLock<dyn ReadableComponentPool<QuadComponent>>>, tex_pool: Arc<RwLock<dyn ReadableComponentPool<TextureComponent>>>, renderer:  Arc<RwLock<dyn Renderer>>) -> Self {
        Self { quad_pool, tex_pool, renderer }
    }
}*/