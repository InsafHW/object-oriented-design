#pragma once
#include <iostream>
#include "CShape.h"
#include "Point.h"

class CEllipse : public CShape
{
public:
	CEllipse(Color color, Point center, double horizontalRadius, double verticalRadius)
		:CShape(color),
		m_center(center),
		m_horizontalRadius(horizontalRadius),
		m_verticalRadius(verticalRadius)
	{}
	void Draw(ICanvas* canvas) const override
	{
		canvas->SetColor(GetColor());
		canvas->DrawEllipse(m_center, m_horizontalRadius, m_verticalRadius);
	}
	Point GetCenter()
	{
		return m_center;
	}
	double GetHorizontalRadius()
	{
		return m_horizontalRadius;
	}
	double GetVerticalRadius()
	{
		return m_verticalRadius;
	}
private:
	Point m_center;
	double m_horizontalRadius;
	double m_verticalRadius;
};

