#pragma once
#include "Trainer.h"
class FreeWeightTrainer :
	public Trainer
{
private:
	string muscleType{ "Abs" };
	void printToStream(ostream& out) override;
public:
	FreeWeightTrainer(string muscle, string type, string manufacturer = "Cybex");

	void setMuscleType(string muscle) { muscleType = muscle; }
	string getMuscleType() { return muscleType; }

	void printToConsole() override;

	friend ostream& operator<<(ostream& out, FreeWeightTrainer& p);
	friend istream& operator>>(istream& in, FreeWeightTrainer& p);
};

ostream& operator<<(ostream& out, FreeWeightTrainer& p);
istream& operator>>(istream& in, FreeWeightTrainer& p);
