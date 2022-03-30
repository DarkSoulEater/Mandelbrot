#include "input.h"

namespace input {
struct Key {
  bool press = false;
  bool pressed = false;
  bool release = false;

  void Reset() {
    press = release = false;
  }

  void Set(bool state) {
    press = pressed = state;
    release = !state;
  }
};

struct {
  Key BACKSPACE;
  Key ESCAPE;
  Key ENTER;
  Key TAB;
  Key DELETE;
  Key SPACE;
  Key LEFT_SHIFT;
  Key LEFT_CONTROL;
  Key LEFT_ALT;
  Key RIGHT_SHIFT;
  Key RIGHT_CONTROL;
  Key RIGHT_ALT;
  Key A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z;
  Key ALPHA_0, ALPHA_1, ALPHA_2, ALPHA_3, ALPHA_4, ALPHA_5, ALPHA_6, ALPHA_7, ALPHA_8, ALPHA_9;
  Key UP_ARROW, DOWN_ARROW, LEFT_ARROW, RIGHT_ARROW;
} keyboard_;

struct {
  Key LEFT;
  Key MIDDLE;
  Key RIGHT;
  sf::Vector2i position = { 0, 0 };
  sf::Vector2f world_position = { 0, 0 };
  sf::Vector2i delta = { 0, 0 };
  int scroll_delta = 0;
} mouse_;

bool GetKeyDown(KeyCode code) {
  switch (code) {
    case KeyCode::NONE:         return 0;
    case KeyCode::BACKSPACE:    return keyboard_.BACKSPACE.press;
    case KeyCode::ESCAPE:       return keyboard_.ESCAPE.press;
    case KeyCode::ENTER:        return keyboard_.ENTER.press;
    case KeyCode::TAB:          return keyboard_.TAB.press;
    case KeyCode::DELETE:       return keyboard_.DELETE.press;
    case KeyCode::SPACE:        return keyboard_.SPACE.press;
    case KeyCode::LEFT_SHIFT:   return keyboard_.LEFT_SHIFT.press;
    case KeyCode::LEFT_CONTROL: return keyboard_.LEFT_CONTROL.press;
    case KeyCode::LEFT_ALT:     return keyboard_.LEFT_ALT.press;
    case KeyCode::RIGHT_SHIFT:  return keyboard_.RIGHT_SHIFT.press;
    case KeyCode::RIGHT_CONTROL:return keyboard_.RIGHT_CONTROL.press;
    case KeyCode::RIGHT_ALT:    return keyboard_.RIGHT_ALT.press;
    case KeyCode::A:            return keyboard_.A.press;
    case KeyCode::B:            return keyboard_.B.press;
    case KeyCode::C:            return keyboard_.C.press;
    case KeyCode::D:            return keyboard_.D.press;
    case KeyCode::E:            return keyboard_.E.press;
    case KeyCode::F:            return keyboard_.F.press;
    case KeyCode::G:            return keyboard_.G.press;
    case KeyCode::H:            return keyboard_.H.press;
    case KeyCode::I:            return keyboard_.I.press;
    case KeyCode::J:            return keyboard_.J.press;
    case KeyCode::K:            return keyboard_.K.press;
    case KeyCode::L:            return keyboard_.L.press;
    case KeyCode::M:            return keyboard_.M.press;
    case KeyCode::N:            return keyboard_.N.press;
    case KeyCode::O:            return keyboard_.O.press;
    case KeyCode::P:            return keyboard_.P.press;
    case KeyCode::Q:            return keyboard_.Q.press;
    case KeyCode::R:            return keyboard_.R.press;
    case KeyCode::S:            return keyboard_.S.press;
    case KeyCode::T:            return keyboard_.T.press;
    case KeyCode::U:            return keyboard_.U.press;
    case KeyCode::V:            return keyboard_.V.press;
    case KeyCode::W:            return keyboard_.W.press;
    case KeyCode::X:            return keyboard_.X.press;
    case KeyCode::Y:            return keyboard_.Y.press;
    case KeyCode::Z:            return keyboard_.Z.press;
    case KeyCode::ALPHA_0:      return keyboard_.ALPHA_0.press;
    case KeyCode::ALPHA_1:      return keyboard_.ALPHA_1.press;
    case KeyCode::ALPHA_2:      return keyboard_.ALPHA_2.press;
    case KeyCode::ALPHA_3:      return keyboard_.ALPHA_3.press;
    case KeyCode::ALPHA_4:      return keyboard_.ALPHA_4.press;
    case KeyCode::ALPHA_5:      return keyboard_.ALPHA_5.press;
    case KeyCode::ALPHA_6:      return keyboard_.ALPHA_6.press;
    case KeyCode::ALPHA_7:      return keyboard_.ALPHA_7.press;
    case KeyCode::ALPHA_8:      return keyboard_.ALPHA_8.press;
    case KeyCode::ALPHA_9:      return keyboard_.ALPHA_9.press;
    case KeyCode::UP_ARROW:     return keyboard_.UP_ARROW.press;
    case KeyCode::DOWN_ARROW:   return keyboard_.DOWN_ARROW.press;
    case KeyCode::LEFT_ARROW:   return keyboard_.LEFT_ARROW.press;
    case KeyCode::RIGHT_ARROW:  return keyboard_.RIGHT_ARROW.press;
    case KeyCode::MOUSE_0:      return mouse_.LEFT.press;
    case KeyCode::MOUSE_1:      return mouse_.RIGHT.press;
    case KeyCode::MOUSE_2:      return mouse_.MIDDLE.press;
    default: throw std::runtime_error("GetKeyDown(): Failed incorrect button code");
  }
}

bool GetKey(KeyCode code) {
  switch (code) {
    case KeyCode::NONE:         return 0;
    case KeyCode::BACKSPACE:    return keyboard_.BACKSPACE.pressed;
    case KeyCode::ESCAPE:       return keyboard_.ESCAPE.pressed;
    case KeyCode::ENTER:        return keyboard_.ENTER.pressed;
    case KeyCode::TAB:          return keyboard_.TAB.pressed;
    case KeyCode::DELETE:       return keyboard_.DELETE.pressed;
    case KeyCode::SPACE:        return keyboard_.SPACE.pressed;
    case KeyCode::LEFT_SHIFT:   return keyboard_.LEFT_SHIFT.pressed;
    case KeyCode::LEFT_CONTROL: return keyboard_.LEFT_CONTROL.pressed;
    case KeyCode::LEFT_ALT:     return keyboard_.LEFT_ALT.pressed;
    case KeyCode::RIGHT_SHIFT:  return keyboard_.RIGHT_SHIFT.pressed;
    case KeyCode::RIGHT_CONTROL:return keyboard_.RIGHT_CONTROL.pressed;
    case KeyCode::RIGHT_ALT:    return keyboard_.RIGHT_ALT.pressed;
    case KeyCode::A:            return keyboard_.A.pressed;
    case KeyCode::B:            return keyboard_.B.pressed;
    case KeyCode::C:            return keyboard_.C.pressed;
    case KeyCode::D:            return keyboard_.D.pressed;
    case KeyCode::E:            return keyboard_.E.pressed;
    case KeyCode::F:            return keyboard_.F.pressed;
    case KeyCode::G:            return keyboard_.G.pressed;
    case KeyCode::H:            return keyboard_.H.pressed;
    case KeyCode::I:            return keyboard_.I.pressed;
    case KeyCode::J:            return keyboard_.J.pressed;
    case KeyCode::K:            return keyboard_.K.pressed;
    case KeyCode::L:            return keyboard_.L.pressed;
    case KeyCode::M:            return keyboard_.M.pressed;
    case KeyCode::N:            return keyboard_.N.pressed;
    case KeyCode::O:            return keyboard_.O.pressed;
    case KeyCode::P:            return keyboard_.P.pressed;
    case KeyCode::Q:            return keyboard_.Q.pressed;
    case KeyCode::R:            return keyboard_.R.pressed;
    case KeyCode::S:            return keyboard_.S.pressed;
    case KeyCode::T:            return keyboard_.T.pressed;
    case KeyCode::U:            return keyboard_.U.pressed;
    case KeyCode::V:            return keyboard_.V.pressed;
    case KeyCode::W:            return keyboard_.W.pressed;
    case KeyCode::X:            return keyboard_.X.pressed;
    case KeyCode::Y:            return keyboard_.Y.pressed;
    case KeyCode::Z:            return keyboard_.Z.pressed;
    case KeyCode::ALPHA_0:      return keyboard_.ALPHA_0.pressed;
    case KeyCode::ALPHA_1:      return keyboard_.ALPHA_1.pressed;
    case KeyCode::ALPHA_2:      return keyboard_.ALPHA_2.pressed;
    case KeyCode::ALPHA_3:      return keyboard_.ALPHA_3.pressed;
    case KeyCode::ALPHA_4:      return keyboard_.ALPHA_4.pressed;
    case KeyCode::ALPHA_5:      return keyboard_.ALPHA_5.pressed;
    case KeyCode::ALPHA_6:      return keyboard_.ALPHA_6.pressed;
    case KeyCode::ALPHA_7:      return keyboard_.ALPHA_7.pressed;
    case KeyCode::ALPHA_8:      return keyboard_.ALPHA_8.pressed;
    case KeyCode::ALPHA_9:      return keyboard_.ALPHA_9.pressed;
    case KeyCode::UP_ARROW:     return keyboard_.UP_ARROW.pressed;
    case KeyCode::DOWN_ARROW:   return keyboard_.DOWN_ARROW.pressed;
    case KeyCode::LEFT_ARROW:   return keyboard_.LEFT_ARROW.pressed;
    case KeyCode::RIGHT_ARROW:  return keyboard_.RIGHT_ARROW.pressed;
    case KeyCode::MOUSE_0:      return mouse_.LEFT.pressed;
    case KeyCode::MOUSE_1:      return mouse_.RIGHT.pressed;
    case KeyCode::MOUSE_2:      return mouse_.MIDDLE.pressed;
    default: throw std::runtime_error("GetKey(): Failed incorrect button code");
  }
}

bool GetKeyUp(KeyCode code) {
  switch (code) {
    case KeyCode::NONE:         return 0;
    case KeyCode::BACKSPACE:    return keyboard_.BACKSPACE.release;
    case KeyCode::ESCAPE:       return keyboard_.ESCAPE.release;
    case KeyCode::ENTER:        return keyboard_.ENTER.release;
    case KeyCode::TAB:          return keyboard_.TAB.release;
    case KeyCode::DELETE:       return keyboard_.DELETE.release;
    case KeyCode::SPACE:        return keyboard_.SPACE.release;
    case KeyCode::LEFT_SHIFT:   return keyboard_.LEFT_SHIFT.release;
    case KeyCode::LEFT_CONTROL: return keyboard_.LEFT_CONTROL.release;
    case KeyCode::LEFT_ALT:     return keyboard_.LEFT_ALT.release;
    case KeyCode::RIGHT_SHIFT:  return keyboard_.RIGHT_SHIFT.release;
    case KeyCode::RIGHT_CONTROL:return keyboard_.RIGHT_CONTROL.release;
    case KeyCode::RIGHT_ALT:    return keyboard_.RIGHT_ALT.release;
    case KeyCode::A:            return keyboard_.A.release;
    case KeyCode::B:            return keyboard_.B.release;
    case KeyCode::C:            return keyboard_.C.release;
    case KeyCode::D:            return keyboard_.D.release;
    case KeyCode::E:            return keyboard_.E.release;
    case KeyCode::F:            return keyboard_.F.release;
    case KeyCode::G:            return keyboard_.G.release;
    case KeyCode::H:            return keyboard_.H.release;
    case KeyCode::I:            return keyboard_.I.release;
    case KeyCode::J:            return keyboard_.J.release;
    case KeyCode::K:            return keyboard_.K.release;
    case KeyCode::L:            return keyboard_.L.release;
    case KeyCode::M:            return keyboard_.M.release;
    case KeyCode::N:            return keyboard_.N.release;
    case KeyCode::O:            return keyboard_.O.release;
    case KeyCode::P:            return keyboard_.P.release;
    case KeyCode::Q:            return keyboard_.Q.release;
    case KeyCode::R:            return keyboard_.R.release;
    case KeyCode::S:            return keyboard_.S.release;
    case KeyCode::T:            return keyboard_.T.release;
    case KeyCode::U:            return keyboard_.U.release;
    case KeyCode::V:            return keyboard_.V.release;
    case KeyCode::W:            return keyboard_.W.release;
    case KeyCode::X:            return keyboard_.X.release;
    case KeyCode::Y:            return keyboard_.Y.release;
    case KeyCode::Z:            return keyboard_.Z.release;
    case KeyCode::ALPHA_0:      return keyboard_.ALPHA_0.release;
    case KeyCode::ALPHA_1:      return keyboard_.ALPHA_1.release;
    case KeyCode::ALPHA_2:      return keyboard_.ALPHA_2.release;
    case KeyCode::ALPHA_3:      return keyboard_.ALPHA_3.release;
    case KeyCode::ALPHA_4:      return keyboard_.ALPHA_4.release;
    case KeyCode::ALPHA_5:      return keyboard_.ALPHA_5.release;
    case KeyCode::ALPHA_6:      return keyboard_.ALPHA_6.release;
    case KeyCode::ALPHA_7:      return keyboard_.ALPHA_7.release;
    case KeyCode::ALPHA_8:      return keyboard_.ALPHA_8.release;
    case KeyCode::ALPHA_9:      return keyboard_.ALPHA_9.release;
    case KeyCode::UP_ARROW:     return keyboard_.UP_ARROW.release;
    case KeyCode::DOWN_ARROW:   return keyboard_.DOWN_ARROW.release;
    case KeyCode::LEFT_ARROW:   return keyboard_.LEFT_ARROW.release;
    case KeyCode::RIGHT_ARROW:  return keyboard_.RIGHT_ARROW.release;
    case KeyCode::MOUSE_0:      return mouse_.LEFT.release;
    case KeyCode::MOUSE_1:      return mouse_.RIGHT.release;
    case KeyCode::MOUSE_2:      return mouse_.MIDDLE.release;
    default: throw std::runtime_error("GetKeyUp(): Failed incorrect button code");
  }
}

void KeyCallback(sf::Event& event, int action) {
  switch (event.key.code) {
    case sf::Keyboard::Backspace:      keyboard_.BACKSPACE.Set(action); break;
    case sf::Keyboard::Escape:         keyboard_.ESCAPE.Set(action); break;
    case sf::Keyboard::Enter:          keyboard_.ENTER.Set(action); break;
    case sf::Keyboard::Tab:            keyboard_.TAB.Set(action); break;
    case sf::Keyboard::Delete:         keyboard_.DELETE.Set(action); break;
    case sf::Keyboard::Space:          keyboard_.SPACE.Set(action); break;
    case sf::Keyboard::LShift:         keyboard_.LEFT_SHIFT.Set(action); break;
    case sf::Keyboard::LControl:       keyboard_.LEFT_CONTROL.Set(action); break;
    case sf::Keyboard::LAlt:           keyboard_.LEFT_ALT.Set(action); break;
    case sf::Keyboard::RShift:         keyboard_.RIGHT_SHIFT.Set(action); break;
    case sf::Keyboard::RControl:       keyboard_.RIGHT_CONTROL.Set(action); break;
    case sf::Keyboard::RAlt:           keyboard_.RIGHT_ALT.Set(action); break;
    case sf::Keyboard::A:              keyboard_.A.Set(action); break;
    case sf::Keyboard::B:              keyboard_.B.Set(action); break;
    case sf::Keyboard::C:              keyboard_.C.Set(action); break;
    case sf::Keyboard::D:              keyboard_.D.Set(action); break;
    case sf::Keyboard::E:              keyboard_.E.Set(action); break;
    case sf::Keyboard::F:              keyboard_.F.Set(action); break;
    case sf::Keyboard::G:              keyboard_.G.Set(action); break;
    case sf::Keyboard::H:              keyboard_.H.Set(action); break;
    case sf::Keyboard::I:              keyboard_.I.Set(action); break;
    case sf::Keyboard::J:              keyboard_.J.Set(action); break;
    case sf::Keyboard::K:              keyboard_.K.Set(action); break;
    case sf::Keyboard::L:              keyboard_.L.Set(action); break;
    case sf::Keyboard::M:              keyboard_.M.Set(action); break;
    case sf::Keyboard::N:              keyboard_.N.Set(action); break;
    case sf::Keyboard::O:              keyboard_.O.Set(action); break;
    case sf::Keyboard::P:              keyboard_.P.Set(action); break;
    case sf::Keyboard::Q:              keyboard_.Q.Set(action); break;
    case sf::Keyboard::R:              keyboard_.R.Set(action); break;
    case sf::Keyboard::S:              keyboard_.S.Set(action); break;
    case sf::Keyboard::T:              keyboard_.T.Set(action); break;
    case sf::Keyboard::U:              keyboard_.U.Set(action); break;
    case sf::Keyboard::V:              keyboard_.V.Set(action); break;
    case sf::Keyboard::W:              keyboard_.W.Set(action); break;
    case sf::Keyboard::X:              keyboard_.X.Set(action); break;
    case sf::Keyboard::Y:              keyboard_.Y.Set(action); break;
    case sf::Keyboard::Z:              keyboard_.Z.Set(action); break;
    case sf::Keyboard::Num0:           keyboard_.ALPHA_0.Set(action); break;
    case sf::Keyboard::Num1:           keyboard_.ALPHA_1.Set(action); break;
    case sf::Keyboard::Num2:           keyboard_.ALPHA_2.Set(action); break;
    case sf::Keyboard::Num3:           keyboard_.ALPHA_3.Set(action); break;
    case sf::Keyboard::Num4:           keyboard_.ALPHA_4.Set(action); break;
    case sf::Keyboard::Num5:           keyboard_.ALPHA_5.Set(action); break;
    case sf::Keyboard::Num6:           keyboard_.ALPHA_6.Set(action); break;
    case sf::Keyboard::Num7:           keyboard_.ALPHA_7.Set(action); break;
    case sf::Keyboard::Num8:           keyboard_.ALPHA_8.Set(action); break;
    case sf::Keyboard::Num9:           keyboard_.ALPHA_8.Set(action); break;
    case sf::Keyboard::Up:             keyboard_.UP_ARROW.Set(action); break;
    case sf::Keyboard::Down:           keyboard_.DOWN_ARROW.Set(action); break;
    case sf::Keyboard::Left:           keyboard_.LEFT_ARROW.Set(action); break;
    case sf::Keyboard::Right:          keyboard_.RIGHT_ARROW.Set(action); break;
    default: break;
  }
}


bool GetMouseButtonDown(int button) {
  if (button == 0) return mouse_.LEFT.press;
  if (button == 1) return mouse_.RIGHT.press;
  if (button == 2) return mouse_.MIDDLE.press;
  return false;
}

bool GetMouseButton(int button) {
  if (button == 0) return mouse_.LEFT.pressed;
  if (button == 1) return mouse_.RIGHT.pressed;
  if (button == 2) return mouse_.MIDDLE.pressed;
  return false;
}

bool GetMouseButtonUp(int button) {
  if (button == 0) return mouse_.LEFT.release;
  if (button == 1) return mouse_.RIGHT.release;
  if (button == 2) return mouse_.MIDDLE.release;
  return false;
}

void MouseButtonCallback(sf::Event& event, int action) {
  if (event.mouseButton.button == sf::Mouse::Right) {
    mouse_.RIGHT.Set(action);
  } else if (event.mouseButton.button == sf::Mouse::Left) {
    mouse_.LEFT.Set(action);
  } else if (event.mouseButton.button == sf::Mouse::Middle) {
    mouse_.MIDDLE.Set(action);
  }
}

sf::Vector2i GetMouseScreenPosition() {
  return mouse_.position;
}

sf::Vector2f GetMouseWorldPosition() {
  return mouse_.world_position;
}

sf::Vector2i GetMouseDelta() {
  return mouse_.delta;
}

int GetMouseScrollDelta() {
  return mouse_.scroll_delta;
}

void MousePositionCallback(sf::Vector2i position, sf::Vector2f world_position) {
  auto old_pos = mouse_.position;
  mouse_.position = position;
  mouse_.delta = mouse_.position - old_pos;
  mouse_.world_position = world_position;
}

void MouseScrollCallback(sf::Event& event) {
  mouse_.scroll_delta = event.mouseWheel.delta;
}

void ResetKeyCall() {
  keyboard_.BACKSPACE.Reset();
  keyboard_.ESCAPE.Reset();
  keyboard_.ENTER.Reset();
  keyboard_.TAB.Reset();
  keyboard_.DELETE.Reset();
  keyboard_.SPACE.Reset();
  keyboard_.LEFT_SHIFT.Reset();
  keyboard_.LEFT_CONTROL.Reset();
  keyboard_.LEFT_ALT.Reset();
  keyboard_.RIGHT_SHIFT.Reset();
  keyboard_.RIGHT_CONTROL.Reset();
  keyboard_.RIGHT_ALT.Reset();
  keyboard_.A.Reset();
  keyboard_.B.Reset();
  keyboard_.C.Reset();
  keyboard_.D.Reset();
  keyboard_.E.Reset();
  keyboard_.F.Reset();
  keyboard_.G.Reset();
  keyboard_.H.Reset();
  keyboard_.I.Reset();
  keyboard_.J.Reset();
  keyboard_.K.Reset();
  keyboard_.L.Reset();
  keyboard_.M.Reset();
  keyboard_.N.Reset();
  keyboard_.O.Reset();
  keyboard_.P.Reset();
  keyboard_.Q.Reset();
  keyboard_.R.Reset();
  keyboard_.S.Reset();
  keyboard_.T.Reset();
  keyboard_.U.Reset();
  keyboard_.V.Reset();
  keyboard_.W.Reset();
  keyboard_.X.Reset();
  keyboard_.Y.Reset();
  keyboard_.Z.Reset();
  keyboard_.ALPHA_0.Reset();
  keyboard_.ALPHA_1.Reset();
  keyboard_.ALPHA_2.Reset();
  keyboard_.ALPHA_3.Reset();
  keyboard_.ALPHA_4.Reset();
  keyboard_.ALPHA_5.Reset();
  keyboard_.ALPHA_6.Reset();
  keyboard_.ALPHA_7.Reset();
  keyboard_.ALPHA_8.Reset();
  keyboard_.ALPHA_9.Reset();
  keyboard_.UP_ARROW.Reset();
  keyboard_.DOWN_ARROW.Reset();
  keyboard_.LEFT_ARROW.Reset();
  keyboard_.RIGHT_ARROW.Reset();
  mouse_.LEFT.Reset();
  mouse_.RIGHT.Reset();
  mouse_.MIDDLE.Reset();
  mouse_.delta = {0, 0};
  mouse_.scroll_delta = 0;
}
} // namespace
