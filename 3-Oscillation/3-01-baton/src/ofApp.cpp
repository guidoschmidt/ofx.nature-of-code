#include "ofApp.h"

float angle = 0;

//--------------------------------------------------------------
void ofApp::setup(){
  ofEnableSmoothing();
}

//--------------------------------------------------------------
void ofApp::update(){
  
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofBackground(250, 250, 250);
  ofSetRectMode(OF_RECTMODE_CENTER);
  ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
  ofRotateDeg(angle);
  ofSetLineWidth(2);

  ofNoFill();
  ofSetColor(0);
  ofDrawLine(-50, 0, 50, 0);
  ofDrawEllipse( 50, 0, 16, 16);
  ofDrawEllipse(-50, 0, 16, 16);

  ofFill();
  ofSetColor(127);
  ofDrawEllipse( 50, 0, 16, 16);
  ofDrawEllipse(-50, 0, 16, 16);

  angle += 0.05;
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
