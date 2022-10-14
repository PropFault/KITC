#pragma once
#include "loader.h"
#include <iostream>
#include <stb_image.h>
enum PixelFormat{
    RGB,
    RGBA
};

struct ImageRaw{
    std::vector<uint8_t> data;
    uint32_t width;
    uint32_t height;
    uint32_t pitch;
    PixelFormat format;
};

class ImageLoader : Loader<ImageRaw>{
public:
    ImageRaw load(Resource&& resource)override{
        auto handle = resource.read();
        std::vector<char> data((std::istreambuf_iterator<char>(*handle)), std::istreambuf_iterator<char>());
        int width;
        int height;
        int channels;
        auto res = stbi_load_from_memory((unsigned char*)data.data(), data.size(), &width, &height, &channels, 0);
        auto error = stbi_failure_reason();
        if(res == nullptr){
            throw std::runtime_error(std::string ("FAILED TO LOAD IMAGE: ") + error);
        }
        if(error != nullptr)
            std::cout<<error<<std::endl;
        return ImageRaw{
                .data = std::vector<uint8_t>(res,res+(width*height*channels)),
                .width = (uint32_t)width,
                .height = (uint32_t)height,
                .pitch = (uint32_t)width*channels,
                .format = (channels > 3? RGBA : RGB)};
    }
};
/*
impl Loader<ImageRaw> for ImageLoader{
    fn load(&mut self, resource: &dyn Resource) -> ImageRaw {
        let mut raw = Vec::new();
        resource.read().read_to_end(&mut raw).map_err(|e| e.to_string()).unwrap();
        println!("{}", raw.len());
        let cursor = Cursor::new(raw);
        let data = ImageReader::new(cursor).with_guessed_format().unwrap().decode().unwrap();
        let color = match data.color(){
            ColorType::Rgb8 | ColorType::Rgb16 => {
                PixelFormat::RGB
            }
            ColorType::Rgba8 | ColorType::Rgba16 => {
                PixelFormat::RGBA
            }
            _ => {PixelFormat::RGB}
        };
        println!("returning raw image BYTES: {}",data.color().bytes_per_pixel());
        return ImageRaw{
            data: Box::from(data.as_bytes()),
            width: data.width(),
            height: data.height(),
            pitch: data.width() * u32::from(data.color().bytes_per_pixel()),
            format: color
        }
    }
}
impl ImageLoader{
    pub fn new() -> ImageLoader{
        ImageLoader{}
    }
}*/