#include "WeatherStation.h"

int main()
{
	CWeatherData wd;

	CDisplay display;
	wd.RegisterObserver(display, 10);

	CStatsDisplay statsDisplay;
	wd.RegisterObserver(statsDisplay, 92);

	wd.SetMeasurements(3, 0.7, 760);
	wd.RemoveObserver(display);
	//wd.SetMeasurements(4, 0.8, 761);

	//wd.RemoveObserver(statsDisplay);

	//wd.SetMeasurements(10, 0.8, 761);
	//wd.SetMeasurements(-10, 0.8, 761);
	return 0;
}