#pragma once

#include <ofMain.h>

class Pendulum {
private:
  glm::vec2 _position;
  glm::vec2 _origin;
  double _radius;
  double _angle;
  double _angularVelocity;
  double _angularAcceleration;
  double _ballr;
  double _damping;
  bool _dragging;
 
public:
  Pendulum(glm::vec2 origin, double radius);
  void go();
  void update();
  void display();
  void clicked(int mx, int my);
  void stopDragging();
  void drag();
};
