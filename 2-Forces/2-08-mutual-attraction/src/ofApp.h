#pragma once

#include "ofMain.h"
#include "Mover.hpp"
#include <vector>

const int MOVER_COUNT = 350;
const int MESH_COUNT = 200;

class ofApp : public ofBaseApp{

private:
  unsigned int _meshIndex = 0;
  Mover* _movers[MOVER_COUNT];
  ofMesh* _meshes[MESH_COUNT];

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
