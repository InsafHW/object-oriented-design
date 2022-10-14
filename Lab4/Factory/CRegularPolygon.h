#pragma once
#include "CShape.h"
#include "Point.h"
#include <iostream>

class CRegularPolygon: public CShape
{
public:
	CRegularPolygon(Color color, int vertexCount, Point center, double radius)
		:CShape(color),
		m_vertexCount(vertexCount),
		m_center(center),
		m_radius(radius)
	{}
	void Draw(ICanvas&) const override
	{
		std::cout << "Draw regular polygon" << std::endl;
	}
	int GetVertexCount()
	{
		return m_vertexCount;
	}
	Point GetCenter()
	{
		return m_center;
	}
	double GetRadius()
	{
		return m_radius;
	}
private:
	int m_vertexCount;
	Point m_center;
	double m_radius;
};

