//
// Created by Шамиль Валиев on 14.05.2022.
//

#include "Checkers.h"


sf::Vector2i posChecker(int i,
                        int Wight,
                        const int Step,
                        const int dX,
                        const int dY){
    int k = (i < 12) ? 0 : 2;
    return {i % (Wight / 2) * Step * 2 + Step * (i / 4 % 2) + dX,
            (i / (Wight / 2)) * Step + dY + Step * k};
}


void Checkers::make(const int Wight, const int Step) {
    const int dXchecker = 33;
    const int dYchecker = 37;
    const int dXdot = dXchecker + 25;
    const int dYdot = dYchecker + 25;
    const int firstHalf = 12;
    const int secondHalf = 24;
    const int Radius = 75;

    for (int i=0; i<firstHalf; i++){
//        _checker[i].setMissis(false);
        _checker[i].setColor(false);
        _checker[i].getChecker()->setRadius(Radius);
        _checker[i].getChecker()->
            setPosition(posChecker(i, Wight, Step, dXchecker, 
                                   dYchecker).x,
                        posChecker(i, Wight, Step, dXchecker, 
                                   dYchecker).y);
//        _checker[i].getDot()->getDot()->setRadius(1);
        _checker[i].getDot()->getDot()->
            setPosition(posChecker(i, Wight, Step, dXdot,
                                   dYdot).x,
                        posChecker(i, Wight, Step, dXdot,
                                   dYdot).y);
        _checker[i].setTexture("../Resources/checker.png");
    }

    for (int i=firstHalf; i<secondHalf; i++){
//        _checker[i].setMissis(false);
        _checker[i].setColor(true);
        _checker[i].getChecker()->setRadius(Radius);
        _checker[i].getChecker()->
                setPosition(posChecker(i, Wight, Step, dXchecker,
                                       dYchecker).x,
                            posChecker(i, Wight, Step, dXchecker,
                                       dYchecker).y);
        _checker[i].getDot()->getDot()->setRadius(0);
        _checker[i].getDot()->getDot()->
                setPosition(posChecker(i, Wight, Step, dXdot,
                                       dYdot).x,
                            posChecker(i, Wight, Step, dXdot,
                                       dYdot).y);
        _checker[i].setTexture("../Resources/checker.png");
        _checker[i].getChecker()->setFillColor(sf::Color(170,
                                                         140, 80));

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


//void Checkers::setDot(bool step, Dot* dot, Dot* fa) {
//    bool f = false;
//    for (Checker &it: _checker) {
//        if (it.getChecker()->getGlobalBounds().
//                contains(dot->getDot()->getPosition().x - 182 + 10,
//                         dot->getDot()->getPosition().y + 182 + 10) &&
//             step != it.getColor()) {
//            f = true;
//            for (Checker &it2: _checker) {
//                if (it2.getChecker()->getGlobalBounds().
//                        contains(it.getChecker()->getPosition().x - 182 + 10,
//                                 it.getChecker()->getPosition().y + 182 +
//                                 10)) {
//                    f = false;
//                }
//            }
//            sf::Vector2i pos(it.getChecker()->getPosition().x - 2*182 + 10,
//                             it.getChecker()->getPosition().y + 2*182 + 10);
//            if (findDot(fa, pos)){
//                f = false;
//            }
//
//            if (f){
//                dot->setLeftDown(it.getChecker()->getPosition().x - 182 + 10,
//                                 it.getChecker()->getPosition().y + 182 +10,
//                                 dot);
////                setDot(step, dot->getLeftDown(), fa);
//            }
//        }
//    }
//}


Checker * Checkers::showDots(bool step,
                             sf::RenderWindow& window,
                             bool& display,
                             const int Step,
                             sf::Vector2i mousePos) {
    const int dXY(120);
    
//    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    for (Checker& it : _checker){
        if (it.getChecker()->getGlobalBounds().contains(mousePos.x,
                                                        mousePos.y)){
            if (!it.getColor() && !step){
                int f(1);
                bool ifRight(false);
                for (Checker& it2 : _checker) {
                    if (it2.getChecker()->getGlobalBounds().
                    contains(it.getChecker()->getPosition().x - Step + dXY,
                             it.getChecker()->getPosition().y + Step + dXY)) {
                        f = 2;
                        for (Checker& it3 : _checker) {
                            if (it3.getChecker()->getGlobalBounds().
                                contains(it.getChecker()->
                                                 getPosition().x - f * Step + dXY,
                                         it.getChecker()->
                                                 getPosition().y + f * Step +
                                                                        dXY)) {
                                f = 0;
                            }
                        }
                    }
                }
                if (f) {
                    it.setDot("leftDown", it.getChecker()->
                                                    getPosition().x - f*Step,
                                            it.getChecker()->
                                                    getPosition().y + f*Step,
                                            it.getDot());
                    display = true;
                }

                f = 1;
                for (Checker& it2 : _checker) {
                    if (it2.getChecker()->getGlobalBounds().
                            contains(it.getChecker()->
                                            getPosition().x + Step + dXY,
                                     it.getChecker()->
                                            getPosition().y + Step + dXY)) {
                        f = 2;
                        for (Checker& it3 : _checker) {
                            if (it3.getChecker()->getGlobalBounds().
                                contains(it.getChecker()->
                                                 getPosition().x + f * Step + dXY,
                                         it.getChecker()->
                                                 getPosition().y + f * Step +
                                                                        dXY)) {
                                f = 0;
                            }
                        }
                    }
                }
                if (f) {
                    it.setDot("rightDown",
                              it.getChecker()->getPosition().x + f*Step,
                              it.getChecker()->getPosition().y + f*Step,
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
                for (Checker& it2 : _checker) {
                    if (it2.getChecker()->getGlobalBounds().
                        contains(it.getChecker()->
                                            getPosition().x - Step + dXY,
                                 it.getChecker()->
                                            getPosition().y - Step + dXY)) {
                        f = 2;
                        for (Checker& it3 : _checker) {
                            if (it3.getChecker()->getGlobalBounds().
                                contains(it.getChecker()->
                                                 getPosition().x - f * Step + dXY,
                                         it.getChecker()->
                                                 getPosition().y - f * Step +
                                                                        dXY)) {
                                f = 0;
                            }
                        }
                    }
                }
                if (f) {
                    it.setDot("leftUp", it.getChecker()->
                                      getPosition().x - f*Step,
                              it.getChecker()->
                                      getPosition().y - f*Step,
                              it.getDot());
                    display = true;
                }

                f = 1;
                for (Checker& it2 : _checker) {
                    if (it2.getChecker()->getGlobalBounds().
                            contains(it.getChecker()->
                                             getPosition().x + Step + dXY,
                                     it.getChecker()->
                                             getPosition().y - Step + dXY)) {
                        f = 2;
                        for (Checker& it3 : _checker) {
                            if (it3.getChecker()->getGlobalBounds().
                                contains(it.getChecker()->
                                                 getPosition().x + f * Step + dXY,
                                         it.getChecker()->
                                                 getPosition().y - f * Step +
                                                                        dXY)) {
                                f = 0;
                            }
                        }
                    }
                }
                if (f) {
                    it.setDot("rightUp",
                              it.getChecker()->getPosition().x + f*Step,
                              it.getChecker()->getPosition().y - f*Step,
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
    const int dXY(120);

    if (dot->getFather()) {
        int x1(dot->getDot()->getPosition().x);
        int x2(dot->getFather()->getDot()->getPosition().x);
        int y1(dot->getDot()->getPosition().y);
        int y2(dot->getFather()->getDot()->getPosition().y);
        int x = (x1 + x2) / 2 + dXY;
        int y = (y1 + y2) / 2 + dXY;
//        sf::Vector2i middle(x, y);
        for (Checker &it: _checker) {
            if (it.getChecker()->getGlobalBounds().contains(x,y)) {
                it.delChecker();
//                it.getChecker()->setPosition(0, 0);
            }
        }
        cleanUp(dot->getFather());
    }
}

Checker* Checkers::move(Checker *ch, sf::RenderWindow& window, bool& display) {
    const int dXY(25);

    try {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (!findDot(ch->getDot(), mousePos)){
            throw "miss-click";
        }
        Dot* endDot(findDot(ch->getDot(), mousePos));
        sf::Vector2i newPos(endDot->getDot()->getPosition());
        cleanUp(endDot);
        ch->getChecker()->setPosition(newPos.x - dXY, newPos.y - dXY);
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
    for (Checker& it : _checker) {
        window.draw(*it.getChecker());
        it.drawDot(window);
    }
}


