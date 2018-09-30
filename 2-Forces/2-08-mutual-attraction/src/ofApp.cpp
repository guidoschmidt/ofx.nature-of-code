#include "ofApp.h"

ofPolyline* line = new ofPolyline();

//--------------------------------------------------------------
void ofApp::setup(){
  for (unsigned int i=0; i < MOVER_COUNT; i++) {
    this->_movers[i] = new Mover(ofRandom(0.1, 0.2),
                                 ofRandom(0, ofGetWidth()),
                                 ofRandom(0, ofGetHeight()));
    this->_meshes[i] = new ofMesh();
    this->_meshes[i]->setMode(OF_PRIMITIVE_LINES);
  }
}

//--------------------------------------------------------------
void ofApp::update(){
  unsigned int i = 0;
  for (auto moverA : this->_movers) {
    for(auto moverB : this->_movers) {
      if (moverA != moverB) {
        glm::vec2 force = moverA->attract(moverB);
        moverA->applyForce(force);
      }
      glm::vec2 fromTo = moverA->getPosition() - moverB->getPosition();
      float distance = glm::length(fromTo);
      this->_meshes[i]->clearVertices();
      this->_meshes[i]->clearColors();
      if (distance <= 120.0) {
        this->_meshes[i]->addVertex(ofPoint(moverA->getPosition().x,
                                            moverA->getPosition().y));
        this->_meshes[i]->addColor(moverA->getColor());
        this->_meshes[i]->addVertex(ofPoint(moverB->getPosition().x,
                                            moverB->getPosition().y));
        this->_meshes[i]->addColor(moverB->getColor());
      }
    }
    i++;
    moverA->update();
  }

}

//--------------------------------------------------------------
void ofApp::draw(){
  ofBackground(20);
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
