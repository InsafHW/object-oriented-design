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

int main()
{
    vector<Duck*> ducks { new MallardDuck(), new RedheadDuck(), new DecoyDuck(), new RubberDuck() };

    std::for_each(
        ducks.begin(),
        ducks.end(), 
        [](Duck* duck) 
        {
            PlayWithDuck(duck);
        }
    );

    std::cout << std::endl << "Checking flies count:" << std::endl;
    MallardDuck mallardDuck;
    for (int i = 0; i < 5; i++)
    {
        mallardDuck.Fly();
    }
    mallardDuck.SetFlyBehavior(make_unique<FlyNoWay>());
    mallardDuck.SetFlyBehavior(make_unique<FlyWithWings>());
    std::cout << "Reset flies count" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        mallardDuck.Fly();
    }
    return 0;
}