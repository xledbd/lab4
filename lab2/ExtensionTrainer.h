#pragma once
#include "Trainer.h"
class ExtensionTrainer :
	public Trainer
{
private:
	string muscleType{ "Tricep" };
	int maxWeight{ 150 };
public:
	ExtensionTrainer(string muscle, int weight = 150, string manufact = "Cybex");

	void setMaxWeight(int weight) { weight > 0 ? (maxWeight = weight) : (maxWeight = 150); }
	void setMuscleType(string muscle) { muscleType = muscle; }

	int getMaxWeight() { return maxWeight; }
	string getMusleType() { return muscleType; }

	void printToConsole() override;
};

