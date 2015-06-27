#pragma once

#include "ofMain.h"
#include "ofx3DModelLoader.h"
#include <vector>

class Blocks {
    public:
        int x;
        int y;
        int z;
        int id = 1;
        ofImage block;
        ofBoxPrimitive box;
};
class ofApp : public ofBaseApp{

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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        ofx3DModelLoader player;

		float x;
		float y;
		float z;
		float ox;
		float oy;
		float oz;
		float xSpeed;
		float ySpeed;
		float dx;
		float dy;
		float rotation;
		bool collide = false;
		float blockSize = 400;
		int chunk = 16;
		int bit = 8;
		float speed = .7;
		float gravity = 1.3;
		ofCamera cam;

		ofLight sun;

		bool up;
		bool down;
		bool left;
		bool right;
		bool shoot;
		bool jump;
		bool boing;
		int timer = 20;

		ofColor dirt = ofColor(0,255,0);
		ofColor sky = ofColor(0,0,255);
		ofColor enemy = ofColor(255,0,0);
		ofColor coin = ofColor(255,255,255);
		ofColor finish = ofColor(0,0,0);
		ofColor pipe = ofColor(0,255,255);
		ofColor brick = ofColor(255,255,0);
		ofColor shroom = ofColor(255,0,255);
		ofColor star = ofColor(1,1,1);
		ofColor black = ofColor(2,2,2);

		ofImage level;

		std::vector<Blocks> b;

};
