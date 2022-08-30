#pragma once

#include <set>
#include <functional>
#include <map>

template <typename T>
class IObserver
{
public:
	virtual void Update(T const& data) = 0;
	virtual ~IObserver() = default;
};

template <typename T>
class IObservable
{
public:
	virtual ~IObservable() = default;
	virtual void RegisterObserver(IObserver<T>& observer, int priority) = 0;
	virtual void NotifyObservers() = 0;
	virtual void RemoveObserver(IObserver<T>& observer) = 0;
};

template <class T>
class CObservable : public IObservable<T>
{
public:
	typedef IObserver<T> ObserverType;

	void RegisterObserver(ObserverType& observer, int priority) override
	{
		m_observers[priority].insert(&observer);
	}

	void NotifyObservers() override
	{
		T data = GetChangedData();
		for (auto it = m_observers.begin(); it != m_observers.end(); it++)
		{
			for (auto innerIt = it->second.begin(); innerIt != it->second.end(); innerIt++)
			{
				(* innerIt)->Update(data);
			}
		}
	}

	void RemoveObserver(ObserverType& observer) override
	{
		for (auto it = m_observers.begin(); it != m_observers.end(); it++)
		{
			for (auto innerIt = it->second.begin(); innerIt != it->second.end(); innerIt++)
			{
				if (*innerIt == &observer)
				{
					it->second.erase(&observer);
					break;
				}
			}
		}
	}

protected:
	virtual T GetChangedData()const = 0;

private:
	std::map<int, std::set<ObserverType*>> m_observers;
};