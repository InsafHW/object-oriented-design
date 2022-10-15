#pragma once
#include "IShape.h"
#include <string>
#include <memory>

class IShapeFactory
{
public:
	virtual std::unique_ptr<IShape> CreateShape(std::string description) const = 0;
};

