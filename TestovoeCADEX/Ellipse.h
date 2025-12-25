#pragma once
#include "Shape.h"
class Ellipse : public Shape
{ 
	public:
	Ellipse(Vector3 center, uint64_t ID, std::string name, double r1, double r2) :Shape(center, ID, name, EllipseParam{ r1, r2 }) {};

	Vector3 getPoint(double t) override;
	Vector3 getDerivative(double t) override;
};
