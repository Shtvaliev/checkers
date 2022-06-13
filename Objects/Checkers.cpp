//
// Created by Шамиль Валиев on 14.05.2022.
//

#include "Checkers.h"

//extern sf::RenderWindow window;
//extern bool display;
//extern Window window;


void Checkers::make() {
    for (int i=0; i<12; i++){
        checker[i].setMissis(false);
        checker[i].setColor(false);
        checker[i].getChecker()->setRadius(75);
        checker[i].getChecker()->
            setPosition((i % 4) * 182 * 2 + 33 + 182 * (i / 4 % 2),
                        (i / 4) * 182 + 37);
//        sf::Vector2i it(checker[i].getChecker()->getPosition());
//        checker[i].getDot()->getDot()->setRadius(1);
        checker[i].getDot()->getDot()->
            setPosition((i % 4) * 182 * 2 + 33 + 182 * (i / 4 % 2) + 25,
                        (i / 4) * 182 + 37 + 25);
        checker[i].setTexture("../Resources/checker.png");

//        window.draw(*checker[i].getChecker());
    }

    for (int i=12; i<24; i++){
        checker[i].setMissis(false);
        checker[i].setColor(true);
        checker[i].getChecker()->setRadius(75);
        checker[i].getChecker()->
                setPosition((i % 4) * 182 * 2 + 33 + 182 * (i / 4 % 2),
                             (i / 4) * 182 + 37 + 182 * 2);
//        sf::Vector2i it(checker[i].getChecker()->getPosition());
        checker[i].getDot()->getDot()->setRadius(0);
        checker[i].getDot()->getDot()->
                setPosition((i % 4) * 182 * 2 + 33 + 182 * (i / 4 % 2) + 25,
                            (i / 4) * 182 + 37 + 182 * 2 + 25);
        checker[i].setTexture("../Resources/checker.png");
        checker[i].getChecker()->setFillColor(sf::Color(170,
                                                        140, 80));

//        window.draw(checker[i]);
    }
}


Dot* findDot(Dot* dot, sf::Vector2i mousePos){
    sf::Vector2i i(dot->getDot()->getPosition());
    Dot* current(nullptr);
    if (dot->getDot()->getGlobalBounds().contains(mousePos.x, mousePos.y)){
        return dot;
    }
    if (dot->getLeftUp()){
        current = findDot(dot->getLeftUp(), mousePos);
        if (current) {
            return current;
        }
    }
    if (dot->getLeftDown()){
        current = findDot(dot->getLeftDown(), mousePos);
        if (current) {
            return current;
        }
    }
    if (dot->getRightUp()){
        current = findDot(dot->getRightUp(), mousePos);
        if (current) {
            return current;
        }
    }
    if (dot->getRightDown()){
        current = findDot(dot->getRightDown(), mousePos);
        if (current) {
            return current;
        }
    }
    return nullptr;
}


void Checkers::setDot(bool step, Dot* dot, Dot* fa) {
    bool f = false;
    for (Checker &it: checker) {
        if (it.getChecker()->getGlobalBounds().
                contains(dot->getDot()->getPosition().x - 182 + 10,
                         dot->getDot()->getPosition().y + 182 + 10) &&
             step != it.getColor()) {
            f = true;
            for (Checker &it2: checker) {
                if (it2.getChecker()->getGlobalBounds().
                        contains(it.getChecker()->getPosition().x - 182 + 10,
                                 it.getChecker()->getPosition().y + 182 +
                                 10)) {
                    f = false;
                }
            }
            sf::Vector2i pos(it.getChecker()->getPosition().x - 2*182 + 10,
                             it.getChecker()->getPosition().y + 2*182 + 10);
            if (findDot(fa, pos)){
                f = false;
            }

            if (f){
                dot->setLeftDown(it.getChecker()->getPosition().x - 182 + 10,
                                 it.getChecker()->getPosition().y + 182 +10,
                                 dot);
//                setDot(step, dot->getLeftDown(), fa);
            }
        }
    }
}


Checker * Checkers::showDots(bool step, sf::RenderWindow& window, bool& display) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    for (Checker& it : checker){
        if (it.getChecker()->getGlobalBounds().contains(mousePos.x,
                                                        mousePos.y)){
            if (!it.getColor() && !step){
                int f = 1;
                for (Checker& it2 : checker) {
                    if (it2.getChecker()->getGlobalBounds().
                    contains(it.getChecker()->getPosition().x - 182 + 120,
                             it.getChecker()->getPosition().y + 182 + 120)) {
                        f = 2;
                        for (Checker& it3 : checker) {
                            if (it3.getChecker()->getGlobalBounds().
                                contains(it.getChecker()->
                                                 getPosition().x - 2 * 182 + 120,
                                         it.getChecker()->
                                                 getPosition().y + 2 * 182 +
                                                                        120)) {
                                f = 0;
                            }
                        }
                    }
                }
                if (f) {
                    it.setDot("leftDown", it.getChecker()->
                                                    getPosition().x - f*182,
                                            it.getChecker()->
                                                    getPosition().y + f*182,
                                            it.getDot());
                    display = true;
                }

                f = 1;
                for (Checker& it2 : checker) {
                    if (it2.getChecker()->getGlobalBounds().
                            contains(it.getChecker()->
                                            getPosition().x + 182 + 120,
                                     it.getChecker()->
                                            getPosition().y + 182 + 120)) {
                        f = 2;
                        for (Checker& it3 : checker) {
                            if (it3.getChecker()->getGlobalBounds().
                                contains(it.getChecker()->
                                                 getPosition().x + 2 * 182 + 120,
                                         it.getChecker()->
                                                 getPosition().y + 2 * 182 +
                                                                        120)) {
                                f = 0;
                            }
                        }
                    }
                }
                if (f) {
                    it.setDot("rightDown",
                              it.getChecker()->getPosition().x + f*182,
                              it.getChecker()->getPosition().y + f*182,
                              it.getDot());
                    display = true;
                }

                if(!it.getDot()->getLeftUp() &&
                        !it.getDot()->getLeftDown() &&
                        !it.getDot()->getRightUp() &&
                        !it.getDot()->getRightDown()){
                    return nullptr;
                } else return &it;

            }


            else if (it.getColor() && step){
                int f = 1;
                for (Checker& it2 : checker) {
                    if (it2.getChecker()->getGlobalBounds().
                        contains(it.getChecker()->
                                            getPosition().x - 182 + 120,
                                 it.getChecker()->
                                            getPosition().y - 182 + 120)) {
                        f = 2;
                        for (Checker& it3 : checker) {
                            if (it3.getChecker()->getGlobalBounds().
                                contains(it.getChecker()->
                                                 getPosition().x - 2 * 182 + 120,
                                         it.getChecker()->
                                                 getPosition().y - 2 * 182 +
                                                                        120)) {
                                f = 0;
                            }
                        }
                    }
                }
                if (f) {
                    it.setDot("leftUp", it.getChecker()->
                                      getPosition().x - f*182,
                              it.getChecker()->
                                      getPosition().y - f*182,
                              it.getDot());
                    display = true;
                }

                f = 1;
                for (Checker& it2 : checker) {
                    if (it2.getChecker()->getGlobalBounds().
                            contains(it.getChecker()->
                                             getPosition().x + 182 + 120,
                                     it.getChecker()->
                                             getPosition().y - 182 + 120)) {
                        f = 2;
                        for (Checker& it3 : checker) {
                            if (it3.getChecker()->getGlobalBounds().
                                contains(it.getChecker()->
                                                 getPosition().x + 2 * 182 + 120,
                                         it.getChecker()->
                                                 getPosition().y - 2 * 182 +
                                                                        120)) {
                                f = 0;
                            }
                        }
                    }
                }
                if (f) {
                    it.setDot("rightUp",
                              it.getChecker()->getPosition().x + f*182,
                              it.getChecker()->getPosition().y - f*182,
                              it.getDot());
                    display = true;
                }
                if(!it.getDot()->getLeftUp() &&
                   !it.getDot()->getLeftDown() &&
                   !it.getDot()->getRightUp() &&
                   !it.getDot()->getRightDown()){
                    return nullptr;
                } else return &it;
            }
        }
    }
    return nullptr;
}

void Checkers::cleanUp(Dot* dot) {
    if (dot->getFather()) {
        int x1(dot->getDot()->getPosition().x);
        int x2(dot->getFather()->getDot()->getPosition().x);
        int y1(dot->getDot()->getPosition().y);
        int y2(dot->getFather()->getDot()->getPosition().y);
        int x = (x1 + x2) / 2 + 120;
        int y = (y1 + y2) / 2 + 120;
//        sf::Vector2i middle(x, y);
        for (Checker &it: checker) {
            if (it.getChecker()->getGlobalBounds().contains(x,y)) {
                it.delChecker();
//                it.getChecker()->setPosition(0, 0);
            }
        }
        cleanUp(dot->getFather());
    }
}

Checker* Checkers::move(Checker *ch, sf::RenderWindow& window, bool& display) {
    try {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (!findDot(ch->getDot(), mousePos)){
            throw "miss-click";
        }
        Dot* endDot(findDot(ch->getDot(), mousePos));
        sf::Vector2i newPos(endDot->getDot()->getPosition());
        cleanUp(endDot);
        ch->getChecker()->setPosition(newPos.x - 25, newPos.y - 25);
        ch->getDot()->getDot()->setPosition(newPos.x, newPos.y);
        ch->getDot()->resetChildren();
        display = true;
        return nullptr;
    }

    catch (const char * s){
        return ch;
    }
}



void Checkers::draw(sf::RenderWindow& window){
    for (Checker& it : checker) {
        window.draw(*it.getChecker());
        it.drawDot(window);
    }
}


