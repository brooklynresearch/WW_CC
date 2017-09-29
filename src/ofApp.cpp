#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    interrupted = false;
    commandChar = ' ';
    
    defaultMovie.load("movies/default.MOV");
    defaultMovie.setLoopState(OF_LOOP_NORMAL);
    defaultMovie.play();
    interruptMovie.load("movies/interrupt.MOV");
    interruptMovie.play();
    interruptMovie.setPaused(true);
    interruptMovie.setLoopState(OF_LOOP_NONE);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if(interrupted){
        if(interruptMovie.getIsMovieDone()){
            interrupted = false;
            defaultMovie.setPaused(false);
            interruptMovie.setPaused(true);
            interruptMovie.firstFrame();
            
//            interruptMovie.stop();
//            defaultMovie.play();
            
        }
        else {
            interruptMovie.update();
        }
    }
    else{
        defaultMovie.update();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if(interrupted){
        interruptMovie.draw(0,0);
    }
    else{
        defaultMovie.draw(0,0);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if(key == commandChar){
        interrupted = true;
        defaultMovie.setPaused(true);
        interruptMovie.setPaused(false);
//        defaultMovie.stop();
//        interruptMovie.play();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
