#ifndef _MANDELBROT_APP_GRID_HPP_
#define _MANDELBROT_APP_GRID_HPP_

#include "core/Object.h"

class Grid : public Object {
public:
    Grid(int win_width, int win_height, sf::View& camera);
    ~Grid();

    virtual void Update() override;

    virtual void Draw(sf::RenderWindow& window) override;

private:
    const int kWinWidth_;
    const int kWinHeight_;

    sf::View& camera_;

    bool redraw_mandelbrot_ = true;
    sf::Uint32* mandelbrot_buffer_;

    sf::Image img_;
    sf::Texture tex_;
    sf::Sprite spr_;

    void UpdateMandelbrot();
    void UpdateMandelbrotSSE();
};


#endif // _MANDELBROT_APP_GRID_HPP_