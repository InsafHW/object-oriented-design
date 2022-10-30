#pragma once
#include "CShape.h"
#include "Point.h"
#include <iostream>
#include <vector>

class CRegularPolygon: public CShape
{
public:
	CRegularPolygon(Color color, int vertexCount, Point center, double radius)
		:CShape(color),
		m_vertexCount(vertexCount),
		m_center(center),
		m_radius(radius)
	{}
	void Draw(ICanvas* canvas) const override
	{
		const double PI = 3.14;
		double centerAngle = 2 * PI / m_vertexCount;

		std::vector<Point> points;

		for (int i = 0; i < m_vertexCount; i++)
		{
			Point point(
				m_center.GetX() + m_radius * std::sin(centerAngle * i),
				m_center.GetY() + m_radius * std::cos(centerAngle * i)
			);
			points.push_back(point);
		}
		points.push_back(points[0]);

		canvas->SetColor(GetColor());
		for (int i = 1; i < points.size(); i++)
		{
			canvas->DrawLine(points[i], points[i - 1]);
		}
	}
	int GetVertexCount()
	{
		return m_vertexCount;
	}
	Point GetCenter() const
	{
		return m_center;
	}
	double GetRadius() const
	{
		return m_radius;
	}
private:
	int m_vertexCount;
	Point m_center;
	double m_radius;
};

