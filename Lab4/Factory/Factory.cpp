#include <iostream>
#include "CDesigner.h"
#include "CShapeFactory.h"
#include "CCanvas.h"
#include "CPainter.h"

using namespace std;

int main()
{
    CShapeFactory shapeFactory;
    CDesigner designer(shapeFactory);
    CPainter painter;

    auto draft = designer.CreateDraft(std::cin);
    painter.DrawPicture(draft);
}