#include "Beverages.h"
#include "Condiments.h"

#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>

using namespace std;

/*
Возвращает функцию, декорирующую напиток определенной добавкой
Параметры шаблона:
	Condiment - класс добавки, конструктор которого в качестве первого аргумента
				принимает IBeveragePtr&& оборачиваемого напитка
	Args - список типов прочих параметров конструктора (возможно, пустой)
*/
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

template <typename Component, typename Decorator>
auto operator << (Component&& component, const Decorator& decorate)
{
	return decorate(forward<Component>(component));
}

TeaType ConvertIntToTeaType(int type)
{
	if (type == 1)
	{
		return TeaType::Ulun;
	}
	if (type == 2)
	{
		return TeaType::Black;
	}
	if (type == 3)
	{
		return TeaType::Green;
	}
	if (type == 4)
	{
		return TeaType::Red;
	}
	throw invalid_argument("Unknown tea type");
}



void DialogWithUser()
{
	cout << "Type 1 - for coffee, 2 - for tea, 3 - for milkshake\n";

	int choice;
	cin >> choice;

	unique_ptr<IBeverage> beverage;

	if (choice == 1)
	{
		cout << "Type 1 - for latte, 2 - for capuccino\n";
		cin >> choice;
		cout << "Select size. Type 1 - for default, 2 - for double\n";
		int sizeType;
		cin >> sizeType;
		CoffeeSize coffeeSize = sizeType == 2 ? CoffeeSize::Double : CoffeeSize::Default;
		if (choice == 1)
		{
			beverage = make_unique<CLatte>(coffeeSize);
		}
		else if (choice == 2)
		{
			beverage = make_unique<CCappuccino>(coffeeSize);
		}
		else
		{
			return;
		}
	}
	else if (choice == 2)
	{
		cout << "Select tea sort. Type 1 - for ulun, 2 - for black, 3 - for green, 4 - for red\n";
		cin >> choice;
		beverage = make_unique<CTea>(ConvertIntToTeaType(choice));
	}
	else if (choice == 3)
	{
		cout << "Select size. Type 1 - for small, 2 - for middle, 3 - for large\n";
		cin >> choice;
		beverage = make_unique<CMilkshake>(MilkShakeSize(choice));
	}
	else
	{
		return;
	}

	for (;;)
	{
		cout << "1 - Lemon, 2 - Cinnamon, 3 - Cream, 4 - Chocolate, 5 - Liquir, 0 - Checkout" << endl;
		cin >> choice;

		if (choice == 1)
		{
			beverage = move(beverage) << MakeCondiment<CLemon>();
		}
		else if (choice == 2)
		{
			beverage = move(beverage) << MakeCondiment<CCinnamon>();
		}
		else if (choice == 3)
		{
			beverage = move(beverage) << MakeCondiment<CCream>();
		}
		else if (choice == 4)
		{
			cout << "Enter slices count:\n";
			cin >> choice;
			beverage = move(beverage) << MakeCondiment<CChocolate>(choice);
		}
		else if (choice == 5)
		{
			cout << "Typ 1 - for nutty, 2 - for chocolate:\n";
			cin >> choice;
			beverage = move(beverage) << MakeCondiment<CLiquor>(choice == 1 ? LiquirType::Nutty : LiquirType::Сhocolate);
		}
		else if (choice == 0)
		{
			break;
		}
		else
		{
			return;
		}
	}

	cout << beverage->GetDescription() << ", cost: " << beverage->GetCost() << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	DialogWithUser();
}