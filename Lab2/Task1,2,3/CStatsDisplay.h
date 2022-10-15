#pragma once
#include <string>
#include <iostream>
#include <limits.h>
#include "IObserver.h"
#include "CWeatherStation.h"
#include "IObservable.h"

enum class DataType
{
	Temperature,
	Humidity,
	Pressure,
};

struct DataInfo
{
	double min = DBL_MAX;
	double max = DBL_MIN;
	double acc = 0;
};

inline std::string GetDataTypeText(DataType& type)
{
	switch (type)
	{
	case DataType::Temperature:
		return "Temperature";
	case DataType::Pressure:
		return "Pressure";
	case DataType::Humidity:
		return "Humidity";
	default:
		throw std::invalid_argument("Unknown type");
	}
}

class CStatsDisplay : public IObserver<SWeatherInfo>
{
private:
	void Update(SWeatherInfo const& data) override
	{
		UpdateData(m_temperature, data.temperature, DataType::Temperature);
		UpdateData(m_humidity, data.humidity, DataType::Humidity);
		UpdateData(m_pressure, data.pressure, DataType::Pressure);
		++m_countAcc;
	}

	void UpdateData(DataInfo& data, double newData, DataType type)
	{
		if (data.min > newData)
		{
			data.min = newData;
		}
		if (data.max < newData)
		{
			data.max = newData;
		}
		data.acc += newData;
		PrintDataInfo(data, type);
	}

	void PrintDataInfo(DataInfo& info, DataType type)
	{
		const std::string typeName = GetDataTypeText(type);
		std::cout << "Max " << typeName << " " << info.max << std::endl;
		std::cout << "Min " << typeName << " " << info.min << std::endl;
		std::cout << "Average " << typeName << " " << (info.acc / m_countAcc) << std::endl;
	}

	DataInfo m_temperature;
	DataInfo m_humidity;
	DataInfo m_pressure;

	unsigned m_countAcc = 0;
};