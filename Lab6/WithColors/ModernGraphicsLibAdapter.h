#pragma once
#include "graphics_lib.h"
#include "modern_graphics_lib.h"
#include "shape_drawing_lib.h"

class ModernGraphicsLibAdapter : public graphics_lib::ICanvas, public modern_graphics_lib::CModernGraphicsRenderer
{
public:
	ModernGraphicsLibAdapter(std::ostream& strm)
		:CModernGraphicsRenderer(strm)
	{
		BeginDraw();
	}

	~ModernGraphicsLibAdapter()
	{
		EndDraw();
	}

	void SetColor(uint32_t rgbColor) override
	{
		m_rgbaColor.r = ((rgbColor >> 16) & 0xff) / 255;
		m_rgbaColor.g = ((rgbColor >> 8) & 0xff) / 255;
		m_rgbaColor.b = (rgbColor & 0xff) / 255;
	}

	void MoveTo(int x, int y) override
	{
		m_startPoint.x = x;
		m_startPoint.y = y;
	}

	void LineTo(int x, int y) override
	{
		DrawLine(m_startPoint, modern_graphics_lib::CPoint{ x, y }, m_rgbaColor);
	}
private:
	modern_graphics_lib::CPoint m_startPoint{ 0, 0 };
	modern_graphics_lib::CRGBAColor m_rgbaColor{0, 0, 0, 1};
};

