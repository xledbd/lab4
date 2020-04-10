#include "ResistanceTrainer.h"

void ResistanceTrainer::printToStream(ostream& out)
{
	out << "1\n";
	out << *this;
}

ResistanceTrainer::ResistanceTrainer(string muscle, int weight, string type, string manufact)
	: Trainer(type, manufact), muscleType(muscle)
{
	setMaxWeight(weight);
}

void ResistanceTrainer::printToConsole()
{
	cout << "������������ ��������\n"
		<< "�������������: " << manufacturer << '\n'
		<< "��� ���������: " << trainerType << "\n"
		<< "������ ����: " << muscleType << "\n"
		<< "������������ ������� ���: " << maxWeight << "kg\n";
}

ostream& operator<<(ostream& out, ResistanceTrainer& p)
{
	out << p.muscleType << '\n'
		<< p.maxWeight << '\n'
		<< p.trainerType << '\n'
		<< p.manufacturer;
	return out;
}

istream& operator>>(istream& in, ResistanceTrainer& p)
{
	in >> std::ws;
	std::getline(in, p.muscleType);
	in >> p.maxWeight;
	in >> std::ws;
	std::getline(in, p.trainerType);
	std::getline(in, p.manufacturer);
	return in;
}
