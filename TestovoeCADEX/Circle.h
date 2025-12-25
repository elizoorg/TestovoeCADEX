#pragma once
#include "Shape.h"
#include "Vector3.h"
class Circle : public Shape
{
	public:
	Circle(Vector3 center, uint64_t ID, std::string name, double r) :Shape(center, ID, name, CircleParam{r}) {};

	Vector3 getPoint(double t) override;
	Vector3 getDerivative(double t) override;

	double getRadius() { auto param = std::get<CircleParam>(param_); return param.radius; }

};

