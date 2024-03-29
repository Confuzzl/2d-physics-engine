module;

#include "util/gl.h"
#include <numbers>
#include <numeric>

export module mesh;

import <vector>;
import <functional>;
import <map>;
import <memory>;

import buffer_objects;
import vertices;
import poly;

template <typename T> struct BufferHolder {
  std::map<unsigned char, T> objects{};

  T &get(const unsigned char n) {
    if (!objects.contains(n))
      objects.emplace(n, T{n});
    return objects.at(n);
  }
};

export BufferHolder<vbo<vertex::simple>> VBOHolder{};
BufferHolder<radial_ebo> EBOHolder{};

export struct Mesh {
  static constexpr unsigned char SEGMENTS = 32;

  std::vector<vertex::simple> localVertexData;
  const vbo<vertex::simple> &vbo;
  const radial_ebo &ebo;

  Mesh(const std::vector<vertex::simple> &data)
      : localVertexData{data},
        vbo{VBOHolder.get(static_cast<unsigned char>(data.size()))},
        ebo{EBOHolder.get(static_cast<unsigned char>(data.size()))} {}

  // static std::unique_ptr<Mesh> ngon(const unsigned char n, const double
  // radius,
  //                                   const double offset) {
  //   std::vector<vertex::simple> data{};
  //   data.reserve(n + 1);
  //   data.emplace_back(0.0f, 0.0f);
  //   for (const auto &vertex : ngonVertices(n, radius, offset))
  //     data.emplace_back(vertex.x, vertex.y);
  //   return std::make_unique<Mesh>(data);
  // }
  // static std::unique_ptr<Mesh> circle(const double radius) {
  //   return ngon(SEGMENTS, radius, 0);
  // }
};
