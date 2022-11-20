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
		WHEN("When adapter creates draw mode must be setted up and unsetted at the end of programm")
		{
			{
				ModernGraphicsLibAdapter adapter(renderer);
				adapter.MoveTo(0, 0);
			}
			REQUIRE(output.str() == "<draw>\n</draw>\n");
		}
		WHEN("Addapter creates, default pointer is setted to 0,0")
		{
			{
				ModernGraphicsLibAdapter adapter(renderer);
				adapter.LineTo(10, 10);
			}
			REQUIRE(output.str() == "<draw>\n"
				"  <line fromX=\"0\" fromY=\"0\" toX=\"10\" toY=\"10\"/>\n"
				"</draw>\n"
			);
		}
		WHEN("Call with moveTo, default pointer changes")
		{
			{
				ModernGraphicsLibAdapter adapter(renderer);
				adapter.MoveTo(20, 20);
				adapter.LineTo(10, 10);
			}
			REQUIRE(output.str() == "<draw>\n"
				"  <line fromX=\"20\" fromY=\"20\" toX=\"10\" toY=\"10\"/>\n"
				"</draw>\n"
			);
		}
	}
}