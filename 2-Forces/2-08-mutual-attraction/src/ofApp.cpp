#include "ofApp.h"

ofPolyline* line = new ofPolyline();

//--------------------------------------------------------------
void ofApp::setup(){
  ofSetBackgroundAuto(false);
  ofEnableAlphaBlending();
  ofSetFrameRate(60);
  for (unsigned int i=0; i < MOVER_COUNT; i++) {
    this->_movers[i] = new Mover(ofRandom(0.1, 0.9),
                                 ofRandom(ofGetWidth() / 2.0 - 500.0, ofGetWidth() / 2.0 + 500),
                                 ofRandom(ofGetHeight() / 2.0 - 500.0, ofGetHeight() / 2.0 + 500));
  }
}

//--------------------------------------------------------------
void ofApp::update(){
  for (auto moverA : this->_movers) {
    for(auto moverB : this->_movers) {
      if (moverA != moverB) {
        glm::vec2 force = moverA->attract(moverB);
        moverA->applyForce(force);
      }
      glm::vec2 fromTo = moverA->getPosition() - moverB->getPosition();
      float distance = glm::length(fromTo);
      if (distance <= 50) {
          if (this->_meshes[this->_meshIndex] == nullptr) {
              this->_meshes[this->_meshIndex] = new ofMesh();
          }
          this->_meshes[this->_meshIndex]->clear();
          this->_meshes[this->_meshIndex]->setMode(OF_PRIMITIVE_LINES);
          this->_meshes[this->_meshIndex]->addVertex(ofPoint(moverA->getPosition().x,
                                moverA->getPosition().y));
          this->_meshes[this->_meshIndex]->addColor(moverA->getColor());
          this->_meshes[this->_meshIndex]->addVertex(ofPoint(moverB->getPosition().x,
                                            moverB->getPosition().y));
          this->_meshes[this->_meshIndex]->addColor(moverB->getColor());
          this->_meshIndex = (this->_meshIndex + 1) % MESH_COUNT;
      }
    }
    moverA->update();
  }

}

//--------------------------------------------------------------
void ofApp::draw(){
  ofSetColor(0, 0, 0, 150);
  ofRect(0, 0, ofGetWidth(), ofGetHeight());
  for (auto moverA : this->_movers) {
    moverA->display();
  }
  for (auto mesh : this->_meshes) {
      if (mesh != nullptr) {
          mesh->draw();
      }
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
