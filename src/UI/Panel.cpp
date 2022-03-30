#include "Panel.h"
#include "../util/asset.h"

Panel::Panel() : sprite_(asset::LoadTexture("../assets/texture/panel.png")) {

}

void Panel::Draw(sf::RenderWindow &window) {
  window.draw(sprite_);
}
