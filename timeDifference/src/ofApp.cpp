#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	grabber.setup(640,480);
	img.allocate(640,480,OF_IMAGE_COLOR);
	fbo.allocate(640,480);
	frame.allocate(640,480,OF_IMAGE_COLOR);

}

//--------------------------------------------------------------
void ofApp::update(){
    // Update camera
    grabber.update();
	

    // If we have a new frame, store a copy in the images buffer
    if (grabber.isFrameNew()){
		
		
		frame.setFromPixels(grabber.getPixels());
		for (int d = 0; d < 6; d++){
			frame.resize(grabber.getWidth()+ofRandom(-200,200),grabber.getHeight()+ofRandom(-200,200));
			frame.resize(grabber.getWidth()+ofRandom(-200,200),grabber.getHeight()+ofRandom(-200,200));
			frame.save("frame.jpg",OF_IMAGE_QUALITY_LOW);
			frame.load("frame.jpg");
			frame.resize(grabber.getWidth(),grabber.getHeight());
		}
        images.push_back(img);
//        images.back().setUseTexture(false);
        images.back().setFromPixels(grabber.getPixels());
    }

    // Keep only the most recent 20 frames
    if (images.size() > 90){
        images.erase(images.begin());
    }

    // Render all buffered images into the FBO
    fbo.begin();
    ofClear(0, 0, 0, 0); // clear FBO each frame (transparent background)

    // Optional: set blend mode for compositing
    ofEnableBlendMode(OF_BLENDMODE_MAX);

    // Draw all images at the same position for cumulative blending
    for (int i = 0; i < images.size(); ++i){
        if (images[i].isAllocated()){
            // Optionally adjust alpha if you want softer accumulation, e.g. ofSetColor(255, 255, 255, 255);
            images[i].draw(ofRandom(-10,10), 0);
        }
    }

    ofDisableBlendMode();
    fbo.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofClear(0,0);
	ofSetColor(255);
	ofEnableBlendMode(OF_BLENDMODE_SCREEN);

//	grabber.draw(0,0);
	frame.draw(0,0);
	
	ofSetColor(255,255,255,200);
	ofEnableBlendMode(OF_BLENDMODE_SUBTRACT);

	fbo.draw(0,0);
//	
	

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

