#pragma once

#include "ofMain.h"
#include <vector>

class Tree {
    public:
        int x;
        int y;
        bool real;
        int id = 1;
        ofImage tree;
};
class Grass {
    public:
        int x;
        int y;
        bool real;
        int id = 1;
        ofImage grass;
};
class Bullet {
    public:
        int x;
        int y;
        float xSpeed;
        float ySpeed;
        bool real;
        int id = 1;
        ofImage bullet;
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

		ofImage player;

		float x;
		float y;
		float xSpeed;
		float ySpeed;
		float dx;
		float dy;
		float rotation;
		float blockSize = 400;
		int chunk = 16;
		float speed = 9;
		ofCamera cam;

		bool up;
		bool down;
		bool left;
		bool right;
		bool shoot;

        std::vector<Tree> t;
        std::vector<Grass> g;
        std::vector<Bullet> b;

};
