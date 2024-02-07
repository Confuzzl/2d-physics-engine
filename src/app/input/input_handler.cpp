module;

#include "util/gl.h"

module input_handler;

import app;
import debug;

void InputHandler::processInput(const double dt) {
  glfwPollEvents();
  for (auto &[keycode, key] : keys)
    key(dt);
}

std::map<int, Key> InputHandler::keys{
    {GLFW_KEY_ESCAPE, {[](const double) { MAIN_APP.close(); }}},
    {GLFW_KEY_W, {Key::moveFunction(glm::vec2{0, +1})}},
    {GLFW_KEY_A, {Key::moveFunction(glm::vec2{-1, 0})}},
    {GLFW_KEY_S, {Key::moveFunction(glm::vec2{0, -1})}},
    {GLFW_KEY_D, {Key::moveFunction(glm::vec2{+1, 0})}},
};

void InputHandler::keyCallback(GLFWwindow *window, int key, int scancode,
                               int action, int mods) {
  const auto iterator = keys.find(key);
  if (iterator == keys.end())
    return;
  iterator->second.change(action);
}
void InputHandler::mouseCallback(GLFWwindow *window, double xpos, double ypos) {
}
void InputHandler::scrollCallback(GLFWwindow *window, double xpos,
                                  double ypos) {
  static float INCREMENT = 0.1f;
  MAIN_CAMERA.zoom = std::fmax(
      INCREMENT, static_cast<float>(MAIN_CAMERA.zoom + ypos * INCREMENT));
}
