#pragma once
#include <iostream>
#include "CShape.h"
#include "Point.h"

class CTriangle: public CShape
{
public:
	CTriangle(Color color, Point left, Point middle, Point right)
		:CShape(color),
		m_left(left),
		m_middle(middle),
		m_right(right)
	{}
	void Draw(ICanvas&) const override
	{
		std::cout << "Draw triangle" << std::endl;
	}
	Point GetVertex1()
	{
		return m_left;
	}
	Point GetVertex2()
	{
		return m_middle;
	}
	Point GetVertex3()
	{
		return m_right;
	}
private:
	Point m_left;
	Point m_middle;
	Point m_right;
};

