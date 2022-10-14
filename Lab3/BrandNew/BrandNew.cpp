#include <iostream>
#include <functional>
#include "Lemon.h"
#include "Cinamon.h"
#include "Syrup.h"
#include "Coffee.h"
#include "ChocolateCrumbs.h"
#include "IceCubes.h"
#include "Milkshake.h"
#include "Tea.h"
#include "CoconutFlakes.h"
#include "Cream.h"
#include "Liquor.h"
#include "Chocolate.h"
#include <vector>

using namespace std;

template <typename Component, typename Decorator>
auto operator << (Component&& component, const Decorator& decorate)
{
	return decorate(forward<Component>(component));
}

template <typename Condiment, typename... Args>
auto MakeCondiment(const Args&...args)
{
	// Возвращаем функцию, декорирующую напиток, переданный ей в качестве аргумента
	// Дополнительные аргументы декоратора, захваченные лямбда-функцией, передаются
	// конструктору декоратора через make_unique
	return [=](auto&& b) {
		// Функции make_unique передаем b вместе со списком аргументов внешней функции
		return make_unique<Condiment>(forward<decltype(b)>(b), args...);
	};
}

void PrintBevarageInfo(const IBeverage& beverage)
{
	cout << beverage.GetDescription() << ". Cost: " << beverage.GetCost() << endl;
}

void Task1()
{
	vector<CBeverage*> beverages{
		new CLatte(CoffeePortion::Standart), // standartLatte
		new CLatte(CoffeePortion::Double), // doubleLatte
		new CCapuccino(CoffeePortion::Standart), // standartCapuccino
		new CCapuccino(CoffeePortion::Double), // doubleCapuccino
		new CTea(TeaType::Black), // blackTea
		new CTea(TeaType::Puer), // puerTea
		new CTea(TeaType::Ulun), // ulunTea
		new CTea(TeaType::White) // whiteTea
	};

	for (int i = 0; i < beverages.size(); i++)
	{
		PrintBevarageInfo(*beverages[i]);
	}
}

void Task2()
{
	auto latte =
		make_unique<CLatte>(CoffeePortion::Double) // Берем двойно латте
		<< MakeCondiment<CChocolate>(4) // добавляем 4 дольки шоколада
		<< MakeCondiment<CLiquor>(LiquorType::Nutty) // добавляем ореховый ликер
		<< MakeCondiment<CCream>(); // добавляем сливки
	PrintBevarageInfo(*latte);
};

int main()
{
	Task1();
	return 0;
}
	
