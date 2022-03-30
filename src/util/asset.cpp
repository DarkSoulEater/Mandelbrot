#include <map>
#include "asset.h"

namespace asset {
namespace path {
  const char* t_StoneCellTiles = "../assets/texture/dungeon-tiles.jpg";

  const char* t_OnWayCell = "../assets/texture/on-way-cell.png";

  const char* t_Minotaur = "../assets/texture/minotaur.png";
} // namespace

static std::map<const char*, sf::Texture> textures_library;

sf::Texture& LoadTexture(const char* path) {
  if(textures_library.find(path) != textures_library.end()) {
      return textures_library[path];
  }
  sf::Texture texture;
  texture.loadFromFile(path);
  return textures_library[path] = texture;
}
} // namespace