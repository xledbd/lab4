#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <typeinfo>
#include "libxl.h"

using std::string;
using std::cout;
using std::ostream;
using std::istream;
using namespace libxl;

class Trainer
{
protected:
	string manufacturer;
	string trainerType;
	virtual void printToStream(ostream& out) = 0;

public:
	Trainer(string type, string man = "Cybex") : trainerType(type), manufacturer(man) {}
	void setManufacturer(string manf) { manufacturer = manf; }
	void setTrainerType(string type) { trainerType = type; }

	string getManufacturer() { return manufacturer; }
	string getTrainerType() { return trainerType; }
	virtual void printToConsole() = 0;

	friend ostream& operator<<(ostream& out, Trainer& p);
};

ostream& operator<<(ostream& out, Trainer& p);