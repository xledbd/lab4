#pragma once
#include "Trainer.h"
class ResistanceTrainer :
	public Trainer
{
private:
	string muscleType{ "Tricep" };
	int maxWeight{ 150 };
	void printToStream(ostream& out) override;
public:
	ResistanceTrainer(string muscle, int weight = 150, string type = "Curl", string manufact = "Cybex");

	void setMaxWeight(int weight) { weight > 0 ? (maxWeight = weight) : (maxWeight = 150); }
	void setMuscleType(string muscle) { muscleType = muscle; }

	int getMaxWeight() { return maxWeight; }
	string getMuscleType() { return muscleType; }

	void printToConsole() override;
	friend ostream& operator<<(ostream& out, ResistanceTrainer& p);
	friend istream& operator>>(istream& in, ResistanceTrainer& p);

};

ostream& operator<<(ostream& out, ResistanceTrainer& p);
istream& operator>>(istream& in, ResistanceTrainer& p);
