#pragma once
#include <exception>

class WeightNotFoundException : public std::exception
{
public:
	WeightNotFoundException(const char* what = "Weight not Found") : std::exception(what) {};
};

