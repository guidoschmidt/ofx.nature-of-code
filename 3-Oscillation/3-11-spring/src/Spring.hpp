#pragma once

#include "ofMain.h"
#include "Mover.hpp"

class Spring {
private:
  glm::vec2 _anchor;
  float _length;
  float _k;

public:
  Spring(float x, float y, int l);
  void connect(Mover* b);
  void update();
  void applyForce(glm::vec2 force);
  void display();
  void displayLine(Mover* mover);
  void constrainLength(Mover* m, float minLength, float maxLength);
  void clicked(int mx, int my);
  void stopDragging();
  void drag(int mx, int my);
};
