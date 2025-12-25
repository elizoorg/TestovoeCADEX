#include "Helix.h"

Vector3 Helix::getPoint(double t)
{
	auto param = std::get<HelixParam>(param_);
	double a = param.step;
	double r = param.radius;
	return Vector3(center.x + r * cos(t), center.y + r * sin(t), a*t);
}
Vector3 Helix::getDerivative(double t)
{
	auto param = std::get<HelixParam>(param_);
	double a = param.step;
	double r = param.radius;
	return Vector3(center.x - r * sin(t), center.y + r * cos(t), a);
}
