#ifndef TAURMAZE__INPUT_H_
#define TAURMAZE__INPUT_H_

#include <SFML/Graphics.hpp>

namespace input {
enum class KeyCode {
  NONE,
  BACKSPACE,
  ESCAPE,
  ENTER,
  TAB,
  DELETE,
  SPACE,
  LEFT_SHIFT,
  LEFT_CONTROL,
  LEFT_ALT,
  RIGHT_SHIFT,
  RIGHT_CONTROL,
  RIGHT_ALT,
  A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
  ALPHA_0, ALPHA_1, ALPHA_2, ALPHA_3, ALPHA_4, ALPHA_5, ALPHA_6, ALPHA_7, ALPHA_8, ALPHA_9,
  UP_ARROW, DOWN_ARROW, LEFT_ARROW, RIGHT_ARROW,
  MOUSE_0, MOUSE_1, MOUSE_2
};

enum Mouse {
  LEFT = 0,
  RIGHT = 1,
  MIDDLE = 2
};

bool GetKeyDown(KeyCode code);

bool GetKey(KeyCode code);

bool GetKeyUp(KeyCode code);


bool GetMouseButtonDown(int button);

bool GetMouseButton(int button);

bool GetMouseButtonUp(int button);


sf::Vector2i GetMouseScreenPosition();

sf::Vector2f GetMouseWorldPosition();

sf::Vector2i GetMouseDelta();

int GetMouseScrollDelta();

}; // namespace

#endif //TAURMAZE__INPUT_H_
