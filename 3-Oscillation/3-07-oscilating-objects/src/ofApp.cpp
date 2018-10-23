#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetFrameRate(60);
  ofEnableSmoothing();
  ofSetBackgroundAuto(false);
  ofEnableAlphaBlending();
  for (unsigned int i = 0; i < OSC_COUNT; i++) {
    _oscillators[i] = new Oscillator();
  }
}

//--------------------------------------------------------------
void ofApp::update(){
  for (auto osc : _oscillators) {
    osc->oscillate();
  }
}

//--------------------------------------------------------------
void ofApp::draw() {
  ofSetColor(250, 250, 250, 20);
  ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
  for (auto osc : _oscillators) {
    osc->display();
  }
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
