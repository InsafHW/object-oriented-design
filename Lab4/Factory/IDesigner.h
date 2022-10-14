#pragma once
#include <sstream>
#include "CPictureDraft.h"

class IDesigner
{
public:
	virtual CPictureDraft CreateDraft(std::istream& stream) const = 0;
};