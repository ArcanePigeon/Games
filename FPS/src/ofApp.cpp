#include "ofApp.h"
#include "math.h"

//--------------------------------------------------------------
void ofApp::setup(){
    sun1.setPointLight();
    Tank1.setup();
    TankGroup.add(Tank1.tankParam);
    Tank1.red = 255;
    Tank1.green = 255;
    Tank1.blue = 255;
    Tank1.upk = 119;
    Tank1.downk = 115;
    Tank1.leftk = 97;
    Tank1.rightk = 100;

    far = 2.5;
    up = 93;
    look = 80;

    hit.setRadius(1);
    hit2.setRadius(1);

    grass.set(10000,10000,10,10);
    grasstex.loadImage("images/Grass1.png");
    bricktex.loadImage("images/Brick.png");
    skytex.loadImage("images/bluecloud_up.jpg");
    sky.setRadius(6000);
    cross.loadImage("images/Cross.png");
    bedrocktex.loadImage("images/Bedrock.png");
    grasstex.getTextureReference().setTextureWrap(GL_REPEAT,GL_REPEAT);

    for (int x=0; x<chunk; x++) {
        for (int y=0; y<chunk; y++) {
            for (int z=0; z<16; z++) {
                   Block var1;
                   var1.x = x*blockSize;
                   var1.y = y*blockSize;
                   var1.z = z*blockSize - blockSize  ;
                   var1.id = 1;
                   if(z == 0){
                        var1.real = true;
                        var1.id = 0;
                   }else{
                        var1.real = false;
                   }

                   var1.block.set(blockSize);
                   vec.push_back(var1);
           }
        }
    }

}
//--------------------------------------------------------------
void ofApp::update(){
    ox = ofGetPreviousMouseX();
    oy = ofGetPreviousMouseY();
    zx = ofGetMouseX();
    zy = ofGetMouseY();
    xp = (ox-zx)  /2;
    yp = (oy-zy)  /2;
    if(mov == false){
        xp = 0;
        yp = 0;
    }
    mov = false;
    Tank1.rotation += xp;
    if(look >= 180){
        look = 180;
    }else if(look <= 0){
        look = 0;
    }
    hitx += hitxs;
    hity += hitys;
    hitz += hitzs;

    hitx2 += hitxs2;
    hity2 += hitys2;
    hitz2 += hitzs2;
    std::cout << look  << " " << hitzs << std::endl;

    look += yp;

    Tank1.zPos -= gravity;


    //std::cout << "x: " << ox << " - " << zx << " = " << xp << "    " << "y: " << oy << " - " << zy << " = " << yp << std::endl;
    Tank1.update();
    ofVec3f q(look,0,180+Tank1.rotation);
    camera.setPosition(Tank1.xPos + (Tank1.xSpeed * far),Tank1.yPos + (Tank1.ySpeed * far),Tank1.zPos +up);
    camera.setOrientation(q);

    //Display *display = XOpenDisplay(0);
    //XWarpPointer(display, None, None, 0, 0, ofGetWidth(), ofGetHeight(), mx, my);
    //XCloseDisplay(display);


    for (std::vector<Block>::iterator it = vec.begin() ; it != vec.end(); ++it) {
        if(it->real == true && hitx < it->x+blockSize/2 && hitx > it->x-blockSize/2 && hity < it->y+blockSize/2 && hity > it->y-blockSize/2 && hitz < it->z+blockSize/2 && hitz > it->z-blockSize/2){
            std::cout << "Collision" << std::endl;
            hitx = 999;
            hity = 999;
            hitz = 999;
            hitxs = 0;
            hitys = 0;
            hitzs = 0;
            oldvec->id = type;
            oldvec->real = true;
        }
        if(it->id != 0 && it->real == true && hitx2 < it->x+blockSize/2 && hitx2 > it->x-blockSize/2 && hity2 < it->y+blockSize/2 && hity2 > it->y-blockSize/2 && hitz2 < it->z+blockSize/2 && hitz2 > it->z-blockSize/2){
            std::cout << "Poof" << std::endl;
            it->real = false;
            hitx2 = 999;
            hity2 = 999;
            hitz2 = 999;
            hitxs2 = 0;
            hitys2 = 0;
            hitzs2 = 0;
        }
        if(it->real == false && hitx < it->x+blockSize/2 && hitx > it->x-blockSize/2 && hity < it->y+blockSize/2 && hity > it->y-blockSize/2 && hitz < it->z+blockSize/2 && hitz > it->z-blockSize/2){
            oldvec = it;
        }
        if(it->real == true && Tank1.xPos < it->x+blockSize/2 && Tank1.xPos > it->x-blockSize/2 && Tank1.yPos < it->y+blockSize/2 && Tank1.yPos > it->y-blockSize/2 && Tank1.zPos+5 < it->z+blockSize/2 && Tank1.zPos+5 > it->z-blockSize/2){
            Tank1.zPos = Tank1.oldz;
            //Tank1.zPos += gravity;
            collide = true;
            std::cout << "collide" << std::endl;
        }/*
        if(it->real == true && Tank1.xPos-20 < it->x+blockSize/2 && Tank1.xPos-20 > it->x-blockSize/2 && Tank1.yPos+20 < it->y+blockSize/2 && Tank1.yPos+20 > it->y-blockSize/2 && Tank1.zPos+5 < it->z+blockSize/2 && Tank1.zPos+5 > it->z-blockSize/2){
            Tank1.xPos = Tank1.oldx;
            Tank1.yPos = Tank1.oldy;
            //Tank1.zPos += gravity;
            collide = true;
            std::cout << "collide" << std::endl;
        }
        if(it->real == true && Tank1.xPos+20 < it->x+blockSize/2 && Tank1.xPos+20 > it->x-blockSize/2 && Tank1.yPos-20 < it->y+blockSize/2 && Tank1.yPos-20 > it->y-blockSize/2 && Tank1.zPos+5 < it->z+blockSize/2 && Tank1.zPos+5 > it->z-blockSize/2){
            Tank1.xPos = Tank1.oldx;
            Tank1.yPos = Tank1.oldy;
            //Tank1.zPos += gravity;
            collide = true;
            std::cout << "collide" << std::endl;
        }
        if(it->real == true && Tank1.xPos-20 < it->x+blockSize/2 && Tank1.xPos-20 > it->x-blockSize/2 && Tank1.yPos-20 < it->y+blockSize/2 && Tank1.yPos-20 > it->y-blockSize/2 && Tank1.zPos+5 < it->z+blockSize/2 && Tank1.zPos+5 > it->z-blockSize/2){
            Tank1.xPos = Tank1.oldx;
            Tank1.yPos = Tank1.oldy;
            //Tank1.zPos += gravity;
            collide = true;
            std::cout << "collide" << std::endl;
        }*/
    }

    if(collide == true && jump == true){
        timer = 20;
        gravity = -12.3;
        collide = false;
    }
    if(timer <= 0){
        gravity = 9.8;
    }
    timer -= 1;


    oldx = hitx;
    oldy = hity;
    oldz = hitz;

    oldx2 = hitx2;
    oldy2 = hity2;
    oldz2 = hitz2;


    Tank1.oldx = Tank1.xPos;
    Tank1.oldy = Tank1.yPos;
    Tank1.oldz = Tank1.zPos;

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

    sun1.enable();
    sun1.setPosition(300,0,5000);

    ofPushMatrix();
        float tx = ofGetWidth() / 2;
        float ty = ofGetHeight() / 2;
        ofTranslate(tx, ty, 400);
    ofPopMatrix();


    Tank1.draw();
    hit.setPosition(hitx,hity,hitz);
    hit.draw();

    hit2.setPosition(hitx2,hity2,hitz2);
    hit2.draw();

    ofPushStyle();
        ofSetColor(255,255,255);

        for (std::vector<Block>::iterator it = vec.begin() ; it != vec.end(); ++it) {
            if(it->real == true){
                    ofSetColor(ofColor::white);
                    if(it->id == 1){
                        grasstex.bind();
                    }else if(it->id == 2){
                        bricktex.bind();
                    }else if(it->id == 0){
                        bedrocktex.bind();
                    }

                it->block.setPosition(it->x,it->y,it->z);
                it->block.draw();
            }
        }
    ofPopStyle();
    //grasstex.getTextureReference().bind();
    //grass.draw();
    skytex.bind();
    sky.setPosition(Tank1.xPos,Tank1.yPos,Tank1.zPos);
    sky.draw();

    sun1.disable();
    camera.end();


    ofDisableLighting();
    ofSetSmoothLighting(false);
    glDisable (GL_DEPTH_TEST);

    cross.draw(ofGetWidth()/2-37,ofGetHeight()/2-37);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    std::cout << key << std::endl;
    if(key == 32){
        jump = true;
    }
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
    if(key == 112){
        if(person == 1){
            person = 2;
        }else if(person == 2){
            person = 3;
        }else if(person == 3){
            person = 1 ;
        }
        if(person == 1){
            far = 2.5;
            up = 93;
            look = 80;
        }else if(person == 2){
            far = -45;
            up = 100;
            look = 50;
        }else if(person == 3){
            far = -4;
            up = 1000;
            look = 5;
        }
    }
    if(key == 49){
        type = 1;
    }
    if(key == 50){
        type = 2;
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
    if(key == 32){
        jump = false;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    mov = true;

    /*
    if(x > ofGetWidth()/2 - 20 && x < ofGetWidth()/2 + 20){
        mx = 0;
    }
    if(y > ofGetHeight()/2 - 20 && y < ofGetHeight()/2 + 20){
        my = 0;
    }
    if(x > ofGetWidth()/2 - 20){
        mx = -1;
    }else if(x < ofGetWidth()/2 + 20){
        mx = 1;
    }
    if(y > ofGetHeight()/2 - 20){
        my = -1;
    }else if(y < ofGetHeight()/2 + 20){
        my = 1;
    }
    std::cout << mx << " " << my << std::endl;
    //Display *display = XOpenDisplay(0);
    //XWarpPointer(display, None, None, 0, 0, ofGetWidth(), ofGetHeight(), mx, my);
    //XCloseDisplay(display);
    */


}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if(button == 0){
        hitx = Tank1.xPos + (Tank1.xSpeed * far);
        hity = Tank1.yPos + (Tank1.ySpeed * far);
        hitz = Tank1.zPos +up;
        hitys = sin((270+Tank1.rotation)*PI/180)*blockSize;
        hitxs = cos((270+Tank1.rotation)*PI/180)*blockSize;
        hitzs = look-90;
        //hitzs = sin((look-90)*(PI/180))*blockSize;
        //std::cout << hitzs << std::endl;
    }
    if(button == 2){
        hitx2 = Tank1.xPos + (Tank1.xSpeed * far);
        hity2 = Tank1.yPos + (Tank1.ySpeed * far);
        hitz2 = Tank1.zPos +up;
        hitys2 = sin((270+Tank1.rotation)*PI/180)*blockSize;
        hitxs2 = cos((270+Tank1.rotation)*PI/180)*blockSize;
        hitzs2 = sin((look-90)*PI/180)*blockSize;
    }
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
