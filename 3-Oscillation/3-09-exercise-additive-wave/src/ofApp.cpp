#include "ofApp.h"

int xSpacing = 8;
int w;
float theta = 0.0;

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetFrameRate(30);

  w = ofGetWidth() + 16;
  for (unsigned int i = 0; i < MAX_WAVES; i++) {
    _amplitude[i] = ofRandom(10, 30);
    float period = ofRandom(100, 300);
    _dx[i] = (TWO_PI / period) * xSpacing;
  }

  _yValues.reserve(w / xSpacing);
  for (unsigned int i = 0; i < w / xSpacing; i++) {
    _yValues.push_back(0);
  }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  ofBackground(0);
  ofSetColor(255);
  calcWave();
  renderWave();
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

void ofApp::calcWave() {
  theta += 0.02;
  for (unsigned int i = 0; i < _yValues.size(); i++) {
    _yValues[i] = 0;
  }

  for (unsigned int j = 0; j < MAX_WAVES; j++) {
    float x = theta;
    for (unsigned i = 0; i < _yValues.size(); i++) {
      if (j % 2 == 0) {
        _yValues[i] += sin(x) * _amplitude[j];
      } else {
        _yValues[i] += cos(x) * _amplitude[j];
      }
      x += _dx[j];
    }
  }
}

void ofApp::renderWave() {
  ofFill();
  ofSetColor(255);
  for (unsigned int x = 0; x < _yValues.size(); x++) {
    ofDrawCircle(x * xSpacing, ofGetHeight() / 2 + _yValues[x], 3);
  }
}
