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

class CShapeFactory : public IShapeFactory
{
public:
	std::unique_ptr<IShape> CreateShape(const std::string& description) const override
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
			return CreateRectangle(color, params);
		}
		if (type == TRIANGLE)
		{
			return CreateTriangle(color, params);
		}
		if (type == ELLIPSE)
		{
			return CreateEllipse(color, params);
		}
		if (type == POLYGON)
		{
			return CreateRegularPolygon(color, params);
		}
		throw std::invalid_argument("Unknown shape type");
	}
private:
	typedef const std::vector<std::string>& Params;

	std::unique_ptr<IShape> CreateRectangle(Color color, Params params) const
	{
		if (params.size() < 6)
		{
			throw std::invalid_argument("Invalid input");
		}
		const auto topLeftX = std::stod(params[2]);
		const auto topLeftY = std::stod(params[3]);
		const auto width = std::stod(params[4]);
		const auto height = std::stod(params[5]);
		if (width <= 0 || height <= 0)
		{
			throw std::invalid_argument("Invalid input");
		}
		return std::make_unique<CRectangle>(
			color,
			Point(topLeftX, topLeftY),
			width,
			height
		);
	}
	std::unique_ptr<IShape> CreateEllipse(Color color, Params params) const
	{
		if (params.size() < 6)
		{
			throw std::invalid_argument("Invalid input");
		}
		const auto centerX = std::stod(params[2]);
		const auto centerY = std::stod(params[3]);
		const auto horizontalRadius = std::stod(params[4]);
		const auto verticalRadius = std::stod(params[5]);
		if (horizontalRadius <= 0 || verticalRadius <= 0)
		{
			throw std::invalid_argument("Invalid input");
		}
		return std::make_unique<CEllipse>(
			color,
			Point(centerX, centerY),
			horizontalRadius,
			verticalRadius
		);
	}
	std::unique_ptr<IShape> CreateTriangle(Color color, Params params) const
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
	std::unique_ptr<IShape> CreateRegularPolygon(Color color, Params params) const
	{
		if (params.size() < 6)
		{
			throw std::invalid_argument("Invalid input");
		}
		const auto vertexCount = std::stod(params[2]);
		const auto centerX = std::stod(params[3]);
		const auto centerY = std::stod(params[4]);
		const auto radius = std::stod(params[5]);
		if (vertexCount <= 0 || radius <= 0)
		{
			throw std::invalid_argument("Invalid input");
		}
		return std::make_unique<CRegularPolygon>(
			color,
			vertexCount,
			Point(centerX, centerY),
			radius
		);
	}

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

