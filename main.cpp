#include <SFML/Graphics.hpp>
#include "Objects/Board.h"
#include "Objects/Checkers.h"


//using namespace sf;

sf::RenderWindow window(sf::VideoMode(1500, 1500), "checker");
bool display = true;

int main()
{
    window.setFramerateLimit(60);

    bool firstBoard = true;
    bool firstCheckers = true;
    Board board;
    Checkers checkers;

    // Главный цикл приложения. Выполняется, пока открыто окно
    while (window.isOpen())
    {
        if (firstBoard) {
            board.make();
            firstBoard = false;
        }

        if (firstCheckers) {
            checkers.make();
            firstCheckers = false;
        }

        // Обрабатываем очередь событий в цикле
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Пользователь нажал на «крестик» и хочет закрыть окно?
            if (event.type == sf::Event::Closed)
                // тогда закрываем его
                window.close();

            if (event.type == sf::Event::MouseButtonPressed){
                if (event.key.code == sf::Mouse::Left){
                    checkers.showDots();
                }
            }
        }


        // Отрисовка окна
        if (display) {
//            window.clear();
            board.draw();
            checkers.draw();
            window.display();
            display = false;
        }
    }

    return 0;
}