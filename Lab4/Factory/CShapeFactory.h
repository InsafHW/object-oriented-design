#pragma once
#include "IShapeFactory.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "CEllipse.h"
#include "CRegularPolygon.h"
#include "Color.h"
#include <vector>

const std::string RECTANGLE = "rectangle";
const std::string TRIANGLE = "triangle";
const std::string ELLIPSE = "ellipse";
const std::string POLYGON = "polygon";

const std::string GREEN = "green";
const std::string RED = "red";
const std::string BLUE = "blue";
const std::string YELLOW = "yellow";
const std::string PINK = "pink";
const std::string BLACK = "black";

class CShapeFactory: public IShapeFactory
{
public:
	std::unique_ptr<IShape> CreateShape(std::string description) const override
	{
		auto params = GetParams(description);

		if (params.size() < 2)
		{
			throw std::invalid_argument("Invalid input");
		}

		const auto type = params[0];
		const auto color = GetColor(params[1]);

		if (type == RECTANGLE)
		{
			if (params.size() < 6)
			{
				throw std::invalid_argument("Invalid input");
			}
			return std::make_unique<CRectangle>(
				color, 
				Point(std::stod(params[2]),
				std::stod(params[3])),
				std::stod(params[4]),
				std::stod(params[5])
			);
		}
		if (type == TRIANGLE)
		{
			if (params.size() < 8)
			{
				throw std::invalid_argument("Invalid input");
			}
			return std::make_unique<CTriangle>(
				color, 
				Point(std::stod(params[2]), std::stod(params[3])),
				Point(std::stod(params[4]), std::stod(params[5])),
				Point(std::stod(params[6]), std::stod(params[7]))
			);
		}
		if (type == ELLIPSE)
		{
			if (params.size() < 6)
			{
				throw std::invalid_argument("Invalid input");
			}
			return std::make_unique<CEllipse>(
				color,
				Point(std::stod(params[2]), std::stod(params[3])),
				std::stod(params[4]),
				std::stod(params[5])
			);
		}
		if (type == POLYGON)
		{
			if (params.size() < 6)
			{
				throw std::invalid_argument("Invalid input");
			}
			return std::make_unique<CRegularPolygon>(
				color,
				std::stoi(params[2]),
				Point(std::stod(params[3]), std::stod(params[4])),
				std::stod(params[5])
			);
		}
		throw std::invalid_argument("Unknown shape type");
	}
private:
	std::vector<std::string> GetParams(std::string description) const
	{
		std::vector<std::string> params;
		std::string line;
		std::istringstream stream(description);
		while (std::getline(stream, line, ' '))
		{	
			params.push_back(line);
		}
		return params;
	}
	Color GetColor(std::string color) const
	{
		if (color == GREEN)
		{
			return Color::Green;
		}
		if (color == RED)
		{
			return Color::Red;
		}
		if (color == BLUE)
		{
			return Color::Blue;
		}
		if (color == YELLOW)
		{
			return Color::Yellow;
		}
		if (color == PINK)
		{
			return Color::Pink;
		}
		if (color == BLACK)
		{
			return Color::Black;
		}
		throw std::invalid_argument("unknown color");
	}
};

