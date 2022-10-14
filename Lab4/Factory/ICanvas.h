#pragma once
#include <string>

class ICanvas
{
public:
	virtual void SetColor(std::string color) = 0;
	virtual void DrawLine(double from, double to) = 0;
	virtual void DrawEllipse(double centerX, double centerY, double width, double height) = 0;
};

