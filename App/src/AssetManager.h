#pragma once

#include "ofMain.h"

class AssetManager : public ofBaseApp {

public:
	// Methods
	void load();

	// Fonts

	// UI
	ofImage background;
	ofImage enabled;
	ofImage disabled;
	ofImage desktop;
	ofImage mobile;
	ofImage showVideoActive;
	ofImage showVideoInactive;
	ofImage unmuteActive;
	ofImage unmuteInactive;

	// Spout Cam
	ofImage target;

private:

};

