#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdint>

// ������������ ���� ����������� ���������� (���������� ��� ���������)
namespace graphics_lib
{
	// ����� ��� ���������
	class ICanvas
	{
	public:
		// ��������� ����� � ������� 0xRRGGBB
		virtual void SetColor(uint32_t rgbColor) = 0;
		// ������ "����" � ����� x, y
		virtual void MoveTo(int x, int y) = 0;
		// ������ ����� � ������� �������, ���������� ���� � ����� x,y 
		virtual void LineTo(int x, int y) = 0;
		virtual ~ICanvas() = default;
	};

	// ���������� ������ ��� ���������
	class CCanvas : public ICanvas
	{
	public:
		void SetColor(uint32_t rgbColor) override
		{
			std::cout << "SetColor #" << std::setfill('0') << std::uppercase << std::setw(6) << std::hex << rgbColor << std::endl;
		}
		void MoveTo(int x, int y) override
		{
			std::cout << "MoveTo (" << x << ", " << y << ")" << std::endl;
		}
		void LineTo(int x, int y) override
		{
			std::cout << "LineTo (" << x << ", " << y << ")" << std::endl;
		}
	};
}