#pragma once
#include "../Task1,2,3/CObservable.h"
#include <string>

template <typename T>
class IObservable
{
public:
	virtual ~IObservable() = default;
	virtual void RegisterObserver(IObserver<T>& observer, int priority) = 0;
	virtual void NotifyObservers() = 0;
	virtual void RemoveObserver(IObserver<T>& observer) = 0;
};

class SafelyMockObservable : public CObservable<double>
{
public:
	void CallNotifyObservers()
	{
		NotifyObservers();
	}
protected:
	double GetChangedData() const override
	{
		return 0;
	}
};

class SafelyMockObserver : public IObserver<double>
{
public:
	SafelyMockObserver(std::string const& name, IObservable<double>& obsObject)
		: m_name(name)
		m_obsevableObject(obsObject)
	{}
private:
	void Update(double const& data, const IObservable<double>* observablee) override
	{
		m_callStack->push(m_name);
		m_obsevableObject.RemoveObserver(*this);
	}
	std::string m_name;
	IObservable<double>& m_obsevableObject;
};