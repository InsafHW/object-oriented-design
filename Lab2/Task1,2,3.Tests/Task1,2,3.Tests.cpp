#define CATCH_CONFIG_MAIN
#include <iostream>
#include <stack>
#include "../../catch2/catch.hpp"
#include "./PriorityObservableTest.h"
#include "./SafeDeleteTest.h"

TEST_CASE("Task2")
{
	SafeDeleteStation observable;
	SafeDeleteDisplay observer(observable);

	observable.RegisterObserver(observer);

	REQUIRE_NOTHROW(observable.ChangeData());
}

TEST_CASE("Task3") {
	PriorityTestObservable observable;

	std::stack<std::string> expectingStack({ "ovserver3", "observer2", "observer1"});
	std::stack<std::string> callStack;

	PriorityTestObserver observer1("observer1", callStack);
	PriorityTestObserver observer2("observer2", callStack);
	PriorityTestObserver observer3("ovserver3", callStack);

	observable.RegisterObserver(observer1, 3);
	observable.RegisterObserver(observer2, 2);
	observable.RegisterObserver(observer3, 1);

	observable.ChangeData();

	REQUIRE(expectingStack == callStack);
}