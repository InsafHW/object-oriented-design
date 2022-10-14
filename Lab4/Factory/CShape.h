#pragma once
#include "ICanvas.h"
#include "Color.h"

class CShape
{
public:
	CShape(Color color)
		:m_color(color)
	{}
	Color GetColor()
	{
		return m_color;
	}
	virtual void Draw(ICanvas&) const = 0;
private:
	Color m_color;
};

