#ifndef TAURMAZE_SRC_UI_PANEL_H_
#define TAURMAZE_SRC_UI_PANEL_H_

#include "../core//Object.h"

class Panel {
 public:
  explicit Panel();

  void Draw(sf::RenderWindow& window);

 private:
  sf::Sprite sprite_;
  std::vector<sf::Text> texts_;
};

#endif //TAURMAZE_SRC_UI_PANEL_H_
