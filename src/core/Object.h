#ifndef TAURMAZE__OBJECT_H_
#define TAURMAZE__OBJECT_H_

#include <set>
#include <SFML/Graphics.hpp>
#include <iterator>

enum class Tag {
  NONE,
  DEBUG,
  LEVEL_1,
  LEVEL_2,
  LEVEL_3,
  UI,
  UI_1,
  UI_2,
  UI_3,
};

class Object {
 public:
  friend class Core;
  explicit Object(int level = 0);

  explicit Object(const char* path, int level = 0);

  virtual ~Object();


  virtual void PreUpdate();

  virtual void Update();

  virtual void LastUpdate();


  virtual void OnMouseEnter();

  virtual void OnMouseOver();

  virtual void OnMouseExit();

  virtual bool OnClick();

  virtual void onCollisionEnter(Object *obj);


  virtual void SetPosition(const sf::Vector2f& position);

  virtual void SetTexture(const char* path);

  virtual void SetTextureRect(const sf::IntRect&);

  virtual sf::Vector2f GetOrigin();

  virtual void Draw(sf::RenderWindow&);

  virtual void Draw(sf::RenderTexture& texture) {
    texture.draw(sprite_);
  }

  virtual void SetSize(float width, float height);

protected:
  int level_;
  sf::Sprite sprite_;

private:
  static std::set<std::pair<int, Object*>> buffer_;
  std::set<std::pair<int, Object*>>::const_iterator buffer_iterator_;
  bool is_mouse_over_ = false;
};

#endif //TAURMAZE__OBJECT_H_
