#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "Shape.h"

#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"

class FileParser
{
public:
	static std::vector<std::unique_ptr<Shape>> parse(const std::string& filepath);
	static std::unique_ptr<Shape> parseLine(const std::string& line);

};

