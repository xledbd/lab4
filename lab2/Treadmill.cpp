#include "Treadmill.h"

Treadmill::Treadmill(double s, double i, string manufact)
	: Trainer(manufact)
{
	setMaxIncline(i);
	setMaxSpeed(s);
}

void Treadmill::printToConsole()
{
	cout << std::setprecision(1) << std::fixed << manufacturer 
		<< " Treadmill:\n"
		<< "Max Speed: " << maxSpeed << " km/h\n"
		<< "Max Incline: " << maxIncline << " %\n";
}
