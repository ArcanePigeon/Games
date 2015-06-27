#include "ofApp.h"
#include "math.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofDisableArbTex();
    sun.setPointLight();
    player.loadModel("player.3ds");
    player.setScale(.1,.1,.1);
    level.loadImage("Level.png");
    level.mirror(true,false);
    int w = level.getWidth();
    int h = level.getHeight();
    for(int x = 0; x<w; x++){
        for(int y = 0; y<h; y++){
            ofColor pix = level.getColor(x,y);
             if(pix != sky){
                Blocks var1;
                if(pix == dirt){
                    var1.block.loadImage("Dirt.png");
                    var1.id = 1;
                }else if(pix == enemy){
                    var1.block.loadImage("Enemy2.png");
                    var1.id = 2;
                }else if(pix == finish){
                    var1.block.loadImage("Finish.png");
                    var1.id = 3;
                }else if(pix == coin){
                    var1.block.loadImage("Coin.png");
                    var1.id = 4;
                }else if(pix == pipe){
                    var1.block.loadImage("Pipe.png");
                    var1.id = 4;
                }else if(pix == brick){
                    var1.block.loadImage("Brick.png");
                    var1.id = 4;
                }else if(pix == shroom){
                    var1.block.loadImage("Shroom.png");
                    var1.id = 4;
                }else if(pix == star){
                    var1.block.loadImage("Star.png");
                    var1.id = 4;
                }else if(pix == black){
                    var1.block.loadImage("Black.png");
                    var1.id = 4;
                }
                var1.block.mirror(true,false);
                var1.box.set(bit);
                var1.x = x*bit- (bit*5);
                var1.y = y*bit- (bit*5);
                b.push_back(var1);
             }
        }
    }


}

//--------------------------------------------------------------
void ofApp::update(){

    if(up == true){
        x += speed;
    }
    if(down == true){
        x += -speed;
    }
    if(left == true){
        rotation -= 180;
    }
    if(right == true){
        rotation += 180;
    }

    y -= gravity;

    ofVec3f q(0,-90 + rotation,0);
    cam.setOrientation(q);
    cam.setPosition(x,y,z);
    sun.setPosition(x,y,200);

    for (std::vector<Blocks>::iterator it = b.begin() ; it != b.end(); ++it) {
        /*if(x+(bit/2)<it->x+(bit/2) && x+(bit/2) > it->x-(bit/2) && y+(bit/2)<it->y+(bit/2) && y+(bit/2) > it->y-(bit/2)){
            x = ox;
            y = oy;
            z = oz;
            std::cout << "COLLISION!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
        }
        if(x-(bit/2)<it->x+(bit/2) && x-(bit/2) > it->x-(bit/2) && y+(bit/2)<it->y+(bit/2) && y+(bit/2) > it->y-(bit/2)){
            x = ox;
            y = oy;
            z = oz;
            std::cout << "COLLISION!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
        }
        if(x+(bit/2)<it->x+(bit/2) && x+(bit/2) > it->x-(bit/2) && y-(bit/2)<it->y+(bit/2) && y-(bit/2) > it->y-(bit/2)){
            x = ox;
            y = oy;
            z = oz;
            std::cout << "COLLISION!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
        }*/

        if(x<it->x+(bit/2) && x> it->x-(bit/2) && y-5<it->y+(bit/2) && y-5> it->y-(bit/2)){
            std::cout << "COLLISION!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
            y = oy;
            collide = true;
        }
        if(x+8<it->x+(bit/2) && x+8> it->x-(bit/2) && y<it->y+(bit/2) && y> it->y-(bit/2)){
            std::cout << "COLLISION!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
            x = ox;
        }
        if(x-8<it->x+(bit/2) && x-8> it->x-(bit/2) && y<it->y+(bit/2) && y> it->y-(bit/2)){
            std::cout << "COLLISION!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
            x = ox;
        }

    }
    if(collide == true && jump == true){
        timer = 20;
        gravity = -2;
        collide = false;
    }
    if(timer <= 0){
        gravity = 1.3;
    }
    timer -= 1;

    player.setPosition(x,y,z);

    ox = x;
    oy = y;
    oz = z;

    //x += xSpeed;
    //y += ySpeed;

}

//--------------------------------------------------------------
void ofApp::draw(){

    ofEnableLighting();
    ofSetSmoothLighting(true);
    glEnable (GL_DEPTH_TEST);


    cam.begin();
    sun.enable();
    ofBackground(131,160,200);
    for (std::vector<Blocks>::iterator it = b.begin() ; it != b.end(); ++it) {
        it->block.bind();
        it->box.setPosition(it->x,it->y,0);
        it->box.draw();
    }
    ofTranslate(x,y,z);
    ofRotateX(90);
    ofRotateY(180);
    ofTranslate(-x,-y,-z);
    player.draw();
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //std::cout << key << std::endl;

    if(key == 119){
        up = true;
    }
    if(key == 115){
        down = true;
    }
    if(key == 97){
        left = true;
    }
    if(key == 100){
        right = true;
    }
    if(key == 32){
        jump = true;
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == 119){
        up = false;
    }
    if(key == 115){
        down = false;
    }
    if(key == 97){
        left = false;
    }
    if(key == 100){
        right = false;
    }
    if(key == 32){
        jump = false;
    }

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if(button == 0){
        shoot = true;
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    if(button == 0){
        shoot = false;
    }
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
