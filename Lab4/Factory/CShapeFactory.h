#pragma once
#include "IShapeFactory.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "CEllipse.h"
#include "CRegularPolygon.h"
#include "Color.h"

class CShapeFactory: public IShapeFactory
{
public:
	std::unique_ptr<CShape> CreateShape(std::string description) const override
	{
		if (description == "Rectangle")
		{
			Point topLeft(0, 0);
			return std::make_unique<CRectangle>(
				Color::Red, topLeft, 10, 20
			);
		}
		if (description == "Triangle")
		{
			Point left(0, 0);
			Point middle(10, 20);
			Point right(3, 0);
			return std::make_unique<CTriangle>(
				Color::Black, left, middle, right
			);
		}
		if (description == "Ellipse")
		{
			Point center(0, 0);
			return std::make_unique<CEllipse>(
				Color::Green, center, 10, 20
			);
		}
		if (description == "Polygon")
		{
			Point center(0, 0);
			return std::make_unique<CRegularPolygon>(
				Color::Pink, 6, center, 10
			);
		}
		throw std::invalid_argument("Unknown shape type");
	}
};

