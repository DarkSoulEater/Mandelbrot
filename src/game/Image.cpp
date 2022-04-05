#include "game/Image.hpp"
#include "util/input.h"
#include <assert.h>
#include <immintrin.h>
#include <iostream>
#include "util/time.hpp"

Image::Image(const char* file_name) : Object(3) {
    LoadImage(file_name);
    std::chrono::high_resolution_clock::time_point now_time_ = std::chrono::high_resolution_clock::now();
    ImMerge(10, 10, "assets/image/AskhatCat.bmp", 1);
    std::chrono::high_resolution_clock::time_point time = std::chrono::high_resolution_clock::now();
    double delta_time_ = std::chrono::duration<double>(time - now_time_).count();
    std::cout << delta_time_ << "\n";

    ImMerge(10, 10, "assets/image/AskhatCat.bmp", 0);
    time = std::chrono::high_resolution_clock::now();
    delta_time_ = std::chrono::duration<double>(time - now_time_).count();
    std::cout << delta_time_;
    SaveImage("assets/image/new_image.bmp");
}

void Image::Update() {
    static int flag = 0;
    if (flag) {
        std::cout << Time::GetDeltaTime() << "\n";
        --flag;
    }

    if (input::GetKeyDown(input::KeyCode::SPACE)) {
        ImMerge(10, 10, "assets/image/AskhatCat.bmp", 0);
        std::cout << "slow ";
        flag = 3;
    }

    if (input::GetKeyDown(input::KeyCode::ENTER)) {
        ImMerge(10, 10, "assets/image/AskhatCat.bmp", 1);
        std::cout << "fast ";
        flag = 3;
    }
}

void Image::Draw(sf::RenderWindow& win) {
    static sf::Texture* tex = new sf::Texture();
    tex->loadFromImage(img_);
    sf::Sprite sp;
    sp.setTexture(*tex);
    win.draw(sp);
    return;
}

void Image::LoadImage(const char* file_name) {
    img_.loadFromFile(file_name);
}

void Image::SaveImage(const char* file_name) {
    img_.saveToFile(file_name);
}

static const __m128i kM128iZero = _mm_set_epi8 (0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0);
static const __m128i kM128_255 = _mm_cvtepu8_epi16 (_mm_set_epi8 (255,255,255,255, 255,255,255,255, 255,255,255,255, 255,255,255,255));

void Print(int* m, const char* text) {
    std::cout << text << "=[";
    for (int i = 0; i < 4; ++i) {
        std::cout << m[i] << " ";
    } 
    std::cout << "]\n";
}

void Print8(__m128i* m, const char* text) {
    std::cout << text << "=[";
    for (int i = 15; i >= 0; --i) {
        std::cout << (int)((unsigned char*)m)[i] << " ";
    } 
    std::cout << "]\n";
}

void Image::ImMerge(int x, int y, const char* src_file, bool mode) {
    sf::Image src_image;
    src_image.loadFromFile(src_file);

    sf::Vector2u src_img_size = src_image.getSize();
    sf::Vector2u img_size = img_.getSize();
    if (x + src_img_size.x > img_size.x || y + src_img_size.y > img_size.y) {
        printf("Error: unccorect image size or position\n");
        return;
    }

    sf::Uint8* src = (sf::Uint8*) src_image.getPixelsPtr();
    sf::Uint8* dst = (sf::Uint8*) img_.getPixelsPtr();

    assert((size_t)src % 16 == 0);
    assert((size_t)dst % 16 == 0);

    for (int y = 0; y < src_img_size.y; ++y) {
        for (int x = 0; x < src_img_size.x;) {
            if (x + 4 < src_img_size.x && mode) {
                __m128i front  = _mm_loadu_si128((__m128i*) &src[(x + y * src_img_size.x) * 4]);
                __m128i back   = _mm_loadu_si128((__m128i*) &dst[(x + y *     img_size.x) * 4]);

                __m128i front_ = (__m128i)_mm_movehl_ps((__m128)kM128iZero, (__m128)front);
                __m128i back_  = (__m128i)_mm_movehl_ps((__m128)kM128iZero, (__m128)back);

                front = _mm_cvtepu8_epi16(front);
                back  = _mm_cvtepu8_epi16(back);

                front_ = _mm_cvtepu8_epi16(front_);
                back_  = _mm_cvtepu8_epi16(back_);

                static const __m128i move_mask_alpha = _mm_set_epi8(255, 14, 255, 14, 255, 14, 255, 14, 255, 6, 255, 6, 255, 6, 255, 6);

                __m128i a  = _mm_shuffle_epi8(front, move_mask_alpha);
                __m128i a_ = _mm_shuffle_epi8(front_, move_mask_alpha);

                front  = _mm_mullo_epi16(front, a);
                front_ = _mm_mullo_epi16(front_, a_);

                back = _mm_mullo_epi16(back,  _mm_sub_epi8(kM128_255, a));
                back_= _mm_mullo_epi16(back_, _mm_sub_epi8(kM128_255, a_));

                __m128i sum  = _mm_adds_epu16(front, back);
                __m128i sum_ = _mm_adds_epu16(front_, back_);

                static const __m128i move_mask_sum = _mm_set_epi8(255, 255, 255, 255, 255, 255, 255, 255, 15, 13, 11, 9, 7, 5, 3, 1);

                sum  = _mm_shuffle_epi8(sum, move_mask_sum);
                sum_ = _mm_shuffle_epi8(sum_, move_mask_sum);

                __m128i color = (__m128i) _mm_movelh_ps((__m128)sum, (__m128)sum_);
                _mm_store_si128((__m128i*) &dst[(x + y * img_size.x) * 4], color);

                x += 4;
            } else {
                sf::Uint8 a = src[x * 4 + 3 + y * src_img_size.x * 4];
                for (int i = 0; i < 3; ++i) {
                    dst[i + x * 4 + y * img_size.x * 4] = (dst[i + x * 4 + y * img_size.x * 4] * (255 - a) + src[i + x * 4 + y * src_img_size.x * 4] * a) >> 8;
                }
                ++x;
            }
        }
    }
}
