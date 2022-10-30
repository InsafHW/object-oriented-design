#pragma once
#include <SFML/Graphics.hpp>
#include "CPictureDraft.h"
#include "ICanvas.h"

class CPainter
{
public:
    CPainter()
	{
        m_window = new sf::RenderWindow;
        m_canvas = new CCanvas(m_window);
	}
    ~CPainter()
    {
        delete m_window;
        delete m_canvas;
    }
	void DrawPicture(CPictureDraft& draft)
	{
        m_window->create(sf::VideoMode(800, 600), "");
        while (m_window->isOpen())
        {
            sf::Event event;
            while (m_window->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    m_window->close();
            }

            m_window->clear();

            for (int i = 0; i < draft.GetShapeCount(); i++)
            {
                std::unique_ptr<IShape>& shape = draft.GetShape(i);
                shape->Draw(m_canvas);
            }

            m_window->display();
        }
	}
private:
    ICanvas* m_canvas;
    sf::RenderWindow* m_window;
};

