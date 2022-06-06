#include <SFML/Graphics.hpp>
#include "Objects/Board.h"
#include "Objects/Checkers.h"

//using namespace sf;

sf::RenderWindow window(sf::VideoMode(1500, 1500), "checkers");

int main()
{
    window.setFramerateLimit(60);

    // Главный цикл приложения. Выполняется, пока открыто окно
    while (window.isOpen())
    {
        Board board;
        board.makeBoard();

        Checkers checkers;
        checkers.makeCheckers();

        // Обрабатываем очередь событий в цикле
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Пользователь нажал на «крестик» и хочет закрыть окно?
            if (event.type == sf::Event::Closed)
                // тогда закрываем его
                window.close();
        }


        // Отрисовка окна
//        window.clear();
        window.display();
    }

    return 0;
}