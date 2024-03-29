export module collider;

import glm;

import aabb;
import poly;
import query_info;

export struct Polygon;
export struct Circle;

export struct Collider {
protected:
  aabb_t aabb;
  glm::vec2 position{};
  float rotation = 0;

  virtual void translateAABB(const glm::vec2 &offset) = 0;
  virtual void setRotateAABB() = 0;

public:
  Collider(aabb_t &&aabb, const glm::vec2 &pos, const float rot);

  glm::vec2 pos() const;
  void translate(const glm::vec2 &v);
  void setPos(const glm::vec2 &v);
  float rot() const;
  void rotate(const float r);
  void setRot(const float r);

  // aabb_t &getAABB() { return aabb; }
  aabb_t getAABB() const { return aabb; }

  virtual SAT::QueryInfo reverseQuery(const Collider &other) const = 0;
  virtual SAT::QueryInfo query(const Polygon &other) const = 0;
  virtual SAT::QueryInfo query(const Circle &other) const = 0;
};
