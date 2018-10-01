#include "ofApp.h"

ofPolyline* line = new ofPolyline();

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetBackgroundAuto(false);
  ofEnableAlphaBlending();
  ofSetFrameRate(60);
  for (unsigned int i=0; i < MOVER_COUNT; i++) {
    this->_movers[i] = new Mover(ofRandom(0.1, 2.0),
                                 ofRandom(0, ofGetWidth()),
                                 ofRandom(0, ofGetHeight()));
  }
}

//--------------------------------------------------------------
void ofApp::update(){
  this->_meshes.clear();
  for (auto moverA : this->_movers) {
    for(auto moverB : this->_movers) {
      if (moverA != moverB) {
        glm::vec2 force = moverA->attract(moverB);
        moverA->applyForce(force);
      }
      glm::vec2 fromTo = moverA->getPosition() - moverB->getPosition();
      float distance = glm::length(fromTo);
      if (distance <= 37) {
        ofMesh* mesh = new ofMesh();
        mesh->setMode(OF_PRIMITIVE_LINES);
        mesh->addVertex(ofPoint(moverA->getPosition().x,
                                moverA->getPosition().y));
        mesh->addColor(moverA->getColor());
        mesh->addVertex(ofPoint(moverB->getPosition().x,
                                            moverB->getPosition().y));
        mesh->addColor(moverB->getColor());
        this->_meshes.push_back(mesh);
      }
    }
    moverA->update();
  }

}

//--------------------------------------------------------------
void ofApp::draw(){
  ofSetColor(20, 20, 20, 240);
  ofRect(0, 0, ofGetWidth(), ofGetHeight());
  for (auto moverA : this->_movers) {
    moverA->display();
  }
  for (auto mesh : this->_meshes) {
    mesh->draw();
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
