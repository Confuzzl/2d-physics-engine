module scene;

import object;
import polygon;
import circle;

Scene::Scene() {}
Scene::~Scene() = default;

import sat;

import debug;

void Scene::init() {
  const auto &a = Object<Polygon>::New({3});
  // const Object &a = Object::ngon({.sides = 3}, {.pos = {0, 0}});
  // const Object &b = Object::ngon({.sides = 5}, {.pos = {3, 0}});
  //  const auto info = SAT::queryCollision(a.getCollider(), b.getCollider());
  //  println("{}", info.collision);
}