 #ifndef H_MOVER
 #define H_MOVER

#include "ofMain.h"
#include <iostream>

class Mover {
private:
  glm::vec2 _position;
  glm::vec2 _velocity;
  glm::vec2 _acceleration;
  ofColor _color;
  float _topSpeed = 5.0f;
public:
  Mover();
  void update();
  void display();
};

 #endif // H_MOVER
