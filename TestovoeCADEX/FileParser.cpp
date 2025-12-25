#include "FileParser.h"
#include <iostream>
#include <sstream>
#include "ShapeFactory.h"

std::vector<std::unique_ptr<Shape>> FileParser::parse(const std::string& filepath)
{
    std::vector<std::unique_ptr<Shape>> shapes;

    std::ifstream file(filepath);

    if (!file) {
        std::cout << "Can't open a file " << filepath << "\n";
        return std::vector<std::unique_ptr<Shape>>();


    }

    int shapeCount;

	file >> shapeCount;

    std::string line;

    for(int i = 0; i < shapeCount; i++)
	{
		std::getline(file, line);
        if (line.empty()) {
            i--;
            continue;
        }

        auto shape = parseLine(line);
        if (shape) {
			shapes.push_back(std::move(shape));
        }
	}








    return shapes;
}

std::unique_ptr<Shape> FileParser::parseLine(const std::string& line)
{
 

    std::istringstream  iss(line);
	char type;
	iss >> type;
 

    uint64_t id;
	iss >> id;

	std::string name;
    

	iss >> name;



    name = name.substr(1, name.length() - 2);
    



	double x, y, z;
	iss >> x >> y >> z;
    


    Vector3 center(x, y, z);

    std::vector<double> params;
	double param;
    while(iss >> param) {
		params.push_back(param);
	}
    return ShapeFactory::createShape(type, center, id, name, params);
}
