#include <iostream>
#include "CDesigner.h"
#include "CShapeFactory.h"

using namespace std;

int main()
{
    CShapeFactory shapeFactory;
    CDesigner designer(shapeFactory);

    auto draft = designer.CreateDraft(std::cin);

    std::cout << "Hello World!\n";
}