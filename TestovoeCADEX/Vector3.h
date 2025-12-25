#pragma once
#include <iostream>


std::string formatDouble(double value, int precision = 6);

struct Vector3
{
	double x, y, z;
	Vector3(double x, double y, double z) : x(x), y(y), z(z) {};

	friend std::ostream& operator << (std::ostream& out, const Vector3& v);

	std::string toString(int precision = 6) const;
};

