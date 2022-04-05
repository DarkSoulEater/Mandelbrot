#ifndef _MANDELBTOT_GAME_IMAGE_HPP_
#define _MANDELBTOT_GAME_IMAGE_HPP_

#include "core/Object.h"

class Image : public Object {
public:
    Image(const char* file_name);

    void Update() override;
    void Draw(sf::RenderWindow& win) override;

    void LoadImage(const char* file_name);
    void SaveImage(const char* file_name);

    void ImMerge(int x, int y, const char* src_file, bool mode);
private:
    sf::Image img_;
};

#endif // _MANDELBTOT_GAME_IMAGE_HPP_