#pragma once

#include "ofMain.h"
#include <vector>

const int MAX_WAVES= 5;

class ofApp : public ofBaseApp{

private:
  float _amplitude[MAX_WAVES];
  float _dx[MAX_WAVES];
  std::vector<float> _yValues;

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

  void calcWave();
  void renderWave();
};
