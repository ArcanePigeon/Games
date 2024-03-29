#include "TankClass.h"

void TankClass::setup(){

    tankParam.add(xPos.set("xPos",0.0,-1000000.0,1000000.0));
    tankParam.add(yPos.set("yPos",0.0,-1000000.0,1000000.0));
    tankParam.add(zPos.set("zPos",0.0,-1000000.0,1000000.0));
    tankParam.add(xSpeed.set("xSpeed",0.0,-1000000.0,1000000.0));
    tankParam.add(ySpeed.set("ySpeed",0.0,-1000000.0,1000000.0));
    tankParam.add(zSpeed.set("zSpeed",0.0,-1000000.0,1000000.0));
    tankParam.add(rSpeed.set("rSpeed",1.5,-1000000.0,1000000.0));
    tankParam.add(rotation.set("rotation",0.0,-1000000.0,1000000.0));
    tankParam.add(up.set("up",false));
    tankParam.add(down.set("down",false));
    tankParam.add(left.set("left",false));
    tankParam.add(right.set("right",false));
    tankParam.add(upk.set("upk",0,0,1000));
    tankParam.add(downk.set("downk",0,0,1000));
    tankParam.add(leftk.set("leftk",0,0,1000));
    tankParam.add(rightk.set("rightk",0,0,1000));
    tankParam.add(red.set("red",0,0,255));
    tankParam.add(green.set("green",0,0,255));
    tankParam.add(blue.set("blue",0,0,255));

    Tank.loadModel("3D/Steve.3ds");
    Tank.setScale(15,15,15);

    ofEnableLighting(); //== glEnable(GL_LIGHTING);
    glShadeModel(GL_SMOOTH);
    ofEnableSeparateSpecularLight();
    ofEnableNormalizedTexCoords();
    ofDisableArbTex();

    light.setSpotlight();
    light.setSpotConcentration(64);
    light.setSpotlightCutOff(30);

}

void TankClass::update(){

    if(up == true){
        yPos += ySpeed;
        xPos += xSpeed;
    }
    if(down == true){
        yPos -= ySpeed;
        xPos -= xSpeed;
    }
    if(left == true){
        xPos += xxSpeed;
	yPos += yySpeed;
    }
    if(right == true){
        xPos -= xxSpeed;
	yPos -= yySpeed;
    }

    yySpeed = sin((360+rotation)*PI/180)*6.5;
    xxSpeed = cos((360+rotation)*PI/180)*6.5;

    ySpeed = sin((270+rotation)*PI/180)*9.5;
    xSpeed = cos((270+rotation)*PI/180)*9.5;

    if(rotation > 360){
        rotation -= 360;
    }
    if(rotation < 0){
        rotation += 360;
    }

}


void TankClass::draw(){
    //light.enable();
    ofPushMatrix();
        ofTranslate(xPos, yPos, 0);
        ofRotate(rotation, 0, 0, 1);
	ofRotateY(-90);
	ofRotateZ(-90);
        ofPushMatrix();
            ofTranslate(-(xPos),-(yPos),0);
            Tank.setPosition(xPos,yPos-35,zPos);
            ofSetColor(red,green,blue);
            Tank.draw();
        ofPopMatrix();
        ofPushMatrix();
        //ofVec3f q(90,0,270+(((rotation)*PI)/180));
        //light.setOrientation(q);
        //light.setPosition(0,0,0);

        ofPopMatrix();
    ofPopMatrix();

}
