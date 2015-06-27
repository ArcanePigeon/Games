#pragma once

#include "ofMain.h"
#include "ofx3DModelLoader.h"
#include "TankClass.h"
#include <vector>

class Block {
    public:
        int x;
        int y;
        int z;
        bool real;
        int id = 1;
        ofBoxPrimitive block;
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

		ofCamera camera;
		ofLight sun1;
		ofParameterGroup TankGroup;
        TankClass Tank1;
        ofPlanePrimitive grass;
        ofImage grasstex;
        ofSpherePrimitive sky;
        ofImage skytex;
        ofImage cross;
        ofImage bricktex;
        ofImage bedrocktex;

        int far = 18;
        int up = 70;
        int person = 1;
        int look = 80;

        float ox;
        float oy;
        float xp;
        float yp;
        float zx;
        float zy;
        float mx;
        float my;
        bool jump;
        bool xt = false;
        bool yt = false;
        bool mov = false;
        float chunk = 32;
        float blockSize = 64;

        float timer = 20;

        ofSpherePrimitive hit;
        float hitx;
        float hity;
        float hitz;

        float hitxs;
        float hitys;
        float hitzs;

        float oldx;
        float oldy;
        float oldz;

        ofSpherePrimitive hit2;
        float hitx2;
        float hity2;
        float hitz2;

        float hitxs2;
        float hitys2;
        float hitzs2;

        float oldx2;
        float oldy2;
        float oldz2;

        float gravity = 9.8;

        int type = 1;

        bool collide = false;

        float velocity;

        std::vector<Block>::iterator oldvec;

        std::vector<Block> vec;


};
