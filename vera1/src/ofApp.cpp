#include "ofApp.h"
#include <iostream>
//--------------------------------------------------------------
void ofApp::setup(){
	
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(187);
	ofNoFill();
	ofSetColor(0);
	int size = 130;
	int w = ofGetWindowWidth();
	ofSetRandomSeed(mouseX);
	//draws each slot on the grid
	for(int i=0 ; i<3 ; i++){
		for(int j=0;j<3;j++){
			ofSetLineWidth(4);
			int x = ofMap(i,0,2, 125, 410);
			int y = ofMap(j,0,2, 100, 410);
			for(int k = 0; k < 6; k++){
				//draws concentric squares
				ofSetRectMode(OF_RECTMODE_CENTER);
				ofRectangle myRect;
				myRect.x=x;
				myRect.y=y;
				myRect.width=(size-22*k);
				myRect.height=(size-22*k);
				ofDrawRectRounded(myRect,5);
			}
			//draws offset polygons
			ofSetLineWidth(5);
			ofSetRectMode(OF_RECTMODE_CORNER);
			// draws a mild curve instead of straight lines
			int bezierAmt = ofRandom(-30,30);
			
			int xtl = x-size/2 + ofRandom(-60,25);
			int ytl = y-size/2 + ofRandom(-50,50);
			// sets other points in curve: endpoint + midpoint
			int xtr = x+size/2 + ofRandom(-20,50);
			int ytr = y-size/2 + ofRandom(-20,50);
			
			int xbr = x+size/2 + ofRandom(-30,50);
			int ybr = y+size/2 + ofRandom(-20,50);
			
			int xbl = x-size/2 + ofRandom(-60,50);
			int ybl = y+size/2 + ofRandom(-20,60);

			//draws first line TL -> TR

			int xc = int((xtr+xtl)/2) + bezierAmt;
			int yc = int((ytr+ytl)/2) + bezierAmt;
			ofDrawCurve(xc, yc, xtl, ytl, xtr, ytr, xc, yc);
			//draws first line TR -> BR

			xc = int((xtr+xbr)/2) + bezierAmt;
			yc = int((ytr+ybr)/2) + bezierAmt;
			ofDrawCurve(xc, yc, xtr, ytr, xbr, ybr, xc, yc);
			//draws first line BR -> BL

			xc = int((xbr+xbl)/2) + bezierAmt;
			yc = int((ybr+ybl)/2) + bezierAmt;
			ofDrawCurve(xc, yc, xbr, ybr, xbl, ybl, xc, yc);
			//draws first line BL -> TL

			xc = int((xbl+xtl)/2) + bezierAmt;
			yc = int((ybl+ytl)/2) + bezierAmt;
			ofDrawCurve(xc, yc, xbl, ybl, xtl, ytl, xc, yc);
			
		}
	}
}
//			ofVertex(x-size/2 + ofRandom(-50,50), y-size/2 + ofRandom(-50,50));
//			ofVertex(x+size/2 + ofRandom(-50,50), y-size/2 + ofRandom(-50,50));
//			ofVertex(x+size/2 + ofRandom(-50,50), y+size/2 + ofRandom(-50,50));
//			ofVertex(x-size/2 + ofRandom(-50,50), y+size/2 + ofRandom(-50,50));
//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
