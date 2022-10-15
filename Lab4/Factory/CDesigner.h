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
			try
			{
				auto shape = m_factory.CreateShape(line);
				draft.AddShape(std::move(shape));
			}
			catch (std::invalid_argument const& e) 
			{
				std::cout << e.what() << std::endl;
			}
		}
		return draft;
	}
private:
	IShapeFactory& m_factory;
};

