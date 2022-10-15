#include <iostream>
#include "CWeatherStation.h"
#include "CDisplay.h"
#include "CStatsDisplay.h"

int main()
{
    CWeatherStation weatherStation;

	CDisplay display;
	weatherStation.RegisterObserver(display);

	CStatsDisplay statsDisplay;
	weatherStation.RegisterObserver(statsDisplay);

	weatherStation.SetMeasurements(3, 0.7, 760);
	weatherStation.SetMeasurements(4, 0.8, 761);

	weatherStation.RemoveObserver(statsDisplay);

	weatherStation.SetMeasurements(10, 0.8, 761);
	weatherStation.SetMeasurements(-10, 0.8, 761);
	return 0;
}