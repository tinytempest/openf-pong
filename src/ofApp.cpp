// make
// make run

#include "ofApp.h"

#define RADIUS 5
#define FRAMERATE 30

#define POSITION_X_MIN_VALUE -1
#define POSITION_Y_MIN_VALUE 1

#define DELTA_POSITION_MIN_VALUE 15 // Delta is the velocity of the object, how many places does the object move from one point to the other.
#define DELTA_POSITION_MAX_VALUE 30

#define rectwidth 250
#define rectheight 50

//--------------------------------------------------------------
void ofApp::setup(){ // Comentario: setup es una funcion que hace que el circulo empiece en un lugar distinto cada vez que triggereo el programa.
    pos.x = ofRandom(POSITION_X_MIN_VALUE, ofGetWidth());
    pos.y = ofRandom(POSITION_Y_MIN_VALUE, ofGetHeight());
    delta_pos.x = ofRandom(DELTA_POSITION_MIN_VALUE, DELTA_POSITION_MAX_VALUE);
    delta_pos.y = ofRandom(DELTA_POSITION_MIN_VALUE, DELTA_POSITION_MAX_VALUE);
    
    //open the webcam
    grabber.setup(640, 480);

    posRect.x = 500;
    posRect.y = 500;
    delta_posRect.x = 0;
    delta_posRect.y = 0;
}

//--------------------------------------------------------------
void ofApp::update(){ // Actualiza en tiempo real, es un loop. Le da continuidad a la accion (se repite), en este caso le da repeat al valor de pos.x. 
    ofSetFrameRate(FRAMERATE);

    pos.x = pos.x + delta_pos.x;
    pos.y = pos.y + delta_pos.y;

    posRect.x = posRect.x + delta_posRect.x;
    
    if ( (pos.x > ofGetWidth()) || (pos.x < 0) ) { 
        delta_pos.x = (-1)*delta_pos.x;
    }

    if ( (pos.y > ofGetHeight()) || (pos.y < 0) ) {
        delta_pos.y = (-1)*delta_pos.y;
    }
   
    if ( (pos.x < posRect.x + rectwidth) && (pos.x > posRect.x) && (pos.y < posRect.y + rectheight) && (pos.y > posRect.y)) {
        boxHitCount++;
        cout << "Estoy golpeando de la caja (" << boxHitCount << ")" << endl;
        delta_pos.x = (-1)*delta_pos.x;
        delta_pos.y = (-1)*delta_pos.y;
    }

    grabber.update();
	if( grabber.isFrameNew() ){	
		// Get the ofPixels and convert to an ofxCvColorImage.
		auto pixels = grabber.getPixels();
		colorImg.setFromPixels(pixels);
	}
}

#define VISION false // Work in progress.

//--------------------------------------------------------------
void ofApp::draw(){
    if (VISION) {
        grabber.draw(0, 0);
    }
    ofSetColor(255);
    ofDrawCircle(pos.x, pos.y, RADIUS);
    ofDrawRectangle(posRect.x, posRect.y, rectwidth, rectheight);
}

//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == OF_KEY_LEFT)
    { 
        delta_posRect.x = delta_posRect.x - 8;
        cout << "Estoy cambiando la velocidad del rectangulo en el eje X."  << endl;
    }

    if (key == OF_KEY_RIGHT) {
        delta_posRect.x = delta_posRect.x + 8;
        cout << "Estoy cambiando la velocidad del rectangulo en el eje X."  << endl;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == OF_KEY_LEFT) 
    {
        delta_posRect.x = 0;
    }
    if (key == OF_KEY_RIGHT) {
        delta_posRect.x = 0;
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
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

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

//--------------------------------------------------------------
void ofApp::drawCross(int x, int y, int size){
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofDrawRectangle(x, y, size, size/10);
    ofDrawRectangle(x, y, size/10, size);
}