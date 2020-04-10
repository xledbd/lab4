#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

#include "WeightNotFound.h"

using std::ostream;
using std::istream;
using std::map;
using std::string;

class Gym;

class Weights
{
	friend class Gym;
	friend ostream& operator<<(ostream& out, Gym& p);
private:
	string type;
	map<int, int> weights;
public:
	Weights(string type = "Plates");
	inline void addWeight(int kg) {
		if (kg > 0)
		{
			weights[kg] += 1;
		}
		else throw std::domain_error("Value can't be negative");
	}
	void removeWeight(int kg);

	void print();
	friend ostream& operator<<(ostream& out , Weights& w);
	friend istream& operator>>(istream& in, Weights& p);

};

ostream& operator<<(ostream& out, Weights& w);
istream& operator>>(istream& in, Weights& p);
