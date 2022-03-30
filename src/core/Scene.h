#ifndef TAURMAZE_SRC_CORE_SCENE_H_
#define TAURMAZE_SRC_CORE_SCENE_H_

enum class Scene {
  NONE,
  START_MENU,
  GAME,
  EXIT
};

void LoadScene(Scene scene);

Scene GetScene();

#endif //TAURMAZE_SRC_CORE_SCENE_H_
