#include "ofApp.h"
#pragma once
#include "math.h"
//--------------------------------------------------------------
void ofApp::setup(){
	int numLines = 16;

	for(int i = 0; i < numLines; i++) {
		ofPolyline trail;
		trails.push_back(trail);
	}
	for(int i = 0; i < numLines; i++) {
		ofPolyline trail;
		trailB.push_back(trail);
	}
	
	rgbaFbo.allocate(800, 800, GL_RGBA);
	rgbaFbo.begin();
	ofClear(255,255,255,0);

}

//--------------------------------------------------------------
void ofApp::update(){
	ofEnableAlphaBlending();

	//lets draw some graphics into our two fbos
	rgbaFbo.begin();
		drawFboTest();
	rgbaFbo.end();
}
//-------------------------------------------------------------
void ofApp::drawFboTest(){
	float time = ofGetElapsedTimef();
	string colors[] = {"361b74","287332", "093088", "287332", "99313c"};
	for (int i = 0; i < 5; i++){
		ofSetLineWidth(200);
//		ofSetLineSmoothing(true);
		ofSetCircleResolution(50);
		ofSetHexColor(ofHexToInt(colors[i]));
		float size = 300 * sin(0.2 * time + i*2);
		ofDrawCircle(400,400, size);
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);

	
	int center = ofGetWindowWidth()/2;
	float time = ofGetElapsedTimef();
	float radius = ofGetWindowWidth()/4;
	
	ofTranslate(center,center);
// color overlay
	
	ofSetColor(255);
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);

	for (int i = 0; i < 16; i++){
//		ofTranslate(center,center);
		ofRotateDeg(ofMap(i,0,16,0,360));
		float i_rad = ofMap(i,0,16,0, 2*M_PI);
		float radx = radius*cos(time*.7);
		float rady = radius*sin(1.3+time*0.3);
//		float x = center + radx * cos(time*0.2+i_rad);
//		float y = center - rady * sin(time*0.2+i_rad);
		
		ofDrawCircle(radx,rady,1);
		
		ofSetLineWidth(4);
		ofSetColor(100);
		
		trailB[i].addVertex(radx,rady);
		if (trailB[i].size() > 200){
			trailB[i].getVertices().erase(trailB[i].getVertices().begin());
		}
		trailB[i].draw();
		
		ofSetLineWidth(2);
		ofSetColor(255);
		
		trails[i].addVertex(radx,rady);
		if (trails[i].size() > 500){
			trails[i].getVertices().erase(trails[i].getVertices().begin());
		}
		trails[i].draw();
		

	}
	ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
	
	rgbaFbo.draw(-400,-400);
//	ofNoFill();

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
