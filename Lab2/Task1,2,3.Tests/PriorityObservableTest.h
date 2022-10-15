#pragma once
#include "../Task1,2,3/CObservable.h"
#include <stack>
#include <string>

class PriorityTestObservable : public CObservable<double>
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

class PriorityTestObserver : public IObserver<double>
{
public:
	PriorityTestObserver(std::string name, std::stack<std::string>& callStack) 
		: m_name(name),
		m_callStack(&callStack) 
	{}
private:
	void Update(double const& data) override
	{
		m_callStack->push(m_name);
	}
private:
	std::stack<std::string>* m_callStack;
	std::string m_name;
};