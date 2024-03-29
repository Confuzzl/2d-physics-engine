module object;

import debug;
import scene;
import app;

import polygon;
import circle;

base_obj_t::base_obj_t(const float mass, const glm::vec2 &velocity,
                       const float angVelocity, const color_t &color)
    : mass{mass}, velocity{velocity}, angVelocity{angVelocity}, color{color} {}

// Object::Object(ngon_opts &&opts, obj_opts &&obj_opts)
//     : Object(Mesh::ngon(opts.sides, opts.radius, opts.offset),
//              Polygon::create(*this, opts.sides, opts.radius, opts.offset),
//              std::move(obj_opts)) {}
// Object::Object(circle_opts &&opts, obj_opts &&obj_opts)
//     : Object(Mesh::circle(opts.radius), Circle::create(*this, opts.radius),
//              std::move(obj_opts)) {}
// Object::Object(std::unique_ptr<Mesh> mesh, std::unique_ptr<Collider>
// collider,
//                obj_opts &&opts)
//     : mesh{std::move(mesh)}, collider{std::move(collider)}, /*pos{opts.pos},
//       rotation{opts.rotation}, mass{opts.mass}*/
//       properties{.pos = opts.pos, .rotation = opts.rotation, .mass =
//       opts.mass}, color{opts.color} {}
// Object::~Object() = default;
//
// Object &Object::ngon(ngon_opts &&opts, obj_opts &&obj_opts) {
//   return genericCreate(std::move(opts), std::move(obj_opts));
// }
// Object &Object::circle(circle_opts &&opts, obj_opts &&obj_opts) {
//   return genericCreate(std::move(opts), std::move(obj_opts));
// }
//
// void Object::translate(const glm::vec2 &v) { properties.pos += v; }
// void Object::rotate(const float r) { properties.rotation += r; }