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

class DataInfo
{
public:
	DataInfo(DataType type)
		:m_type(type)
	{}

	void Update(double newData)
	{
		m_countAcc++;
		if (m_min > newData)
		{
			m_min = newData;
		}
		if (m_max < newData)
		{
			m_max = newData;
		}
		m_acc += newData;
		PrintInfo();
	}

	void PrintInfo()
	{
		const std::string typeName = GetDataTypeText(m_type);
		std::cout << "Max " << typeName << " " << m_max << std::endl;
		std::cout << "Min " << typeName << " " << m_min << std::endl;
		std::cout << "Average " << typeName << " " << (m_acc / m_countAcc) << std::endl;
	}
private:
	DataType m_type;
	double m_min = DBL_MAX;
	double m_max = DBL_MIN;
	double m_acc = 0;
	unsigned m_countAcc = 0;
};

class CStatsDisplay : public IObserver<SWeatherInfo>
{
public:
	CStatsDisplay()
	{
		m_temperature = std::make_unique<DataInfo>(DataType::Temperature);
		m_humidity = std::make_unique<DataInfo>(DataType::Humidity);
		m_pressure = std::make_unique<DataInfo>(DataType::Pressure);
	}
private:
	void Update(SWeatherInfo const& data) override
	{
		m_temperature->Update(data.temperature);
		m_humidity->Update(data.humidity);
		m_pressure->Update(data.pressure);
	}

	std::unique_ptr<DataInfo> m_temperature;
	std::unique_ptr<DataInfo> m_humidity;
	std::unique_ptr<DataInfo> m_pressure;
};