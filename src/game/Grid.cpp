#include "Grid.hpp"
#include "util/time.hpp"
#include "util/input.h"

Grid::Grid(int win_width, int win_height, sf::View& camera) : Object(11), kWinWidth_(win_width), kWinHeight_(win_height), camera_(camera) {
    mandelbrot_buffer_ = (sf::Uint32*) calloc(win_width * win_height, sizeof(sf::Uint32));
}

Grid::~Grid() {
    free(mandelbrot_buffer_);
}

void Grid::Update() {
    
}

static void DrawGrid(sf::RenderWindow& window, sf::View& camera) {

}

static void DrawMandelbrot(sf::RenderWindow& window, sf::View& camera) {
    sf::Vector2u win_size = window.getSize();
    
    for (uint64_t wy = 0; wy < win_size.y; ++wy) {
        for (uint64_t wx = 0; wx < win_size.x; ++wx) {

        }
    }
}

#include <iostream>

void Grid::Draw(sf::RenderWindow& window) {
    Object::Draw(window);
    const int kMaxRate = 250;
    const float kMaxRadius2 = 300.f;
    const float kEPS = 0.0001f;

    if (input::GetKeyDown(input::KeyCode::W) 
    ||  input::GetKeyDown(input::KeyCode::S) 
    ||  input::GetKeyDown(input::KeyCode::A) 
    ||  input::GetKeyDown(input::KeyCode::D)) {
        for (uint64_t wy = 0; wy < kWinHeight_; ++wy) {
            for (uint64_t wx = 0; wx < kWinWidth_; ++wx) {
                sf::Vector2f coords = {window.mapPixelToCoords({wx, wy}, camera_)};
                coords.x /= 10;
                coords.y /= 10;
                if (!wx && !wy) {
                    std::cout << coords.x << " " << coords.y << "\n";
                }

                float x = coords.x;
                float y = coords.y;

                int i = 0;
                for (; i < kMaxRate; ++i) {
                    float x2 = x * x;
                    float y2 = y * y;
                    float xy = x * y;

                    float r2 = x2 + y2;
                    if (kMaxRadius2 - r2 <= kEPS) break;

                    x = x2 - y2 + coords.x;
                    y = xy + xy + coords.y;
                }

                if (kMaxRate == i) {
                    mandelbrot_buffer_[wx + wy * kWinWidth_] = sf::Color::Red.toInteger();
                } else {
                    mandelbrot_buffer_[wx + wy * kWinWidth_] = sf::Color::White.toInteger();
                }

                //mandelbrot_buffer_[wx + wy * kWinWidth_] = sf::Color::Red.toInteger();
            }
        }

        redraw_mandelbrot_ = true;
    }

    img_.create(kWinWidth_, kWinHeight_, (sf::Uint8*)mandelbrot_buffer_);
    //img.create(kWinWidth_, kWinHeight_, sf::Color::Green);

    tex_.loadFromImage(img_);

    spr_.setTexture(tex_);
    spr_.setScale({1, 1});
    spr_.setPosition(window.mapPixelToCoords({0,0}));
    //std::cout << window.mapPixelToCoords({0, 0}).x << window.mapPixelToCoords({0, 0}).y << "\n";
    //sprite.setPosition({0, 0});
    window.draw(spr_);

    redraw_mandelbrot_ = false;

    //Object::Draw(window);
}