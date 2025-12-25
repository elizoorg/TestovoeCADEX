#pragma once
#include <variant>
#include <string>
#include "Vector3.h"

struct CircleParam {
	double radius;
};

struct EllipseParam {
	double radius1;
	double radius2;
};

struct HelixParam {
	double radius;
	double step;
};

class Shape
{
public:
	using Parameter = std::variant<CircleParam, EllipseParam, HelixParam>;


	Shape(Vector3 center, uint64_t ID, std::string name,Parameter param) : center(center), ID(ID), name(name),param_(std::move(param)) {}
	
	virtual ~Shape() = default;
	
	virtual Vector3 getPoint(double t) = 0;
	virtual Vector3 getDerivative(double t) = 0;
	std::string getName() { return name; }
	uint64_t getID() { return ID; }
	Vector3 getCenter() { return center; }
protected:
	Vector3 center;
	uint64_t ID;
	std::string name;
	Parameter param_;
};

