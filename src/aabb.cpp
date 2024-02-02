module aabb;

import collider;

import debug;

static VBO<ShapeVertex> sharedVBO() {
  static VBO<ShapeVertex> out{4};
  return out;
}

AABB::AABB(const Collider &parent, const glm::vec2 &min, const glm::vec2 &max)
    : parent{parent}, min{min}, max{max}, vbo{sharedVBO()} {}

void AABB::expand(const glm::vec2 &p) {
  min.x = std::min(min.x, p.x);
  max.x = std::max(max.x, p.x);
  min.y = std::min(min.y, p.y);
  max.y = std::max(max.y, p.y);
}

std::array<glm::vec2, 4> AABB::corners() const {
  return {{min, {max.x, min.y}, max, {min.x, max.y}}};
}

glm::vec2 AABB::globalPos() const { return parent.globalPos(); }