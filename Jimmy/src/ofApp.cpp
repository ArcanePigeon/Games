#include "ofApp.h"
#include "math.h"

//--------------------------------------------------------------
void ofApp::setup(){
    player.loadImage("Player.png");
    for (int x=0; x<chunk; x++) {
        for (int y=0; y<chunk; y++) {
            Tree var1;
            var1.x = x*blockSize - ofGetWidth() + ofRandom(-90,160) - 3600;
            var1.y = y*blockSize - ofGetHeight() + ofRandom(-90,160) - 3600;
            var1.id = ofRandom(1,8);
            if(var1.id == 1){
                var1.tree.loadImage("hemp01.png");
            }else if(var1.id == 2){
                var1.tree.loadImage("grasses02.png");
            }else if(var1.id == 3){
                var1.tree.loadImage("bigtree03.png");
            }else if(var1.id == 4){
                var1.tree.loadImage("pine-half07.png");
            }else if(var1.id == 5){
                var1.tree.loadImage("shrub1-05.png");
            }else if(var1.id == 6){
                var1.tree.loadImage("shrub1-03.png");
            }else if(var1.id == 7){
                var1.tree.loadImage("pine-half04.png");
            }else if(var1.id == 8){
                var1.tree.loadImage("pine-half05.png");
            }
            t.push_back(var1);
        }
    }
    for (int x=0; x<9; x++) {
        for (int y=0; y<9; y++) {
            Grass var1;
            var1.x = x*800 - ofGetWidth()*1.5 - 3600;
            var1.y = y*800 - ofGetHeight()*1.5 - 3600;
            var1.grass.loadImage("grass.jpg");
            var1.id = 1;
            g.push_back(var1);
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){

    dx = mouseX-ofGetWidth()/2 - x;
    dy = mouseY-ofGetHeight()/2 - y;

    rotation = atan2(dy,dx)*(180/PI);

    if(up == true){
        y += speed;
    }
    if(down == true){
        y += -speed;
    }
    if(left == true){
        x += -speed;
    }
    if(right == true){
        x += speed;
    }
    cam.setPosition(x,y,900);

    //x += xSpeed;
    //y += ySpeed;

}

//--------------------------------------------------------------
void ofApp::draw(){
    std::cout << "x: " << x << " " << "y: " << y << " Rotation: " << rotation << std::endl;
    cam.begin();
    ofSetColor(ofColor::grey);
    //ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    for (std::vector<Grass>::iterator it = g.begin() ; it != g.end(); ++it) {
        it->grass.draw(it->x,it->y);
    }
    ofSetColor(ofColor::white);
    ofPushMatrix();
    ofTranslate(x,y);
    ofRotate(-rotation);
    ofTranslate(-(x),-(y));
    player.draw(x-32,y-32);
    ofPopMatrix();

    for (std::vector<Tree>::iterator it = t.begin() ; it != t.end(); ++it) {
        it->tree.draw(it->x,it->y);
    }
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
