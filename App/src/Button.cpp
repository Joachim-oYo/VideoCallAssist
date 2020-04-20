#include "Button.h"

void Button::setup(string type, string state, ofPoint position, ofImage imgA, ofImage imgB) {
	imageA = imgA;
	imageB = imgB;
	buttonType = type;
	buttonState = state;
	buttonPosition = position;

	hurtboxWidth = imgA.getWidth();
	hurtboxHeight = imgA.getHeight();
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

bool Button::wasHit(int x, int y) {
	bool hit = (((x - buttonPosition.x) <= hurtboxWidth && (x - buttonPosition.x) >= 0) && ((y - buttonPosition.y) <= hurtboxHeight && (y - buttonPosition.y) >= 0));
	return hit;
}

void Button::press() {
	if (buttonState == "ENABLED")
		buttonState = "DISABLED";
	else if (buttonState == "DISABLED")
		buttonState = "ENABLED";
	else if (buttonState == "DESKTOP")
		buttonState = "MOBILE";
	else if (buttonState == "MOBILE")
		buttonState = "DESKTOP";
	else if (buttonState == "OFF")
		buttonState = "ON";
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