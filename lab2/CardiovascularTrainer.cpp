#include "CardiovascularTrainer.h"

void CardiovascularTrainer::printToStream(ostream& out)
{
	out << "3\n";
	out << *this;
}

CardiovascularTrainer::CardiovascularTrainer(double s, double i, string type, string manufact)
	: Trainer(type, manufact)
{
	setMaxIncline(i);
	setMaxSpeed(s);
}

void CardiovascularTrainer::printToConsole()
{
	cout << std::setprecision(1) << std::fixed
		<< "Кардиотренажер \n"
		<< "Производитель: " << manufacturer << '\n'
		<< "Тип тренажера: " << trainerType << "\n"
		<< "Макс скорость: " << maxSpeed << " km/h\n"
		<< "Макс уклон: " << maxIncline << " %\n";
}

ostream& operator<<(ostream& out, CardiovascularTrainer& p)
{
	out << p.maxSpeed << '\n'
		<< p.maxIncline << '\n'
		<< p.trainerType << '\n'
		<< p.manufacturer;
	return out;
}

istream& operator>>(istream& in, CardiovascularTrainer& p)
{
	in >> p.maxSpeed
		>> p.maxIncline;
	in >> std::ws;
	std::getline(in, p.trainerType);
	std::getline(in, p.manufacturer);
	return in;
}
