#ifndef TAURMAZE_ASSET_H
#define TAURMAZE_ASSET_H

#include <SFML/Graphics.hpp>

namespace asset {
sf::Texture& LoadTexture(const char* path);

  namespace path {
    extern const char* t_StoneCellTiles;

    extern const char* t_OnWayCell;

    extern const char* t_Minotaur;
  }
} // namespace


#endif //TAURMAZE_ASSET_H
