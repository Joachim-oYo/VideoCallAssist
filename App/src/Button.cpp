#include "Button.h"

void Button::setup(string type, string state, ofPoint position, ofImage imgA, ofImage imgB) {
	imageA = imgA;
	imageB = imgB;
	buttonType = type;
	buttonState = state;
	buttonPosition = position;
}

void Button::setup(string type, string state, int x, int y, ofImage activeImg, ofImage inactiveImg) {
	setup(type, state, ofPoint(x, y), activeImg, inactiveImg);
}

string Button::getState() {
	return buttonState;
}

string Button::getType() {
	return buttonType;
}

void Button::press() {
	//if (buttonState == "ENABLED")
}

void Button::release() {

}

void Button::draw() {
	// Draw the button with the correct image based on its state
	if (buttonState == "ENABLED")
		imageA.draw(buttonPosition);
	else if (buttonState == "DISABLED")
		imageB.draw(buttonPosition);
	else if (buttonState == "DESKTOP")
		imageA.draw(buttonPosition);
	else if (buttonState == "MOBILE")
		imageB.draw(buttonPosition);
	else if (buttonState == "OFF")
		imageA.draw(buttonPosition);
	else if (buttonState == "ON")
		imageB.draw(buttonPosition);

}