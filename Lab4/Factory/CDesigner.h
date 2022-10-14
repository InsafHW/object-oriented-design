#pragma once
#include "IDesigner.h"
#include "IShapeFactory.h"
#include <iostream>

class CDesigner:public IDesigner
{
public:
	CDesigner(IShapeFactory& factory)
		:m_factory(factory)
	{}
	CPictureDraft CreateDraft(std::istream& stream) const override
	{
		CPictureDraft draft;
		std::string line;
		while (getline(stream, line))
		{
			std::cout << line;
		}
		return draft;
	}
private:
	IShapeFactory& m_factory;
};

