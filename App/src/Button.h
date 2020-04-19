#pragma once

#include "ofMain.h"

class Button : public ofBaseApp {

public:
	// Methods
	void setup(ofPoint position, ofImage activeImg, ofImage inactiveImg);
	void setup(int x, int y, ofImage activeImg, ofImage inactiveImg);
	void press();
	void release();
	void draw();

	// State
	bool isPressed;
	ofPoint position;
	ofImage activeImage;
	ofImage inactiveImage;

private:

};

