#include "Weights.h"

Weights::Weights(string type)
	:type(type)
{
}

void Weights::removeWeight(int kg)
{
	auto a = weights.find(kg);
	if (a == weights.end())
	{
		throw WeightNotFoundException();
	}
	else
	{
		if (a->second > 1) --(a->second);
		else weights.erase(a);
	}
}

void Weights::print()
{
	std::cout << type << '\n';
	std::for_each(weights.begin(), weights.end(), [&](std::pair<const int, int>& p) {std::cout << p.first << "кг, кол-во: " << p.second << '\n'; });

}

ostream& operator<<(ostream& out, Weights& w)
{
	out << w.weights.size() << '\n';
	std::for_each(w.weights.begin(), w.weights.end(), [&out](std::pair<const int, int>& p) {out << p.first << ' ' << p.second << '\n'; });
	out << w.type;
	return out;
}

istream& operator>>(istream& in, Weights& p)
{
	int n;
	std::pair<int, int> a;
	in >> n;
	for (size_t i = 0; i < n; i++)
	{
		in >> a.first >> a.second;
		p.weights[a.first] = a.second;
	}
	in >> std::ws;
	std::getline(in, p.type);
	return in;
}
