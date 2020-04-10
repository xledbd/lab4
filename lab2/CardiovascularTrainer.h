#pragma once
#include "Trainer.h"

class CardiovascularTrainer :
	public Trainer
{
private:
	double maxSpeed;
	double maxIncline;
	void printToStream(ostream& out) override;
public:
	CardiovascularTrainer(double s = 12.0, double i = 9.0, string type = "Treadmill", string manufact = "Cybex");

	void setMaxSpeed(double speed) { speed > 0 ? (maxSpeed = speed) : (maxSpeed = 12.0); }
	void setMaxIncline(double incline) { incline > 0 ? (maxIncline = incline) : (maxIncline = 12.0); }

	double getMaxSpeed() { return maxSpeed; }
	double getMaxIncline() { return maxIncline; }

	void printToConsole() override;
	friend ostream& operator<<(ostream& out, CardiovascularTrainer& p);
	friend istream& operator>>(istream& in, CardiovascularTrainer& p);

};

ostream& operator<<(ostream& out, CardiovascularTrainer& p);
istream& operator>>(istream& in, CardiovascularTrainer& p);
