//
// Created by Шамиль Валиев on 12.06.2022.
//

#include "Window.h"


Window::Window() : _window(sf::VideoMode(1500,
                                                1500),
                                                "_checker"),
                  _display(true),
                  _step(false),
                   _firstBoard(true),
                   _firstCheckers(true),
                   _board(),
                   _checkers(),
                  _currentChecker(nullptr),
                  _Wight(8),
                  _Step(182)
{
    _window.setFramerateLimit(60);
}


void Window::Do() {
    while (_window.isOpen())
    {
        if (_firstBoard) {
            _board.make(_Wight, _Step);
            _firstBoard = false;
        }

        if (_firstCheckers) {
            _checkers.make(_Wight, _Step);
            _firstCheckers = false;
        }

        // Обрабатываем очередь событий в цикле
        sf::Event event{};
        while (_window.pollEvent(event))
        {
            // Пользователь нажал на «крестик» и хочет закрыть окно?
            if (event.type == sf::Event::Closed)
                // тогда закрываем его
                _window.close();

            if (event.type == sf::Event::MouseButtonPressed){
                if (event.key.code == sf::Mouse::Left){
                    if (!_currentChecker) {
                        _currentChecker = _checkers.showDots(_step,
                                                             _window,
                                                             _display,
                                                             _Step,
                         sf::Mouse::getPosition(_window));
                        if (_currentChecker){
                            _step = !_step;
                        }
                    } else {
                        _currentChecker = _checkers.move(_currentChecker,
                                                         _window,
                                                         _display);
                    }
                }
            }
        }


        // Отрисовка окна
        if (_display) {
//            window.clear();
            _board.draw(_window);
            _checkers.draw(_window);
            _window.display();
            _display = false;
        }
    }
}

