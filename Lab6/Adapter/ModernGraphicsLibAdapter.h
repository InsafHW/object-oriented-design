#pragma once
#include "graphics_lib.h"
#include "modern_graphics_lib.h"
#include "shape_drawing_lib.h"

class ModernGraphicsLibAdapter : public graphics_lib::ICanvas
{
public:
	ModernGraphicsLibAdapter(modern_graphics_lib::CModernGraphicsRenderer& renderer)
		: m_renderer(renderer)
	{
		renderer.BeginDraw();
	}

	~ModernGraphicsLibAdapter()
	{
		m_renderer.EndDraw();
	}

	void MoveTo(int x, int y) override
	{
		m_startPoint.x = x;
		m_startPoint.y = y;
	}

	void LineTo(int x, int y) override
	{
		m_renderer.DrawLine(m_startPoint, modern_graphics_lib::CPoint{x, y});
	}
private:
	modern_graphics_lib::CModernGraphicsRenderer& m_renderer;
	modern_graphics_lib::CPoint m_startPoint{0, 0};
};

