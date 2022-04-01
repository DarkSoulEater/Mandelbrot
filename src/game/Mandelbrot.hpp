#ifndef _MANDELBROT_GAME_MANDELBROT_HPP_
#define _MANDELBROT_GAME_MANDELBROT_HPP_

#include <SFML/Graphics.hpp>
#include <immintrin.h>
#include <emmintrin.h>
#include "core/Object.h"

class Mandelbrot : public Object {
public:
    Mandelbrot(sf::RenderWindow& window, sf::View& camera);
    ~Mandelbrot();

    virtual void Update() override;

    //virtual void Draw(sf::RenderWindow& window) override;

private:
    const int kWinWidth_;
    const int kWinHeight_;

    sf::RenderWindow& window_;
    sf::View& camera_;

    sf::Uint32* set_buffer_;
    int* true_buff_;

    sf::Image img_;
    sf::Texture texture_;

    const int kMaxRate = 250;
    const float kMaxRadius2 = 100.f;
    const float kEPS = 0.000001f;

    const __m128 kMaxRadius2_M128_;
    const __m256 kMaxRadius2_M256_;

    void UpdateMandelbrot();
    void UpdateMandelbrotSSE4();
    void UpdateMandelbrotSSE8();
};


#endif // _MANDELBROT_GAME_MANDELBROT_HPP_