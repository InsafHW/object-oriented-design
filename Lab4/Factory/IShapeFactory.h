#pragma once
#include "CShape.h"
#include <string>
#include <memory>

class IShapeFactory
{
public:
	virtual std::unique_ptr<CShape> CreateShape(std::string description) const = 0;
};

