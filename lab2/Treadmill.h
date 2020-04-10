#pragma once
#include "Trainer.h"
class Treadmill :
	public Trainer
{
private:
	double maxSpeed;
	double maxIncline;
public:
	Treadmill(double s = 12.0, double i = 9.0, string manufact = "Cybex");

	void setMaxSpeed(double speed) { speed > 0 ? (maxSpeed = speed) : (maxSpeed = 12.0); }
	void setMaxIncline(double incline) { incline > 0 ? (maxIncline = incline) : (maxIncline = 12.0); }

	double getMaxSpeed() { return maxSpeed; }
	double getMaxIncline() { return maxIncline; }

	void printToConsole() override;
};

