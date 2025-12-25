#include "Ellipse.h"

Vector3 Ellipse::getPoint(double t)
{
	auto param = std::get<EllipseParam>(param_);
	double a = param.radius1;
	double b = param.radius2;
	return Vector3(center.x + a * cos(t), center.y + b * sin(t), center.z);
}

Vector3 Ellipse::getDerivative(double t)
{
	auto param = std::get<EllipseParam>(param_);
	double a = param.radius1;
	double b = param.radius2;
	return Vector3(center.x - a * sin(t), center.y + b * cos(t), center.z);
}
