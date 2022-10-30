#include "IObservable.h"
#include <set>
#include <map>

template <class T>
class CObservable : public IObservable<T>
{
public:
	typedef IObserver<T> ObserverType;

	void RegisterObserver(ObserverType& observer, int priority = 0) override
	{
		if (m_observersSet.find(&observer) == m_observersSet.end())
		{
			m_observers[priority].insert(&observer);
			m_observersSet.insert(&observer);
		}
	}

	void NotifyObservers() override
	{
		T data = GetChangedData();

		std::map<int, std::set<ObserverType*>> observersCopy(m_observers);

		for (auto it = observersCopy.begin(); it != observersCopy.end(); it++)
		{
			for (auto innerIt = it->second.begin(); innerIt != it->second.end(); innerIt++)
			{
				(*innerIt)->Update(data);
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
					m_observersSet.erase(&observer);
					break;
				}
			}
		}
	}
protected:
	// Классы-наследники должны перегрузить данный метод, 
	// в котором возвращать информацию об изменениях в объекте
	virtual T GetChangedData() const = 0;
private:
	std::map<int, std::set<ObserverType*>> m_observers;
	std::set<ObserverType*> m_observersSet;
};