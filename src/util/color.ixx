export module color;

import glm;
import math;

export using color_t = glm::uvec3;

export namespace colors {
const color_t BLACK{0}, DARK_GRAY{63}, GRAY{127}, LIGHT_GRAY{191}, WHITE{255};

const color_t RED{255, 0, 0}, GREEN{0, 255, 0}, BLUE{0, 0, 255};

color_t random() {
  return {randomInt(0u, 255u), randomInt(0u, 255u), randomInt(0u, 255u)};
}
} // namespace colors