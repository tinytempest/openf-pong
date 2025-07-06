#pragma once

#include "ofMain.h"

#include "ofxOpenCv.h" // NOTA: una vez que editaste addons.make tenes que agregar el .h aca de vision por computadora.

class ofApp : public ofBaseApp{

	public:
		void setup() override;
		void update() override;
		void draw() override;
		void exit() override;

		void keyPressed(int key) override;
		void keyReleased(int key) override;
		void mouseMoved(int x, int y ) override;
		void mouseDragged(int x, int y, int button) override;
		void mousePressed(int x, int y, int button) override;
		void mouseReleased(int x, int y, int button) override;
		void mouseScrolled(int x, int y, float scrollX, float scrollY) override;
		void mouseEntered(int x, int y) override;
		void mouseExited(int x, int y) override;
		void windowResized(int w, int h) override;
		void dragEvent(ofDragInfo dragInfo) override;
		void gotMessage(ofMessage msg) override;
		void drawCross(int x, int y, int size);
		
		ofVec2f pos;
		ofVec2f delta_pos;

		ofVec2f posRect;
		ofVec2f delta_posRect;
		int rectw;
		int recth;
		
		int boxHitCount = 0;

		ofVideoGrabber grabber;
		ofxCvColorImage	colorImg;
};
