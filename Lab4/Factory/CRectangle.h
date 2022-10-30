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
	void Draw(ICanvas* canvas) const override
	{
		const Point topRight(
			m_topLeft.GetX() + m_width,
			m_topLeft.GetY()
		);
		const Point bottomLeft(
			m_topLeft.GetX(),
			m_topLeft.GetY() + m_height
		);
		const Point bottomRight = GetRightBottom();
		canvas->SetColor(GetColor());
		canvas->DrawLine(m_topLeft,	topRight);
		canvas->DrawLine(topRight, bottomRight);
		canvas->DrawLine(bottomRight, bottomLeft);
		canvas->DrawLine(bottomLeft, m_topLeft);
	};
	Point GetLeftTop() const
	{
		return m_topLeft;
	}
	Point GetRightBottom() const
	{
		return Point(
			m_topLeft.GetX() + m_width,
			m_topLeft.GetY() + m_height
		);
	}
	double GetWidth() const
	{
		return m_width;
	}
	double GetHeight() const
	{
		return m_height;
	}
private:
	double m_width;
	double m_height;
	Point m_topLeft;
};

