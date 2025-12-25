

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Shape.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"
#include "FileParser.h"
#include <algorithm>
#include <iomanip>

#define M_PI 3.14159265358979323846
int main(int argc, char* argv[])
{
	std::string filepath;
	std::vector<std::unique_ptr<Shape>> shapes;
	std::vector<Circle*> circles;

    if(argc > 1)
	{
		filepath = argv[1];
	}
	
	shapes = FileParser::parse(filepath);
	for (auto& shape : shapes) {
		auto point = shape->getPoint(M_PI/4.0);
		auto derivative = shape->getDerivative(M_PI/4.0);
		std::cout <<"|" << std::setw(10) << shape->getID()
				  <<"|" << std::setw(20) << std::left << shape->getName() 
				  <<"|" << std::right << std::setw(35) << point.toString() 
				  <<"|" << std::setw(35) << derivative.toString() 
				  <<"|" << std::endl;
	}
	
	for (const auto& shape : shapes) {
		auto circle = dynamic_cast<Circle*>(shape.get());
		if(circle) {
			circles.push_back(circle);
		}
	}


	std::sort(circles.begin(), circles.end(), [](Circle* a, Circle* b) { return a->getRadius() < b->getRadius(); });

	std::cout << "Sorted circles:\n";

	for(auto& circle: circles) {
		std::cout <<circle->getID() << " "<< circle->getRadius() << std::endl;
	}

	std::cout << "Total radius:\n";

	double totalRadius = 0;
	for(auto& circle: circles) {
		totalRadius += circle->getRadius();
	}

	std::cout << totalRadius << std::endl;

}
