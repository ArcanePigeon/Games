#include "ofApp.h"
#include <vector>

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetFrameRate(60);

    sun1.setPointLight();
    sun.setRadius(90);

    sun2.setPointLight();
    sun3.setRadius(90);

    test.setRadius(30);

    wall1.set(wallw,ms,wallh);
    wall2.set(wallw,ms,wallh);
    wall3.set(ms,wallw,wallh);
    wall4.set(ms,wallw,wallh);
    sky.setRadius(4000);

    skyimg.loadImage("graycloud_up.jpg");
    wallimg.loadImage("wall.jpg");
    floorimg.loadImage("floor.jpg");

    Tank1.setup();
    TankGroup.add(Tank1.tankParam);
    Tank1.red = 255;
    Tank1.upk = 357;
    Tank1.downk = 359;
    Tank1.leftk = 356;
    Tank1.rightk = 358;

    ofSeedRandom();

    for (int i=0; i<wallz; i++) {
        for (int j=0; j<wallz; j++) {
           distribution = ofRandom(0,2);
           std::cout << distribution << std::endl;
           if (distribution == 1) {
               MyWall var1;
               var1.x = i;
               var1.y = j;
               var1.vertical = false;
               vec.push_back(var1);
           }
        }
    }

    for (int i=0; i<wallz; i++) {
        for (int j=0; j<wallz; j++) {
           distribution = ofRandom(0,2);
           std::cout << distribution << std::endl;
           if (distribution == 1) {
               MyWall var1;
               var1.x = i;
               var1.y = j;
               var1.vertical = true;
               vec.push_back(var1);
           }
        }
    }



    floor.set(ms,ms,100,100,OF_PRIMITIVE_TRIANGLES);

    for (std::vector<MyWall>::iterator it = vec.begin() ; it != vec.end(); ++it) {
        (*it).x = (*it).x * ms/wallz + ms/wallz/2;
        (*it).y = (*it).y * ms/wallz + ms/wallz/2;
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    Tank1.update();

    float time = ofGetElapsedTimef();
    float timeScale = 1.5;
    float displacementScale = 5.75;

    ofVec3f q(90,0,270+Tank1.rotation);
    wobblex = (ofSignedNoise(time*timeScale)) * displacementScale;
    wobbley = (ofSignedNoise(time*timeScale)) * displacementScale;
    wobblez = (ofSignedNoise(time*timeScale)) * displacementScale;
    camera.setPosition(Tank1.xPos + Tank1.xSpeed,Tank1.yPos + Tank1.ySpeed,Tank1.zPos +60 + wobblez);
    camera.setOrientation(q);



}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableLighting();
    ofSetSmoothLighting(true);
    glEnable (GL_DEPTH_TEST);

    ofColor centerColor = ofColor(255, 255, 255);
    ofColor edgeColor(250, 250, 250);
    ofBackgroundGradient(centerColor, edgeColor, OF_GRADIENT_CIRCULAR);

    camera.begin();


    //sun1.enable();
    //ofColor suncolor = ofColor(230,200,100);
    //sun1.setAmbientColor(suncolor);
    //sun1.setDiffuseColor(ofColor::blue);

    ofPushMatrix();
        float tx = ofGetWidth() / 2;
        float ty = ofGetHeight() / 2;
        ofTranslate(tx, ty);
    ofPopMatrix();

    Tank1.draw();


    if(f==false){
        Tank1.light.disable();
    }else{
    }

    ofPushStyle();
        skyimg.bind();
        ofSetColor(255,255,255);
        sky.setPosition(Tank1.xPos,Tank1.yPos,Tank1.zPos);
        //sky.draw();
    ofPopStyle();

    ofPushStyle();
        floorimg.bind();
        ofSetColor(255,255,255);
        floor.draw();
    ofPopStyle();


        ofPushStyle();
        wallimg.bind();

        ofSetColor(255,255,255);
        wall1.setPosition(-ms/2,0,wallh/2);
        wall1.draw();
        wall2.setPosition(ms/2,0,wallh/2);
        wall2.draw();
        wall3.setPosition(0,-ms/2,wallh/2);
        wall3.draw();
        wall4.setPosition(0,ms/2,wallh/2);
        wall4.draw();

        ofTranslate(-ms/2,-ms/2);
        for (std::vector<MyWall>::iterator it = vec.begin() ; it != vec.end(); ++it) {
            ofSetColor(ofColor::white);
            (*it).tree.setPosition((*it).x,(*it).y,wallh/2);
            (*it).tree.draw();
        }

        ofTranslate(ms/2,ms/2);
    ofPopStyle();

    sun1.disable();
    camera.end();

    ofDisableLighting();
    ofSetSmoothLighting(false);
    glDisable (GL_DEPTH_TEST);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    std::cout << key << std::endl;

    if(key == Tank1.upk){
        Tank1.up = true;
    }
    if(key == Tank1.downk){
        Tank1.down = true;
    }
    if(key == Tank1.leftk){
        Tank1.left = true;
    }
    if(key == Tank1.rightk){
        Tank1.right = true;
    }
    if(key == 102){
        if(f == 1){
            f = 0;
        }else
        if(f == 0){
            f = 1;
        }
        std::cout << f << std::endl;

    }


}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

    if(key == Tank1.upk){
        Tank1.up = false;
    }
    if(key == Tank1.downk){
        Tank1.down = false;
    }
    if(key == Tank1.leftk){
        Tank1.left = false;
    }
    if(key == Tank1.rightk){
        Tank1.right = false;
    }

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
