#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../Task1/Observer.h"
#include "../Task1/WeatherStation.h"

TEST_CASE("plus test") {
	CWeatherData wd;

	//CDisplay display(1);
	//CStatsDisplay statsDisplay(10);

	//wd.RegisterObserver(display);
	//wd.RegisterObserver(statsDisplay);

	REQUIRE((1 + 1) == 2);
}