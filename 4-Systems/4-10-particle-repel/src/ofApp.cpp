#include "ofApp.h"


ofColor backgroundColor; 

//--------------------------------------------------------------
void ofApp::setup(){
  // Setup openframeworks
  ofSetFrameRate(120);

  // Setup colors
  backgroundColor = ofColor();
  backgroundColor.setHex(0xf2e3c9);
  ofColor particleColor = ofColor();
  particleColor.setHex(0x7ecfc0);
  ofColor particleIntersectionColor = ofColor();
  particleIntersectionColor.setHex(0xef4b4b);

  // Setup UI
  int x = 0;
  int padding = 0;

  _uiBackgroundPicker = new ofxDatGuiColorPicker("Background",
                                                 backgroundColor);
  _uiBackgroundPicker->onColorPickerEvent(this, &ofApp::onColorPickerBackground);
  _uiBackgroundPicker->setPosition(x, 0);
  x += _uiBackgroundPicker->getWidth() + padding;

  _uiParticlePicker = new ofxDatGuiColorPicker("Particles/Color",
                                               particleColor);
  _uiParticlePicker->onColorPickerEvent(this, &ofApp::onColorPickerParticle);
  _uiParticlePicker->setPosition(x, 0);
  x += _uiParticlePicker->getWidth() + padding;

  _uiParticleHighlightPicker = new ofxDatGuiColorPicker("Particles/Intersect",
                                                        particleIntersectionColor);
  _uiParticleHighlightPicker->onColorPickerEvent(this, &ofApp::onColorPickerParticleIntersecting);
  _uiParticleHighlightPicker->setPosition(x, 0);

  // Setup particle system
  glm::vec2 origin = glm::vec2(ofGetWidth() / 2, ofGetHeight() / 2);
  _particleSystem = new ParticleSystem(origin);

  ofBackground(backgroundColor);
  _particleSystem->setParticleIntersectionColor(particleIntersectionColor);
  _particleSystem->setParticleColor(particleColor);
}

//--------------------------------------------------------------
void ofApp::update(){
  _uiBackgroundPicker->update();
  _uiParticlePicker->update();
  _uiParticleHighlightPicker->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofSetColor(backgroundColor);

  glm::vec2 mouse = glm::vec2(ofGetMouseX(), ofGetMouseY());
  for (int i = 0; i < 3; i++) {
    _particleSystem->addParticle(mouse);
  }
  _particleSystem->run();
  _particleSystem->calculateIntersections();
  // Draw UI
  _uiBackgroundPicker->draw();
  _uiParticlePicker->draw();
  _uiParticleHighlightPicker->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
void ofApp::onColorPickerBackground(ofxDatGuiColorPickerEvent e)
{
  // std::cout << "Background Color" << std::endl;
    ofSetBackgroundColor(e.color);
}

void ofApp::onColorPickerParticle(ofxDatGuiColorPickerEvent e)
{
  // std::cout << "Particle Color" << std::endl;
  _particleSystem->setParticleColor(e.color);
}

void ofApp::onColorPickerParticleIntersecting(ofxDatGuiColorPickerEvent e)
{
  // std::cout << "Intersection Color" << std::endl;
  _particleSystem->setParticleIntersectionColor(e.color);
}
