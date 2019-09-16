#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  glm::vec2 systemOrigin = {
    ofGetWidth() / 2,
    ofGetHeight() / 2 + ofGetHeight() / 3 };
  _images = std::vector<ofImage>(5);
  std::string imagePaths[5] = {
    "corona.png",
    "emitter.png",
    "particle.png",
    "texture.png",
    "reflection.png"
  };
  for (int i = 0; i < 5; i++) {
    _images[i] = ofImage();
    _images[i].load(imagePaths[i]);
  }
  _particleSystem = new ParticleSystem(systemOrigin, _images);
  ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  ofBackground(0);
  _particleSystem->addParticle();
  glm::vec2 gravity = glm::vec2(0, -0.03);
  _particleSystem->applyForce(gravity);
  _particleSystem->run();
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
