#pragma once

#include "ofMain.h"
#include "ofxDatGui.h"
#include "ParticleSystem.hpp"

class ofApp : public ofBaseApp{
private:
  ofxDatGuiColorPicker *_uiBackgroundPicker;
  ofxDatGuiColorPicker *_uiParticlePicker;
  ofxDatGuiColorPicker *_uiParticleHighlightPicker;

  void onColorPickerBackground(ofxDatGuiColorPickerEvent e);
  void onColorPickerParticle(ofxDatGuiColorPickerEvent e);
  void onColorPickerParticleIntersecting(ofxDatGuiColorPickerEvent e);

  ParticleSystem *_particleSystem;

public:
  void setup();
  void update();
  void draw();

  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y);
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void mouseEntered(int x, int y);
  void mouseExited(int x, int y);
  void windowResized(int w, int h);
  void dragEvent(ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);
};
