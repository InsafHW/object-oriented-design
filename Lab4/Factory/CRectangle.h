#pragma once
#include <iostream>
#include "CShape.h"
#include "Point.h"

class CRectangle: public CShape
{
public:
	CRectangle(Color color, Point topLeft, double width, double height)
		: CShape(color),
		m_topLeft(topLeft),
		m_width(width),
		m_height(height)
	{}
	void Draw(ICanvas&) const override
	{
		std::cout << "Draw rectangle" << std::endl;
	};
	Point GetLeftTop()
	{
		return m_topLeft;
	}
	Point GetRightBottom()
	{
		return Point(
			m_topLeft.GetX() + m_width,
			m_topLeft.GetY() + m_height
		);
	}
private:
	double m_width;
	double m_height;
	Point m_topLeft;
};

