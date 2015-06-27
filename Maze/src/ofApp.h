#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofx3DModelLoader.h"
#include "TankClass.h"
#include <vector>

class MyWall {
    public:
        int x;
        int y;
        bool vertical;
        ofx3DModelLoader tree;
};

class ofApp : public ofBaseApp{
	public:

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);


    ofCamera camera;
    ofLight sun1;
    ofLight sun2;

    float sunx = 0;
    float suny = 0;
    float sunz = 0;
    float xSpeed = 0;
    float ySpeed = 0;
    float zSpeed = 0;
    float rotation = 0;
    int distribution;
    int skyr;

    bool f = true;

    int ms = 10000;
    int wallz = 10;
    int wallw = 10;
    int wobblex;
    int wobbley;
    int wobblez;


    ofParameterGroup TankGroup;
    TankClass Tank1;

    ofPlanePrimitive floor;
    ofSpherePrimitive sun;
    ofSpherePrimitive sun3;
    ofBoxPrimitive wall1;
    ofBoxPrimitive wall2;
    ofBoxPrimitive wall3;
    ofBoxPrimitive wall4;

    ofSpherePrimitive sky;
    ofTexture skytex;
    ofTexture walltex;
    ofTexture floortex;

    ofImage skyimg;
    ofImage wallimg;
    ofImage floorimg;

    ofSpherePrimitive test;

    int wallh = 100;

    unsigned char pixels1[512*512*4];
    unsigned char pixels2[512*512*4];
    unsigned char pixels3[512*512*4];

    std::vector<MyWall> vec;


};

