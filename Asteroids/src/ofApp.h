#pragma once

#include "ofMain.h"
#include "ofx3DModelLoader.h"
#include <vector>

class Asteroid {
    public:
        float x;
        float y;
        float xSpeed;
        float ySpeed;
        float sizes;
        bool dead = false;
        ofBoxPrimitive Asteroid;

        float life = 1000;
};
class Bullet {
    public:
        float x;
        float y;
        float xSpeed;
        float ySpeed;
        bool dead = false;
        ofBoxPrimitive Bullet;

        float life = 500;
};

class Life {
    public:
        float x;
        float y;
        int i;
        bool dead = false;
        ofImage Heart;
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

        //ship position
        ofEasyCam cam;
        ofLight sun;
        ofImage gover;
		float x;
		float y = -ofGetHeight()/2 + 100;

		bool left;
		bool right;
		bool space;

		ofx3DModelLoader Ship;
		float timer = 10;

		float AT = 0;

		float life = 10;
		bool over = false;

		std::vector<Bullet> b;
		std::vector<Asteroid> a;
		std::vector<Life> l;


};
