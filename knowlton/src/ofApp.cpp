#include "ofApp.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include <bits/stdc++.h>

//--------------------------------------------------------------
void ofApp::setup(){
	
	
	for(int i = 0; i<12; i++){
		ofImage pic;
		string loader = "pix/";
		loader.append(ofToString(i+1));
		loader.append(".png");
		pic.load(loader);
		pixes.push_back(pic);
	}
	
	ofBackground(255);
	
		camWidth = 640;
		camHeight = 480;
		
		vidGrabber.setVerbose(true);
		vidGrabber.setup(camWidth,camHeight);
	
	
}

//--------------------------------------------------------------
void ofApp::update(){
	vidGrabber.update();

}

//--------------------------------------------------------------
void ofApp::draw(){
	addBrightness = 20;
	
	ofClear(255,0);
	
	int resolution = 6;
	int tileSize = 12;

	string glyphs[] = {" ", "'","+","X", "Ø", "#"};
	int rotation[] = {0, 90, 180, 270};

	ofPixelsRef pixelsRef = vidGrabber.getPixels();

	ofSetColor(0);
	for(int i = 0; i< 640/resolution; i++){
		for(int j = 0; j<480/resolution; j++){
			int c = ofClamp(addBrightness + pixelsRef.getColor(ofMap(i,0,640/resolution,0,640),ofMap(j,0,480/resolution,0,480)).getLightness(),0,255);
			
			int cc = ofMap(c, 0, 255, 11,0);
			if(cc > 2 and cc < 5){
				pixes[cc].rotate90(static_cast<int>(ofRandom(0,4)));
			}
			else{}
			pixes[cc].draw(i*tileSize,j*tileSize,tileSize,tileSize);

		}
	}

}

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
