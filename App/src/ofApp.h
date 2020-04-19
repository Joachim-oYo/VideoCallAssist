#pragma once
#include "ofMain.h"
#include "ofxSpout.h"
#include "Button.h"
#include "AssetManager.h"
/*
ofxCsv - not useful
ofxEasing
ofxNetwork - not useful
ofxParagraph
ofxSmartFont
*/

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	// Camera and Spout
	ofVideoGrabber camera;
	ofxSpout::Sender sender;
	
	// Asset Manager
	AssetManager assets;
};
