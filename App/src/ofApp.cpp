#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetWindowTitle("VideoCallAssist");
	ofSetFrameRate(60);

	//camera.setup(640, 480);
	openCamera();

	// Initialise the Spout sender with a channel name
	sender.init("VideoCallAssist");
	spoutFbo.allocate(640, 480);

	// Load all of the assets
	assets.load();
}

//--------------------------------------------------------------
void ofApp::update() {
	// Send the camera's texture once per frame
	spoutFbo.begin();
	if (isCameraOpen) {
		camera.update();
		if (camera.isInitialized())
			camera.draw(0, 0);
		ofPushStyle();
		assets.target.draw(25, 175);
		ofPopStyle();
	}
	else {
		ofPushStyle();
		ofClear(0, 0, 0, 0);
		assets.target.draw(25, 175);
		ofPopStyle();
	}
	spoutFbo.end();
	sender.send(spoutFbo.getTexture());
}

//--------------------------------------------------------------
void ofApp::draw() {
	spoutFbo.draw(0, 0, 320, 240);
}

void ofApp::openCamera() {
	// open camera
	if (camera.setup(640, 480))
		isCameraOpen = true;
	else 
		cout << "camera is busy" << endl;
}

void ofApp::closeCamera() {
	// close camera
	camera.close();
	isCameraOpen = false;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (isCameraOpen) {
		closeCamera();
	}
	else {
		openCamera();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
