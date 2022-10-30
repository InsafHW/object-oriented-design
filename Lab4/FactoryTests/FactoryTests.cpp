#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include "../Factory/CShapeFactory.h"
#include "../Factory/CPictureDraft.h"

SCENARIO("Factory")
{
	GIVEN("Shape factory")
	{
		CShapeFactory factory;
		WHEN("Pass less than 2 params, throws error")
		{
			REQUIRE_THROWS(factory.CreateShape(""));
			REQUIRE_THROWS(factory.CreateShape("triangle"));
		}
		WHEN("Pass unknown shape type, throws error")
		{
			REQUIRE_THROWS(factory.CreateShape("unknown 10 10 200 200"));
		}
		WHEN("When pass unknown color, throws error")
		{
			REQUIRE_THROWS(factory.CreateShape("rectangle violet 0 0 200 100"));
		}
	}
}

SCENARIO("Create rectangle")
{
	GIVEN("Shape factory")
	{
		CShapeFactory factory;
		WHEN("Pass less than 6 params, throws error")
		{
			REQUIRE_THROWS(factory.CreateShape("rectangle green 0 0 100"));
		}
		WHEN("Pass width <= 0, throws error")
		{
			REQUIRE_THROWS(factory.CreateShape("rectangle green 0 0 -100 200"));
		}
		WHEN("Pass height <= 0, throws error")
		{
			REQUIRE_THROWS(factory.CreateShape("rectangle green 0 0 100 -200"));
		}
		WHEN("Pass string instead of numbers for point and width/height, throws error")
		{
			REQUIRE_THROWS(factory.CreateShape("rectangle green string string 100 22"));
		}
		WHEN("Pass all parameters correct, shape will be created")
		{
			auto shape = factory.CreateShape("rectangle green 0 0 100 200");
			CRectangle& rectangle = dynamic_cast<CRectangle&>(*shape);
			REQUIRE(rectangle.GetLeftTop().GetX() == 0);
			REQUIRE(rectangle.GetLeftTop().GetY() == 0);
			REQUIRE(rectangle.GetRightBottom().GetX() == 100);
			REQUIRE(rectangle.GetRightBottom().GetY() == 200);
			REQUIRE(rectangle.GetWidth() == 100);
			REQUIRE(rectangle.GetHeight() == 200);
			REQUIRE(rectangle.GetColor() == Color::Green);
		}
	}
}

SCENARIO("Create triangle")
{
	GIVEN("Shape factory")
	{
		CShapeFactory factory;
		WHEN("Pass less than 8 params, throws error")
		{
			REQUIRE_THROWS(factory.CreateShape("triangle green 0 0 100 200 200"));
		}
		WHEN("Pass string instead of numbers for points, throws error")
		{
			REQUIRE_THROWS(factory.CreateShape("triangle green string string 100 22 300 200"));
		}
		WHEN("Pass all parameters correct, shape will be created")
		{
			auto shape = factory.CreateShape("triangle green 0 0 100 200 300 400");
			CTriangle& triangle = dynamic_cast<CTriangle&>(*shape);
			REQUIRE(triangle.GetVertex1().GetX() == 0);
			REQUIRE(triangle.GetVertex1().GetY() == 0);
			REQUIRE(triangle.GetVertex2().GetX() == 100);
			REQUIRE(triangle.GetVertex2().GetY() == 200);
			REQUIRE(triangle.GetVertex3().GetX() == 300);
			REQUIRE(triangle.GetVertex3().GetY() == 400);
			REQUIRE(triangle.GetColor() == Color::Green);
		}
	}
}

SCENARIO("Create ellipse")
{
	GIVEN("Shape factory")
	{
		CShapeFactory factory;
		WHEN("Pass less than 6 params, throws error")
		{
			REQUIRE_THROWS(factory.CreateShape("ellipse green 100 100 100"));
		}
		WHEN("Pass string instead of numbers for points, throws error")
		{
			REQUIRE_THROWS(factory.CreateShape("ellipse green 100 100 100 string"));
		}
		WHEN("Pass horizontal radius <= 0, throws error")
		{
			REQUIRE_THROWS(factory.CreateShape("ellipse green 100 100 -100 10"));
		}
		WHEN("Pass vertical radius <= 0, throws error")
		{
			REQUIRE_THROWS(factory.CreateShape("ellipse green 100 100 100 0"));
		}
		WHEN("Pass all parameters correct, shape will be created")
		{
			auto shape = factory.CreateShape("ellipse green 0 0 100 200");
			CEllipse& ellipse = dynamic_cast<CEllipse&>(*shape);
			REQUIRE(ellipse.GetCenter().GetX() == 0);
			REQUIRE(ellipse.GetCenter().GetY() == 0);
			REQUIRE(ellipse.GetHorizontalRadius() == 100);
			REQUIRE(ellipse.GetVerticalRadius() == 200);
			REQUIRE(ellipse.GetColor() == Color::Green);
		}
	}
}

SCENARIO("Create regular polygon")
{
	GIVEN("Shape factory")
	{
		CShapeFactory factory;
		WHEN("Pass less than 6 params, throws error")
		{
			REQUIRE_THROWS(factory.CreateShape("polygon green 6 100 100"));
		}
		WHEN("Pass string instead of numbers for points, throws error")
		{
			REQUIRE_THROWS(factory.CreateShape("polygon green 6 100 string 100"));
		}
		WHEN("Pass vertex count <= 0, throws error")
		{
			REQUIRE_THROWS(factory.CreateShape("polygon green 0 100 100 200"));
		}
		WHEN("Pass radius <= 0, throws error")
		{
			REQUIRE_THROWS(factory.CreateShape("polygon green 6 100 100 -10"));
		}
		WHEN("Pass all parameters correct, shape will be created")
		{
			auto shape = factory.CreateShape("polygon green 6 100 100 10");
			CRegularPolygon& polygon = dynamic_cast<CRegularPolygon&>(*shape);
			REQUIRE(polygon.GetVertexCount() == 6);
			REQUIRE(polygon.GetCenter().GetX() == 100);
			REQUIRE(polygon.GetCenter().GetY() == 100);
			REQUIRE(polygon.GetRadius() == 10);
			REQUIRE(polygon.GetColor() == Color::Green);
		}
	}
}

SCENARIO("Picture draft")
{
	GIVEN("Picture draft")
	{
		CPictureDraft pictureDraft;
		WHEN("After creation draft has no shapes")
		{
			REQUIRE(pictureDraft.GetShapeCount() == 0);
		}
		WHEN("After adding shape, draft will store this shape")
		{
			pictureDraft.AddShape(std::make_unique<CRectangle>(Color::Green, Point(100, 100), 200, 100));
			REQUIRE(pictureDraft.GetShapeCount() == 1);
		}
		WHEN("Getting shape with non existing index, throws error")
		{
			REQUIRE_THROWS(pictureDraft.GetShape(0));
		}
	}
}