#include "game/Mandelbrot.hpp"

#include <emmintrin.h>
#include <immintrin.h>

#include <iostream>

#include "util/time.hpp"
#include "util/input.h"

Mandelbrot::Mandelbrot(sf::RenderWindow& window, sf::View& camera)
    : Object(11),
      window_(window),
      camera_(camera),
      kWinWidth_(window.getSize().x),
      kWinHeight_(window.getSize().y),
      kMaxRadius2_M128_(_mm_set1_ps(kMaxRadius2)),
      kMaxRadius2_M256_(_mm256_set1_ps(kMaxRadius2)) {
  // Init mandelbrot set buffer
  set_buffer_ = (sf::Uint32*)calloc(kWinWidth_ * kWinHeight_, sizeof(sf::Uint32));
  true_buff_ = (int*)calloc(kWinHeight_ * kWinWidth_, sizeof(int));

  // Set sprite data
  if (!texture_.create(kWinWidth_, kWinHeight_)) {
    std::cout << "Error: failed create texture\n";
  }
  sprite_.setTexture(texture_);
  sprite_.setTextureRect(sf::IntRect(0, 0, kWinWidth_, kWinHeight_));
  sprite_.setOrigin({0, 0});
}

Mandelbrot::~Mandelbrot() {
  free(set_buffer_);
  free(true_buff_);
}

// ----------------------------------------------------------------------------------
int a = 8, b = 6, c = 7;
inline sf::Color GetColor(int k) {
    return sf::Color((a * k) % 256, (b * k) % 256, (c * k) % 256);
    //return sf::Color((a * k * k) % 256, (b * k) % 256, (c * c * k) % 256);
    //return sf::Color((a * k * k) % 256, (b  * k) % 256, (c * k) % 256);
    //return sf::Color((10 * a * k) % 256, (10 * b * k) % 256, (10 * c * k) % 256);
    //return sf::Color((256 -a * k) % 256, ( b * k) % 256, (256 - c * k) % 256);
}

#define COLOR(k) sf::Color((8 * (k)) % 256, (4 * (k)) % 256, (7 * (k)) % 256)
#define COLOR_COOL(k) 0xff000000 | ((k) << 8) | ((k) << 16) | ((k) << 24);
#define COLOR_COOL64(k) 0xff000000 | ((k >> 32) << 8) | ((k >> 32) << 16) | ((k >> 32) << 24);
//#define COLOR(k) 0xff000000 | (k << 8) | (k << 16) | (k << 24);
// ----------------------------------------------------------------------------------

void Mandelbrot::Update() {
  std::cout << Time::GetDeltaTime() << " " << Time::GetFPS() << "\n";

  if (input::GetKey(input::KeyCode::SPACE)) {
      std::cout << "#color:" << a << " " << b << " " << c << "\n";
      a = rand() % 15;
      b = rand() % 15;
      c = rand() % 15;
  }

  UpdateMandelbrotSSE8();
}

void Mandelbrot::UpdateMandelbrot() {
  for (int wy = 0; wy < kWinHeight_; ++wy) {
    for (int wx = 0; wx < kWinWidth_; ++wx) {
      // Init coords
      sf::Vector2f coords = window_.mapPixelToCoords({wx, wy}, camera_);
      float X = coords.x, Y = coords.y;
      int rate = 0;
      float radius2 = 0;

      // Check point
      for (; rate < kMaxRate && kMaxRadius2 - radius2 > kEPS; ++rate) {
        float X2 = X * X;
        float Y2 = Y * Y;
        float XY = X * Y;
        radius2 = X2 + Y2;

        X = X2 - Y2 + coords.x;
        Y = XY * 2 + coords.y;
      }

      // Update color
      true_buff_[wx + wy * kWinWidth_] = rate;
      set_buffer_[wx + wy * kWinWidth_] = GetColor(rate).toInteger();
    }
  }

  // Update sprite texture
  texture_.update((sf::Uint8*)set_buffer_);
}

void Mandelbrot::UpdateMandelbrotSSE4() {
    float dx = window_.mapPixelToCoords({1, 0}, camera_).x - window_.mapPixelToCoords({0, 0}, camera_).x;
    for (int wy = 0; wy < kWinHeight_; ++wy) {
        for (int wx = 0; wx < kWinWidth_; wx += 4) {
        // Init coords

        sf::Vector2f p1 = window_.mapPixelToCoords({wx, wy}, camera_);

        float X0_[4] = {
            p1.x,
            p1.x + dx,
            p1.x + dx * 2,
            p1.x + dx * 3,
        };

        __m128 X0 = _mm_load_ps(X0_);
        __m128 Y0 = _mm_set1_ps(p1.y);

        __m128 X = X0;
        __m128 Y = Y0;

        __m128i rate = _mm_setzero_si128();
        __m128 radius2 = _mm_setzero_ps();

        // Check point
        for (int i = 0; i < kMaxRate; ++i) {
            __m128 X2 = _mm_mul_ps(X, X);
            __m128 Y2 = _mm_mul_ps(Y, Y);
            radius2 = _mm_add_ps(X2, Y2);

            __m128 cmp = _mm_cmple_ps(radius2, kMaxRadius2_M128_);

            if (!_mm_movemask_ps(cmp)) break;
            rate = _mm_sub_epi32(rate, _mm_castps_si128(cmp));

            __m128 XY = _mm_mul_ps(X, Y);

            X = _mm_add_ps(_mm_sub_ps(X2, Y2), X0);
            Y = _mm_add_ps(_mm_add_ps(XY, XY), Y0);
        }

        int* rate_ = (int*)&rate;
        for (int i = 0; i < 4; ++i) {
            set_buffer_[wx + i + wy * kWinWidth_] = GetColor(rate_[i]).toInteger();
        } 
        }
    }
    texture_.update((sf::Uint8*)set_buffer_);
}

void Mandelbrot::UpdateMandelbrotSSE8() {
    sf::Vector2f p1 = window_.mapPixelToCoords({0, 0}, camera_);
    float x_ = p1.x;
    
    sf::Vector2f d = window_.mapPixelToCoords({1, 1}, camera_) - p1;

    for (int wy = 0; wy < kWinHeight_; wy += 1) {
        for (int wx = 0; wx + 8 < kWinWidth_; wx += 8) {
            // Init coords

            float X0_[8] = {
                p1.x,          p1.x + d.x,     p1.x + d.x * 2, p1.x + d.x * 3,
                p1.x + d.x * 4, p1.x + d.x * 5, p1.x + d.x * 6, p1.x + d.x * 7,
            };
            p1.x += d.x * 8;

            __m256 X0 = _mm256_load_ps(X0_);
            __m256 Y0 = _mm256_set1_ps(p1.y);

            __m256 X = X0;
            __m256 Y = Y0;

            __m256i rate = _mm256_setzero_si256();
            __m256 radius2 = _mm256_setzero_ps();
                
            // Check point
            for (int i = 0; i < kMaxRate; ++i) {
                __m256 X2 = _mm256_mul_ps(X, X);
                __m256 Y2 = _mm256_mul_ps(Y, Y);

                radius2 = _mm256_add_ps(X2, Y2);

                __m256 cmp =_mm256_cmp_ps(radius2, kMaxRadius2_M256_, _CMP_LE_OS);
        
                if (!_mm256_movemask_ps(cmp)) break;

                rate = _mm256_sub_epi32(rate, _mm256_castps_si256(cmp));

                __m256 XY = _mm256_mul_ps(X, Y);

                X = _mm256_add_ps(_mm256_sub_ps(X2, Y2), X0);
                Y = _mm256_add_ps(_mm256_add_ps(XY, XY), Y0);
            }

            // Update color
//#define OPTIMIZE
#ifdef OPTIMIZE
            int64_t* r_ = (int64_t*)&rate;
            for (int i = 0; i < 4; ++i) {
                *(int64_t*)(set_buffer_ + wx + i * 2 + wy * kWinWidth_) = COLOR_COOL64(r_[i]);
            }
#else
            int *rate_ = (int*) &rate;
            for (int i = 0; i < 8; ++i) {
                set_buffer_[wx + i + wy * kWinWidth_] = GetColor(rate_[i]).toInteger();
                //set_buffer_[wx + i + wy * kWinWidth_] = COLOR(rate_[i]);
                //set_buffer_[wx + i + wy * kWinWidth_] = COLOR_COOL(rate_[i]);
            }
#endif
        }

        p1.y += d.y;
        p1.x = x_;  
    }

    texture_.update((sf::Uint8*)set_buffer_);
}
