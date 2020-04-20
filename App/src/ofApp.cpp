#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetWindowTitle("VideoCallAssist");
	ofSetFrameRate(60);

	//camera.setup(640, 480);
	openCamera();

	// Initialize the Spout sender with a channel name
	spoutSender.init("VideoCallAssist");
	spoutFbo.allocate(1280, 720);

	// Load all of the assets
	assets.load();

	// Setup the buttons
	setupButtons();

}

//--------------------------------------------------------------
void ofApp::update() {
	// Update the texture that will be sent over Spout
	updateSpoutFbo();	
	spoutSender.send(spoutFbo.getTexture());
}

//--------------------------------------------------------------
void ofApp::draw() {
	// Draw Background
	assets.background.draw(0, 0);

	// Draw Buttons
	drawButtons();

	// Draw Spout Cam Preview
	spoutFbo.draw(ofGetWidth() - 1280/4 - 20, ofGetHeight() - 720/4 - 20, 1280/4, 720/4);
}

void ofApp::updateSpoutFbo() {
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
}

void ofApp::setupButtons() {
	// Sets up all of the buttons
	enableButton.setup("TOGGLE", "DISABLED", ofPoint(20, 77), assets.enabled, assets.disabled);
	desktopButton.setup("TOGGLE", "DESKTOP", ofPoint(20, 156), assets.desktop, assets.mobile);
	unmuteButton.setup("LATCHED", "OFF", ofPoint(20, 233), assets.unmuteInactive, assets.unmuteActive);
	showVideoButton.setup("LATCHED", "OFF", ofPoint(131, 233), assets.showVideoInactive, assets.showVideoActive);
}

void ofApp::drawButtons() {
	// Draws all of the buttons at their initialized positions
	enableButton.draw();
	desktopButton.draw();
	unmuteButton.draw();
	showVideoButton.draw();
}

void ofApp::openCamera() {
	// open camera
	if (camera.setup(1280, 720))
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
	// open or close the camera with the spacebar
	if (key == 32) {
		if (isCameraOpen) {
			closeCamera();
		}
		else {
			openCamera();
		}
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
