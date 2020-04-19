#include "Button.h"

void Button::setup(ofPoint position, ofImage activeImg, ofImage inactiveImg) {
	activeImage = activeImg;
	inactiveImage = inactiveImg;
}

void Button::setup(int x, int y, ofImage activeImg, ofImage inactiveImg) {
	setup(ofPoint(x, y), activeImg, inactiveImg);
}

void Button::press() {

}

void Button::release() {

}

void Button::draw() {

}