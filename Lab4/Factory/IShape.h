#pragma once
#include "ICanvas.h"

class IShape
{
public:
	virtual void Draw(ICanvas&) const = 0;
	virtual std::string GetColor() const = 0;
};

