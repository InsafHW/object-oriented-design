#pragma once
#include "graphics_lib.h"

// ???????????? ???? ?????????? ??? ????????? ????? (?????????? graphics_lib)
// ??? ?????????? ?????????? ??? ?????????
namespace shape_drawing_lib
{
    struct Point
    {
        int x;
        int y;
    };

    // ????????? ????????, ??????? ????? ???? ?????????? ?? ?????? ?? graphics_lib
    class ICanvasDrawable
    {
    public:
        virtual void Draw(graphics_lib::ICanvas& canvas)const = 0;
        virtual ~ICanvasDrawable() = default;
    };

    class CTriangle : public ICanvasDrawable
    {
    public:
        CTriangle(const Point& p1, const Point& p2, const Point& p3, const uint32_t color = 0x000000)
            :m_p1(p1),
            m_p2(p2),
            m_p3(p3),
            m_color(color)
        {}

        void Draw(graphics_lib::ICanvas& canvas)const override
        {
            canvas.SetColor(m_color);
            canvas.MoveTo(m_p1.x, m_p2.y);
            canvas.LineTo(m_p2.x, m_p2.y);
            canvas.LineTo(m_p3.x, m_p3.y);
            canvas.LineTo(m_p1.x, m_p1.y);
        }
    private:
        Point m_p1;
        Point m_p2;
        Point m_p3;
        uint32_t m_color;
    };

    class CRectangle : public ICanvasDrawable
    {
    public:
        CRectangle(const Point& leftTop, int width, int height, const uint32_t color = 0x000000)
            :m_leftTop(leftTop),
            m_width(width),
            m_height(height),
            m_color(color)
        {}

        void Draw(graphics_lib::ICanvas& canvas)const override
        {
            canvas.SetColor(m_color);
            Point rightTop{ m_leftTop.x + m_width, m_leftTop.y };
            Point rightBottom{ rightTop.x, rightTop.y + m_height };
            Point leftBottom{ m_leftTop.x, rightBottom.y };
            canvas.MoveTo(m_leftTop.x, m_leftTop.y);
            canvas.LineTo(rightTop.x, rightTop.y);
            canvas.LineTo(rightBottom.x, rightBottom.y);
            canvas.LineTo(leftBottom.x, leftBottom.y);
            canvas.LineTo(m_leftTop.x, m_leftTop.y);
        }
    private:
        Point m_leftTop;
        int m_width;
        int m_height;
        uint32_t m_color;
    };

    // ????????, ????????? ???????? ICanvasDrawable-??????? ?? ICanvas
    class CCanvasPainter
    {
    public:
        CCanvasPainter(graphics_lib::ICanvas& canvas)
            :m_canvas(canvas)
        {}
        void Draw(const ICanvasDrawable& drawable)
        {
            drawable.Draw(m_canvas);
        }
    private:
        graphics_lib::ICanvas& m_canvas;
    };
}
