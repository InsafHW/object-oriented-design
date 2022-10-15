#include <iostream>
#include "CDesigner.h"
#include "CShapeFactory.h"
#include "CCanvas.h"
#include "CDrawer.h"

using namespace std;

int main()
{
    CShapeFactory shapeFactory;
    CDesigner designer(shapeFactory);
    CDrawer drawer;

    auto draft = designer.CreateDraft(std::cin);
    drawer.DrawPicture(draft);
}