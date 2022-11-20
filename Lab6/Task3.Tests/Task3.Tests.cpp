#pragma once
#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../WithColors/ModernGraphicsLibAdapter.h"

SCENARIO("Class adapter")
{
	GIVEN("ModernGraphicsLibAdapter")
	{
		std::ostringstream output;
		WHEN("When adapter creates draw mode must be setted up and unsetted at the end of programm")
		{
			{
				ModernGraphicsLibAdapter adapter(output);
				adapter.MoveTo(0, 0);
			}
			REQUIRE(output.str() == "<draw>\n</draw>\n");
		}
		WHEN("Addapter creates, default pointer is setted to 0,0")
		{
			{
				ModernGraphicsLibAdapter adapter(output);
				adapter.LineTo(10, 10);
			}
			REQUIRE(output.str() == "<draw>\n"
				"  <line fromX=\"0\" fromY=\"0\" toX=\"10\" toY=\"10\">\n"
				"    <color r=\"0\" g=\"0\" b=\"0\" a=\"1\" />\n"
				"  </line>\n"
				"</draw>\n"
			);
		}
		WHEN("Call with moveTo, default pointer changes")
		{
			{
				ModernGraphicsLibAdapter adapter(output);
				adapter.MoveTo(20, 20);
				adapter.LineTo(10, 10);
			}
			REQUIRE(output.str() == "<draw>\n"
				"  <line fromX=\"20\" fromY=\"20\" toX=\"10\" toY=\"10\">\n"
				"    <color r=\"0\" g=\"0\" b=\"0\" a=\"1\" />\n"
				"  </line>\n"
				"</draw>\n"
			);
		}
	}
}

TEST_CASE("Setting color")
{
	std::ostringstream output;
	{
		ModernGraphicsLibAdapter adapter(output);
		adapter.SetColor(0xFFFFFF);
		adapter.LineTo(10, 10);
	}
	REQUIRE(output.str() == "<draw>\n"
		"  <line fromX=\"0\" fromY=\"0\" toX=\"10\" toY=\"10\">\n"
		"    <color r=\"1\" g=\"1\" b=\"1\" a=\"1\" />\n"
		"  </line>\n"
		"</draw>\n"
	);
}