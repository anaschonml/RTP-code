#include "ofApp.h"
#include "stdio.h"
//#include "/Users/anaschon/Documents/of_v0.12.1_osx_release/addons/ofxShadertoy-master/src/ofxShadertoy.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(255);
	font.load("Arial Black",100);
	paper.load("images/canvas.jpeg");
	
	ofDisableArbTex();
	
	if(ofIsGLProgrammableRenderer()){
		shaderBlurX.load("shadersGL3/shaderBlurX");
		shaderBlurY.load("shadersGL3/shaderBlurY");
		shader.load("shadersGL3/shader");
	}else{
		shaderBlurX.load("shadersGL2/shaderBlurX");
		shaderBlurY.load("shadersGL2/shaderBlurY");
		shader.load("shadersGL2/shader");
	}
	fboBlurOnePass.allocate(800,800);
	fboBlurTwoPass.allocate(800,800);
	maskTex.allocate(800,800);
	unblur.allocate(800,800);
	
	
}

//--------------------------------------------------------------
void ofApp::update(){
	// generate noise map
	maskTex.begin();
	ofClear(0, 0, 0, 0);

	for (int i = 0; i<80;i++){
		for(int j = 0; j<80;j++){
			ofSetColor(0,0,0,(255-ofNoise(i*0.06,j*0.06)*255));
			ofDrawRectangle(10*i, 10*j, 10, 10);
		}
	}
	maskTex.end();
	
	//generate text
	unblur.begin();
	ofClear(0, 0, 0, 0);

	ofColor c[] = {{246,188,54,},{243,127,51},{193,45,40},{191,43,51},{219,54,92},{115,61,131},{60,65,123},{47,65,137},{45,76,147},{0,67,31},{24,100,56},};

	string line1 = "MITMEDIALAB";
	int w1 = 100;
	int w2 = 0;
	int w3 = 0;
	int height = 400;
	int w = 0;
	string letter = "";
	
	for(int i = 0; i < line1.size(); i++){
		
		ofSetColor(c[i]);
		if (i<3){
			height = 200;
			w1 += font.stringWidth(letter);
//			ofLog(OF_LOG_NOTICE,"W1= " + ofToString(w1));
			w = w1;
		}
		else if (i>=3 and i < 8){
			height = 400;
			w2 += font.stringWidth(letter);
//			ofLog(OF_LOG_NOTICE,"W2= " + ofToString(w2));
			w = w2;
		}
		else{
			height = 600;
			w3 += font.stringWidth(letter);
//			ofLog(OF_LOG_NOTICE,"W3= " + ofToString(w3));
			w = w3;
		}
		letter = std::string(1,line1[i]);
		
			font.drawString(letter,w,height);

	}
	unblur.end();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);

	//draw unblurred text
	ofSetColor(255, 255, 255, 200); // 50% alpha
	unblur.draw(0,0);
	ofSetColor(255,255,255,255);
//	maskTex.draw(0,0);
	float blur = 20;
	//----------------------------------------------------------
	//blur text, pass 1
	fboBlurOnePass.begin();
	ofClear(0, 0, 0, 0);


	shaderBlurX.begin();
	shaderBlurX.setUniform1f("blurAmnt", blur);
	shaderBlurX.setUniform1f("texwidth", 800);

	unblur.draw(0,0);
	fboBlurOnePass.end();
	
//	fboBlurOnePass.draw(0,0);

	shaderBlurX.end();

	
	//----------------------------------------------------------
	//blur text, pass 2
	fboBlurTwoPass.begin();
	ofClear(0, 0, 0, 0);

	
	shaderBlurY.begin();
	shaderBlurY.setUniform1f("blurAmnt", blur);
	shaderBlurY.setUniform1f("texheight", 800);
	
	fboBlurOnePass.draw(0, 0);
	fboBlurOnePass.draw(0, 0);
	fboBlurOnePass.draw(0, 0);
	
	shaderBlurY.end();
	fboBlurTwoPass.end();
	
	//mask with noise texture
	shader.begin();
	shader.setUniformTexture("imageMask", maskTex.getTexture(), 1);
	shader.setUniform2f("resolution", 800,800);
	ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
	fboBlurTwoPass.draw(0,0);
	fboBlurTwoPass.draw(0,0);


	shader.end();
//	ofSetColor(255,255,255,40);
	//add image overlay for paper texture
	ofEnableBlendMode(OF_BLENDMODE_SCREEN);
	paper.draw(0,0,600,400);
	paper.draw(600,0,600,400);
	paper.draw(0,400,600,400);
	paper.draw(600,400,600,400);
//
//	
//	//----------------------------------------------------------
//	fboBlurTwoPass.draw(0, 0);
	
	
//		ofDrawCircle(ofMap(i,0,sizeof(c)/sizeof(c[0]),50,750),400, 30);
//
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
