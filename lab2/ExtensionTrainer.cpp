#include "ExtensionTrainer.h"

ExtensionTrainer::ExtensionTrainer(string muscle, int weight, string manufact)
	: Trainer(manufact), muscleType(muscle)
{
	setMaxWeight(weight);
}

void ExtensionTrainer::printToConsole()
{
	cout << manufacturer << ' ' << muscleType << " Extension Trainer\n"
		<< "Max weight: " << maxWeight << "kg\n";
}
