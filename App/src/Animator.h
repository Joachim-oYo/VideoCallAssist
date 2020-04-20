#pragma once

#include "ofMain.h"

class Animator : public ofBaseApp {

public:
	// Methods
	void setup(ofPoint position);
	void setup(string type, string state, int x, int y, ofImage imgA, ofImage imgB);
	string getState();
	string getType();
	bool wasHit(int x, int y);
	void press();
	void release();
	void draw();

	// State
	string buttonState;
	string buttonType;
	ofPoint buttonPosition;
	ofImage imageA;
	ofImage imageB;
	float hurtboxWidth;
	float hurtboxHeight;

	int count = 0;
	int duration = 240;

private:

};

