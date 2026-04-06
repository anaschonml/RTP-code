#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	grabber.setVerbose(true);

	grabber.setup(640,480);
	
//	change.allocate(grabber.getWidth(),grabber.getHeight(),OF_IMAGE_COLOR);

	grayDiff.allocate(640,480);
	
	tshImage.allocate(640,480,OF_IMAGE_COLOR_ALPHA);

	threshold = 200;


}

//--------------------------------------------------------------
void ofApp::update(){
	grabber.update();
	
	if (grabber.isFrameNew()){
//		colorImg.setFromPixels(grabber.getPixels());
//		grayImage = colorImg;
		for (int i = 0; i < grabber.getWidth();i++){
			for (int j = 0; j < grabber.getHeight(); j++){
				ofColor clr = grabber.getPixels().getColor(i,j);
				if (clr.getBrightness() > mouseX){
					ofColor transparent;
					transparent = 0;
					transparent.a = 0;
					tshImage.setColor(i,j,transparent);
					
				}
				else{
					tshImage.setColor(i,j,255);
				}
			}
		}
		

		// find contours which are between the size of 20 pixels and 1/3 the w*h pixels.
		// also, find holes is set to true so we will get interior contours as well....
		grayDiff = tshImage;
//		contourFinder.findContours(grayDiff, 20, (340*240)/3, 10, true);
	}
	
	tshImage.update();
	if (ofGetFrameNum() % 20 == 0) {
		// Add new frame to the front
		trails.insert(trails.begin(), tshImage);

		// If we exceed 10, remove the last one
		if (trails.size() > 10) {
			trails.pop_back();
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofClear(0,0);
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	for (int t = 0; t < trails.size(); t++){
		float mapped = ofMap(t, 0, (float)trails.size(), 0.0f, 255.0f, true);
		int hue = static_cast<int>(mapped) % 255;
		ofColor hueCol = ofColor::fromHsb(hue, 190, 255);
		ofSetColor(hueCol);
		trails[trails.size()-1 - t].draw(0,0);
	}
	ofSetColor(255,255,255,50);
	tshImage.draw(0,0);

	

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
