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
    vector<Duck*> ducks{ new MallardDuck(), new RedheadDuck(), new DecoyDuck(), new RubberDuck() };

    std::for_each(
        ducks.begin(),
        ducks.end(),
        [](Duck* duck)
        {
            PlayWithDuck(duck);
        }
    );

    std::cout << "----------------------------------" << std::endl;
    MallardDuck mallardDuck;
    PlayWithDuck(&mallardDuck);

    mallardDuck.SetDanceBehavior(MinuetDance);
    mallardDuck.SetFlyBehavior(FlyWithWings);
    mallardDuck.SetQuackBehavior(SqueakBehavior);
    PlayWithDuck(&mallardDuck);
    mallardDuck.Fly();
    mallardDuck.Fly();
    mallardDuck.Fly();
    mallardDuck.Fly();
    mallardDuck.Fly();

    return 0;
}