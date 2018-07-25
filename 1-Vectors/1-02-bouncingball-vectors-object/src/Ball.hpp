#pragma once

#include "ofMain.h"

class Ball {

private:
  glm::vec2 _position;
  glm::vec2 _velocity;

public:
  Ball();
  void update();
  void display();
};
