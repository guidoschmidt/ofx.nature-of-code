#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  for (unsigned int i = 0; i < 200; i++) {
    this->_movers[i] = new Mover(ofRandom(0.1, 4.0f),
                                 ofRandom(0, ofGetWidth()),
                                 ofRandom(0, ofGetHeight()));
  }
}

//--------------------------------------------------------------
void ofApp::update(){
  this->_wind = glm::vec2(ofRandom(-0.1, 0.1), 0);
  const float c = 0.05;
  for (auto mover : this->_movers) {
    const float gravity = 0.1 * mover->getMass();
    glm::vec2 friction = mover->getVelocity();
    friction = glm::normalize(friction);
    friction *= -1;
    friction *= c;

    mover->applyForce(friction);
    mover->applyForce(this->_wind);
    mover->applyForce(glm::vec2(0, gravity));

    mover->update();
    mover->checkEdges();
  }
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofBackground(42, 42, 42);
  for (auto mover : this->_movers) {
    mover->display();
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
