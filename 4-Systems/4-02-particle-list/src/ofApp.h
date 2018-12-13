#pragma once

#include "ofMain.h"
#include "Particle.hpp"
#include <vector>

class ofApp : public ofBaseApp{
private:
  std::vector<Particle*> _particles;
  
public:
  void setup();
  void draw();	
};
