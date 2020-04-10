#pragma once

#include <iostream>
#include <memory>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <algorithm>

#include "Menu.h"
#include "CardiovascularTrainer.h"
#include "FreeWeightTrainer.h"
#include "ResistanceTrainer.h"
#include "Weights.h"

using std::vector;
using std::multimap;
using std::cin;
using std::istream;
using std::wstring;

class Gym
{
private:
	string name;
	Weights dumbbells{ "Гантели" };
	Weights plates{ "Диски" };
	multimap<int, std::shared_ptr<Trainer>> trainerList;

	void addCardioTrainer();
	void addResistanceTrainer();
	void addFreeWeightTrainer();
	void addDumbbell();
	void addPlate();

	void editCardioTrainer(std::shared_ptr<Trainer> pos);
	void editResistanceTrainer(std::shared_ptr<Trainer> pos);
	void editFreeWeightTrainer(std::shared_ptr<Trainer> pos);

	void removeDumbbell(int kg);
	void removePlate(int kg);

	wstring to_wstring(string const& str)
	{
		size_t len = mbstowcs(nullptr, &str[0], 0);
		if (len == -1); // invalid source str, throw
		wstring wstr(len, 0);
		mbstowcs(&wstr[0], &str[0], wstr.size());
		return wstr;
	}

public:
	Gym(string name = "IMPECCABLE PECS") : name(name) {}
	class TrainerListMenu : public Menu
	{
	private:
		Gym& g;
	public:
		TrainerListMenu(Gym& g);
		std::pair<int, int> build();
	};

	void setName(string name) { this->name = name; }
	string getName() { return name; }

	void addTrainer();
	void editTrainer();
	void removeTrainer();

	void createReport();
	void createXLSXReport();
	void printSingle();

	friend ostream& operator<<(ostream& out, Gym& p);
	friend istream& operator>>(istream& in, Gym& p);
};

ostream& operator<<(ostream& out, Gym& p);
istream& operator>>(istream& in, Gym& p);
