#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	#ifdef OF_TARGET_OPENGLES
		ofGLESWindowSettings settings;
		settings.glesVersion=2;
	#else
		ofGLWindowSettings settings;
		settings.setGLVersion(3,2);
	#endif


	//Use ofGLFWWindowSettings for more options like multi-monitor fullscreen
	settings.setSize(800, 800);
	settings.windowMode = OF_WINDOW; //can also be OF_FULLSCREEN
	

	auto window = ofCreateWindow(settings);

	ofRunApp(window, std::make_shared<ofApp>());
	ofRunMainLoop();

}
