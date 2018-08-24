#pragma once

#include "ofMain.h"
#include "Mover.hpp"

class Attractor {
private:
  float _mass;
  float _G;
  glm::vec2 _position;
  bool _dragging;
  bool _rollover;
  glm::vec2 _dragOffset;

public:
  Attractor();

  glm::vec2 attract(Mover* mover);
  void display();
  void clicked(int mx, int my);
  void hover(int mx, int my);
  void stopDragging();
  void drag();
};
