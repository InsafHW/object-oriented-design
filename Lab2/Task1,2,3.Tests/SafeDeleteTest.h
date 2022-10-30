#pragma once
#include "../Task1,2,3/CObservable.h"

class SafeDeleteTestObservable: public CObservable<double>
{
public:
	void ChangeData()
	{
		NotifyObservers();
	}
protected:
	double GetChangedData() const override
	{
		return 0;
	}
};

class SafeDeleteTextObserver : public IObserver<double>
{
private:
	void Update(double const& data) override
	{

	}
};