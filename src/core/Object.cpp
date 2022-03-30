#include "Object.h"
#include "util/asset.h"

std::set<std::pair<int, Object*>> Object::buffer_ = std::set<std::pair<int, Object*>>();

Object::Object(int level) {
  level_ = level;
  buffer_iterator_ = buffer_.insert({level_, this}).first;

  sprite_ = sf::Sprite(asset::LoadTexture("assets/texture/default_obj.png"));
  sprite_.setOrigin(sprite_.getTextureRect().width / 2, sprite_.getTextureRect().height / 2);
}

Object::Object(const char *path, int level) {
  level_ = level;
  buffer_iterator_ = buffer_.insert({level_, this}).first;

  sprite_ = sf::Sprite(asset::LoadTexture(path));
  sprite_.setOrigin(sprite_.getTextureRect().width / 2, sprite_.getTextureRect().height / 2);
}

Object::~Object() {
  buffer_.erase(buffer_iterator_);
}

void Object::PreUpdate() {}

void Object::Update() {}

void Object::LastUpdate() {}


void Object::OnMouseEnter() {}

void Object::OnMouseOver() {}

void Object::OnMouseExit() {}

bool Object::OnClick() {return false;}

void Object::onCollisionEnter(Object *obj) {}


void Object::SetPosition(const sf::Vector2f &position) {
  sprite_.setPosition(position);
}

void Object::SetTexture(const char* path) {
  sprite_.setTexture(asset::LoadTexture(path));
  sprite_.setOrigin(sprite_.getTextureRect().width * 0.5f, sprite_.getTextureRect().height * 0.5f);
}

void Object::SetTextureRect(const sf::IntRect& rect) {
  sprite_.setTextureRect(rect);
  sprite_.setOrigin(sprite_.getTextureRect().width * 0.5f, sprite_.getTextureRect().height * 0.5f);
}

sf::Vector2f Object::GetOrigin() {
  return sprite_.getOrigin();
}


void Object::Draw(sf::RenderWindow &window) {
  window.draw(sprite_);
}

void Object::SetSize(float width, float height) {
  auto texture_size = sprite_.getTextureRect();
  sprite_.setScale({width / texture_size.width, height / texture_size.height});
}
