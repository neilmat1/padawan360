#ifndef R2_SERVO_H
#define R2_SERVO_H

#include <Adafruit_PWMServoDriver.h>

class R2Servo {
public:
	R2Servo();
	void setup(int servoMax, int servoMin, int pwmChannel, Adafruit_PWMServoDriver* pwmBoard);
	void setup(int pwmChannel, Adafruit_PWMServoDriver* pwmBoard);
	void close();
	void open();
	void toggle();
	void update();

private:
	bool isOpen;
	bool dirty;

	int servoMax;
	int servoMin;

	int pwmChannel;
	Adafruit_PWMServoDriver* pwmBoard;
};

#endif
