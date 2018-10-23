#include "ofApp.h"

double angle = 0.0;
double angleVelocity = 0.1;

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetLineWidth(2);
  ofSetFrameRate(30);
  ofNoFill();
  ofSetColor(0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  ofBeginShape();
  for (unsigned int x = 0; x < ofGetWidth(); x += 5) {
    double y = ofMap(sin(angle), -1, 1, 0, ofGetHeight());
    ofVertex(x, y);
    angle += angleVelocity;
  }
  ofEndShape();
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
