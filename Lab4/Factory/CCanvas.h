#pragma once
#include "ICanvas.h"
#include <iostream>

class CCanvas: public ICanvas
{
public:
	CCanvas(double window)
		:m_window(window)
	{}
	void SetColor(std::string color) override
	{
		m_color = color;
		std::cout << "Setted color " << color << std::endl;
	}
	void DrawLine(double from, double to) override
	{
		std::cout << "From: " << from << ". To: " << to << std::endl;
	}
	void DrawEllipse(double centerX, double centerY, double width, double height)
	{
		std::cout << "CenterX: " << centerX<< ". CenterY: " << centerX << ". Width: " << width << ". Height: " << height << std::endl;
	}
private:
	std::string m_color;
	double m_window;
};

