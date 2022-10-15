#pragma once
#include "ICanvas.h"
#include "IShape.h"
#include "Color.h"

class CShape: public IShape
{
public:
	CShape(Color color)
		:m_color(color)
	{}
	Color GetColor() const override
	{
		return m_color;
	}
	virtual void Draw(ICanvas*) const = 0;
private:
	Color m_color;
};

