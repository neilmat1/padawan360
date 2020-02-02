#include "R2Servo.h"

R2Servo::R2Servo() {
	this->isOpen = false;
	this->dirty = false;
	this->servoMax = 450;
	this->servoMin = 100;
	this->pwmBoard = NULL;
	this->pwmChannel = -1;
}

void R2Servo::setup(int servoMax, int servoMin, int pwmChannel, Adafruit_PWMServoDriver* pwmBoard) {
	this->servoMax = servoMax;
	this->servoMin = servoMin;
	this->pwmChannel = pwmChannel;
	this->pwmBoard = pwmBoard;
}

void R2Servo::setup(int pwmChannel, Adafruit_PWMServoDriver* pwmBoard) {
	this->pwmChannel = pwmChannel;
	this->pwmBoard = pwmBoard;
}

void R2Servo::close() {
	Serial.println("closing Servo on channel " + String(this->pwmChannel));
	this->isOpen = false;
	this->dirty = true;
}

void R2Servo::open() {
	Serial.println("opening Servo on channel " + String(this->pwmChannel));
	this->isOpen = true;
	this->dirty = true;
}

void R2Servo::toggle() {
	Serial.println("toggling Servo on channel " + String(this->pwmChannel));
	this->isOpen = !isOpen;
	this->dirty = true;
}

void R2Servo::update() {
	if (dirty) {
		Serial.println("updating Servo on channel " + String(this->pwmChannel));
		if (isOpen) {
			pwmBoard->setPWM(pwmChannel, 0, servoMax);
		}
		else {
			pwmBoard->setPWM(pwmChannel, 0, servoMin);
		}
		dirty = false;
	}
}
