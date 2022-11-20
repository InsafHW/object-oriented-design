#pragma once
#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../Adapter/ModernGraphicsLibAdapter.h"

SCENARIO("Object adapter")
{
	GIVEN("ModernGraphicsLibAdapter")
	{
		std::ostringstream output;
		modern_graphics_lib::CModernGraphicsRenderer renderer(output);
		ModernGraphicsLibAdapter adapter(renderer);
		WHEN("Call only moveTo method output must be empty")
		{
			adapter.MoveTo(0, 0);
			REQUIRE(output.str() == "");
		}
	}
}