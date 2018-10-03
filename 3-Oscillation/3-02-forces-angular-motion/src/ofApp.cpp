#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  this->_attractor = new Attractor();
  for (unsigned int i = 0; i < MOVER_COUNT; i++) {
    this->_movers[i] = new Mover(ofRandom(0.1, 2.0),
                                 ofRandom(0, ofGetWidth()),
                                 ofRandom(0, ofGetHeight()));
  }
}

//--------------------------------------------------------------
void ofApp::update() {
  for (auto mover : this->_movers) {
    glm::vec2 force = this->_attractor->attract(mover);
    mover->applyForce(force);
    mover->update();
  }
}

//--------------------------------------------------------------
void ofApp::draw() {
  ofBackground(12, 12, 12);
  this->_attractor->display();
  for (auto mover : this->_movers) {
    glm::vec2 force = this->_attractor->getPosition() - mover->getPosition();
    double distance = glm::length(force);
    mover->display(distance);
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}
