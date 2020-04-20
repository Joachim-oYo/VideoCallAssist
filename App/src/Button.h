#pragma once

#include "ofMain.h"

class Button : public ofBaseApp {

public:
	// Methods
	void setup(string type, string state, ofPoint position, ofImage imgA, ofImage imgB);
	void setup(string type, string state, int x, int y, ofImage imgA, ofImage imgB);
	string getState();
	string getType();
	void press();
	void release();
	void draw();

	// State
	string buttonState;
	string buttonType;
	ofPoint buttonPosition;
	ofImage imageA;
	ofImage imageB;

private:

};

