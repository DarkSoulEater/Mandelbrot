#include "Button.h"
#include "../core/Scene.h"

#include <iostream>
void b_DefaultFunction() {
  std::cout << "You do not set function!\n";
}

void b_LoadGameScene() {
  LoadScene(Scene::GAME);
}

Button::Button(std::function<void()> function) : Object("../assets/texture/default_button.png", 10) {
  function_ = function;
}
bool Button::OnClick() {
  // Object::OnClick();
  function_();
  return true;
}
