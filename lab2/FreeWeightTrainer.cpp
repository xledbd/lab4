#include "FreeWeightTrainer.h"

void FreeWeightTrainer::printToStream(ostream& out)
{
	out << "2\n";
	out << *this;
}

FreeWeightTrainer::FreeWeightTrainer(string muscle, string type, string manufacturer)
	: Trainer(type, manufacturer)
{
	setMuscleType(muscle);
}

void FreeWeightTrainer::printToConsole()
{
	cout << "Тренажер со свободными весами\n"
		<< "Производитель: " << manufacturer << '\n'
		<< "Тип тренажера: " << trainerType << "\n"
		<< "Группа мышц: " << muscleType << "\n";
}

ostream& operator<<(ostream& out, FreeWeightTrainer& p)
{
	out << p.muscleType << '\n'
		<< p.trainerType << '\n'
		<< p.manufacturer;
	return out;
}

istream& operator>>(istream& in, FreeWeightTrainer& p)
{
	in >> std::ws;
	std::getline(in, p.muscleType);
	std::getline(in, p.trainerType);
	std::getline(in, p.manufacturer);
	return in;
}
