#pragma once
#include <iostream>
#include "../Task1,2,3/CObservable.h"

class SafeDeleteStation : public CObservable<int>
{
public:
	void ChangeData()
	{
		NotifyObservers();
	}

protected:
	int GetChangedData() const override
	{
		return 0;
	}
};


class SafeDeleteDisplay : public IObserver<int>
{
public:
	SafeDeleteDisplay(IObservable<int>& observable)
		:m_observable(&observable)
	{}

	void Update(int const& data) override
	{
		m_observable->RemoveObserver(*this);
		std::cout << data;
	}

private:
	IObservable<int>* m_observable;
};