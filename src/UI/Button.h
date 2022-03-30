#ifndef TAURMAZE_SRC_UI_BUTTON_H_
#define TAURMAZE_SRC_UI_BUTTON_H_

#include "core/Object.h"
#include <functional>

void b_DefaultFunction();

void b_LoadGameScene();

class Button : public Object {
 public:
  explicit Button(std::function<void()> function = b_DefaultFunction);

  bool OnClick() override;

 private:
  std::function<void()> function_;
};

#endif //TAURMAZE_SRC_UI_BUTTON_H_
