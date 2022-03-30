#include "Scene.h"

static Scene target_scene = Scene::NONE;

void LoadScene(Scene scene) {
  target_scene = scene;
}

Scene GetScene() {
  return target_scene;
}
