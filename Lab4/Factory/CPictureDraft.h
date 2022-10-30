#pragma once
#include <memory>
#include <vector>
#include <stdexcept>
#include "IShape.h"

class CPictureDraft
{
public:
	std::unique_ptr<IShape>& GetShape(int index)
	{
		if (index < 0 || index >= m_shapes.size())
		{
			throw std::out_of_range("Index is out of range");
		}
		return m_shapes[index];
	}
	int GetShapeCount()
	{
		return m_shapes.size();
	}
	void AddShape(std::unique_ptr<IShape>&& shape)
	{
		m_shapes.push_back(std::move(shape));
	}
private:
	std::vector<std::unique_ptr<IShape>> m_shapes;
};