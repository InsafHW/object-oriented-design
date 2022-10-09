#include <iostream>
#include "Duck.h"
#include <vector>
#include <algorithm>

void PlayWithDuck(Duck* duck)
{
    std::cout << "------------------" << std::endl;
    duck->Display();
    duck->Swim();
    std::cout << "Fly behavior: ";
    duck->Fly();
    std::cout << "Quack behavior: ";
    duck->Quack();
    std::cout << "Dance behavior: ";
    duck->Dance();
}

void MakeMultipleFlies(Duck* duck)
{
    for (int i = 0; i < 5; i++)
    {
        duck->Fly();
    }
}

int main()
{
    ModelDuck modelDuck;
    PlayWithDuck(&modelDuck);

    modelDuck.SetDanceBehavior(make_unique<MinuetDance>());
    modelDuck.SetFlyBehavior(make_unique<FlyWithWings>());
    modelDuck.SetQuackBehavior(make_unique<SqueakBehavior>());
    PlayWithDuck(&modelDuck);

    std::cout << std::endl << "Checking flies count:" << std::endl;
    MallardDuck mallardDuck;
    MakeMultipleFlies(&mallardDuck);

    mallardDuck.SetFlyBehavior(make_unique<FlyNoWay>());
    mallardDuck.SetFlyBehavior(make_unique<FlyWithWings>());
    std::cout << "Reset flies count" << std::endl;
    MakeMultipleFlies(&mallardDuck);
    return 0;
}