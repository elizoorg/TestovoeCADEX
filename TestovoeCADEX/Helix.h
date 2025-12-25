#pragma once
#include "Shape.h"
class Helix: public Shape
{
public:
	Helix(Vector3 center, uint64_t ID, std::string name,double r, double step) :Shape(center, ID, name, HelixParam{ r, step }) {};

	Vector3 getPoint(double t) override;
	Vector3 getDerivative(double t) override;
};

