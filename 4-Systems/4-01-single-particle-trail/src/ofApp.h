#pragma once

#include "ofMain.h"
#include "Particle.hpp"

class ofApp : public ofBaseApp{
private:
  Particle* _particle;
  
public:
  void setup();
  void draw();	
};
