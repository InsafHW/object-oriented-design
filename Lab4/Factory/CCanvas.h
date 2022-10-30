#pragma once
#include "ICanvas.h"
#include <iostream>
#include <SFML/Graphics.hpp>

class CCanvas: public ICanvas
{
public:
	CCanvas(sf::RenderTarget* renderTarget)
		:m_renderTarget(renderTarget)
	{}
	void SetColor(Color color) override
	{
		switch (color)
		{
		case Color::Green:
			m_color = sf::Color::Green;
			break;
		case Color::Red:
			m_color = sf::Color::Red;
			break;
		case Color::Blue:
			m_color = sf::Color::Blue;
			break;
		case Color::Yellow:
			m_color = sf::Color::Yellow;
			break;
		case Color::Pink:
			m_color = sf::Color::Magenta;
			break;
		case Color::Black:
			m_color = sf::Color::Black;
			break;
		default:
			break;
		}
	}
	void DrawLine(Point from, Point to) override
	{
		sf::VertexArray lines(sf::LinesStrip, 2);
		lines[0].position = sf::Vector2f(from.GetX(), from.GetY());
		lines[0].color = m_color;
		lines[1].position = sf::Vector2f(to.GetX(), to.GetY());
		lines[1].color = m_color;
		m_renderTarget->draw(lines);
	}
	void DrawEllipse(Point center, double horizontalRadius, double verticalRadius)
	{
		const double PI = 3.14;
		const int quality = 70;
		sf::ConvexShape ellipse;
		ellipse.setPointCount(quality);
		for (int i = 0; i < quality; i++)
		{
			float rad = (360 / quality * i) / (360 / PI / 2);
			float x = cos(rad) * horizontalRadius;
			float y = sin(rad) * verticalRadius;
			ellipse.setPoint(i, sf::Vector2f(x, y));
		}
		ellipse.setPosition(center.GetX(), center.GetY());
		ellipse.setFillColor(m_color);
		m_renderTarget->draw(ellipse);
	}
private:
	sf::Color m_color;
	sf::RenderTarget* m_renderTarget;
};

