#pragma once
#include "Vector3.h"
#include "Shape.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"
#include <vector>
#include <iostream>
class ShapeFactory
{
public: 

	static bool isValidName(const std::string& name) {
		for (char c : name) {
			if (!(std::isalnum(c) || c == '_')) {
				return false;
			}
		}
		return !name.empty();
	}

	static std::unique_ptr<Shape> createShape(char type, Vector3 center, uint64_t ID, std::string name, std::vector<double> params) {
		
		if(!isValidName(name)) {
			#ifdef _DEBUG
			std::cout << "Found a wrong name of shape with ID: " << ID << "\n";
			#endif
			return nullptr;
		}

		switch (type) {
		case 'C': 
			if (params[0] < 0) {
				#ifdef _DEBUG
				std::cout << "Found a wrong radius of circle with ID: " << ID << "\n";
				#endif

				
				return nullptr;
			}
			return std::make_unique<Circle>(center, ID, name, params[0]);
		case 'E': 
			if (params[0] < 0 || params[1] < 0) {
				#ifdef _DEBUG
				std::cout << "Found a wrong radiuses of ellipse with ID: " << ID << "\n";
				#endif

				return nullptr;
			}
			return std::make_unique <Ellipse>(center, ID, name, params[0], params[1]);
		case 'H':
			if (params[0] < 0 || params[1] < 0)
			{
				#ifdef _DEBUG
				std::cout << "Found a wrong radius or step of helix with ID: " << ID << "\n";
				#endif

				return nullptr;
			}
			return std::make_unique <Helix>(center, ID, name, params[0], params[1]);
		default: 
			std::cout << "Found a wrong type of shape\n";
			return nullptr;
		}
	

	}


};

