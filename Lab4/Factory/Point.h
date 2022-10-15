#pragma once
class Point
{
public:
	Point(double x, double y)
		:m_x(x),
		m_y(y)
	{}
	double GetX() const
	{
		return m_x;
	}
	double GetY() const
	{
		return m_y;
	}
	void SetX(double x)
	{
		m_x = x;
	}
	void SetY(double y)
	{
		m_y = y;
	}
private:
	double m_x;
	double m_y;
};

