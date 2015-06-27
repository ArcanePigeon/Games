#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    sun.setPointLight();
    sun.setPosition(100,200,300);

    Ship.loadModel("Ship.3DS");
    gover.loadImage("GameOver.jpg");
    Ship.setScale(.1,.1,.1);
    for(int i = 0; i<10; i++){
        Life var1;
        var1.i = i;
        var1.x = ofGetWidth() -i+1*16;
        var1.y = 0;
        var1.Heart.loadImage("Heart.jpg");
        var1.Heart.resize(16,16);
        l.push_back(var1);
    }


}

//--------------------------------------------------------------
void ofApp::update(){

    if(life<=0){
        over = true;
        gover.resize(ofGetWidth(),ofGetHeight());
        for (std::vector<Asteroid>::iterator it = a.begin() ; it != a.end(); ++it) {
            it->dead = true;
        }
    }

    Ship.setPosition(x,y,0);
    if(right == true){
        x += 5;
    }
    if(left == true){
        x -= 5;
    }
    if(AT <= 0){
        Asteroid var1;
        var1.x = ofRandom(-ofGetWidth()/2,ofGetWidth()/2);
        var1.y = ofGetHeight()/2;
        var1.sizes = ofRandom(60,90);
        var1.Asteroid.set(var1.sizes);
        a.push_back(var1);
        AT = 90;
    }
    AT -= 1;
    if(timer <= 0){
        if(space == true){
            Bullet var1;
            var1.x = x-67;
            var1.y = y+40;
            var1.Bullet.set(5);
            b.push_back(var1);
            Bullet var2;
            var2.x = x+67;
            var2.y = y+40;
            var2.Bullet.set(5);
            b.push_back(var2);
        }
        timer = 40;
    }
    timer -= 1;

    for (std::vector<Bullet>::iterator it = b.end() ; it != b.begin(); --it) {
        if(it->dead == true){
            //b.erase(it);
            //std::cout << "poof bullet" << std::endl;
        }
    }
    for (std::vector<Asteroid>::iterator it = a.end() ; it != a.begin(); --it) {
        if(it->dead == true){
            //a.erase(it);
            //std::cout << "poof asteroid" << std::endl;
        }
    }
    for (std::vector<Life>::iterator lifez = l.end() ; lifez != l.begin(); --lifez) {
        if(life == 10){
        }else if(life == 9 && lifez-> i == 9){
            l.erase(lifez);
        }else if(life == 8 && lifez-> i == 8){
            l.erase(lifez);
        }else if(life == 7 && lifez-> i == 7){
            l.erase(lifez);
        }else if(life == 6 && lifez-> i == 6){
            l.erase(lifez);
        }else if(life == 5 && lifez-> i == 5){
            l.erase(lifez);
        }else if(life == 4 && lifez-> i == 4){
            l.erase(lifez);
        }else if(life == 3 && lifez-> i == 3){
            l.erase(lifez);
        }else if(life == 2 && lifez-> i == 2){
            l.erase(lifez);
        }else if(life == 1 && lifez-> i == 1){
            l.erase(lifez);
        }else if(life == 0 && lifez-> i == 0){
            l.erase(lifez);
        }
    }
    for (std::vector<Bullet>::iterator it = b.begin() ; it != b.end(); ++it) {
        it->y += 5;
        it->Bullet.setPosition(it->x,it->y,0);
        it->life -= 1;
        if(it->life <= 0){
            it->dead = true;
        }
    }
    for (std::vector<Asteroid>::iterator it = a.begin() ; it != a.end(); ++it) {
        it->life -= 1;
        if(it->life <= 0){
            it->dead = true;
        }
        it->y -= 1.2;
        it->Asteroid.setPosition(it->x,it->y,0);
        for (std::vector<Bullet>::iterator itz = b.begin() ; itz != b.end(); ++itz) {
            if(itz->x < it->x+it->sizes/2 && itz->x > it->x-it->sizes/2 && itz->y < it->y+it->sizes/2 && itz->y > it->y-it->sizes/2){
                it->dead = true;
                it->x = 999;
                it->y = 999;
                itz->dead = true;
                itz->x = 9999;
                itz->y = 9999;
                //std::cout << "WOOOOOOO" << std::endl;
            }
        }

        if(x+50 < it->x+it->sizes/2 && x+50 > it->x-it->sizes/2 && y-50 < it->y+it->sizes/2 && y-50 > it->y-it->sizes/2){
            life -= 1;
            it->dead = true;
            it->x = 999;
            it->y = 999;
        }
        if(x-50 < it->x+it->sizes/2 && x-50 > it->x-it->sizes/2 && y-50 < it->y+it->sizes/2 && y-50 > it->y-it->sizes/2){
            life -= 1;
            it->dead = true;
            it->x = 999;
            it->y = 999;
        }
        if(x < it->x+it->sizes/2 && x > it->x-it->sizes/2 && y-50 < it->y+it->sizes/2 && y-50 > it->y-it->sizes/2){
            life -= 1;
            it->dead = true;
            it->x = 999;
            it->y = 999;
        }
        if(-ofGetHeight()/2 < it->y+it->sizes/2 && -ofGetHeight()/2 > it->y-it->sizes/2){
            //std::cout << " Life Lost " << std::endl;
            life -= 1;
            it->dead = true;
            it->x = 999;
            it->y = 999;
        }

    }
    if(x >= ofGetWidth()/2){
        x -= 7;
    }
     if(x <= -ofGetWidth()/2){
        x += 7;
    }


}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableLighting();
    ofSetSmoothLighting(true);
    glEnable (GL_DEPTH_TEST);

    cam.begin();
    sun.enable();
    ofSetColor(ofColor::white);
    Ship.draw();
    ofSetColor(ofColor::red);
    for (std::vector<Bullet>::iterator it = b.begin() ; it != b.end(); ++it) {
        if(it->dead == false){
            it->Bullet.draw();
        }
    }
    ofSetColor(ofColor::black);
    for (std::vector<Asteroid>::iterator it = a.begin() ; it != a.end(); ++it) {
        if(it->dead == false){
            it->Asteroid.draw();
        }
    }

    cam.end();
    ofSetColor(ofColor::white);
    for (std::vector<Life>::iterator it = l.begin() ; it != l.end(); ++it) {
        it->x = ofGetWidth() -it->i+1*16;
        if(it->dead == false){
            it->Heart.draw(it->x,it->y);
        }
    }
    if(over == true){
        gover.draw(0,0);

    }else{
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 13 && over == true){
        over = false;
        life = 10;
        for(int i = 0; i<10; i++){
        Life var1;
        var1.i = i;
        var1.x = ofGetWidth() -i*16;
        var1.y = 0;
        var1.Heart.loadImage("Heart.jpg");
        var1.Heart.resize(16,16);
        l.push_back(var1);
    }
    }
    // if left key is pressed then make left true
    if(key == 356){
        left = true;
    }
    // if right key is pressed then make right true
    if(key == 358){
        right = true;
    }
    // if space key is pressed then make space true
    if(key == 32){
        space = true;
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    // if left key is pressed then make left false
    if(key == 356){
        left = false;
    }
    // if right key is pressed then make right false
    if(key == 358){
        right = false;
    }
    // if space key is pressed then make space false
    if(key == 32){
        space = false;
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
