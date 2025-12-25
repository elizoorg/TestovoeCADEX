#include "Circle.h"
#include <cmath>

Vector3 Circle::getPoint(double t)
{
	auto param = std::get<CircleParam>(param_);
	double r = param.radius;
	return Vector3(center.x + r*cos(t),center.y + r*sin(t), center.z);
}

Vector3 Circle::getDerivative(double t)
{
	auto param = std::get<CircleParam>(param_);
	double r = param.radius;
	return Vector3(center.x - r * sin(t), center.y + r * cos(t), center.z);
}
