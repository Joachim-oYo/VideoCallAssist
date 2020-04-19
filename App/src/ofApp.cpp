#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetWindowTitle("VideoCallAssist");
	ofSetFrameRate(60);

	//camera.initGrabber(640, 480);

	//// Initialise the Spout sender with a channel name
	//sender.init("VideoCallAssist");

	// Load all of the assets
	assets.load();
}

//--------------------------------------------------------------
void ofApp::update() {
	camera.update();

	// Send the camera's texture once per frame
	//sender.send(camera.getTexture());
}

//--------------------------------------------------------------
void ofApp::draw() {
	if (camera.isFrameNew()) {
		assets.activeButton.draw(0, 0);
		assets.inactiveButton.draw(0, assets.activeButton.getHeight());
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

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
