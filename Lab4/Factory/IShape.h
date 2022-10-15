#pragma once
#include "ICanvas.h"
#include "Color.h"

class IShape
{
public:
	virtual void Draw(ICanvas*) const = 0;
	virtual Color GetColor() const = 0;
};

