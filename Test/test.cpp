#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../Doctest/doctest.h"
#include <SFML/Graphics.hpp>
#include "../Objects/Checkers.h"
#include "../Objects/Checker.h"
#include "../Objects/Dot.h"
#include "../Objects/Board.h"
#include "../Objects/Window.h"

int fact(int n) {
    return n <= 1 ? n : fact(n - 1) * n;
}
TEST_CASE("testing the factorial function") {
//    CHECK(fact(0) == 1); // should fail
    CHECK(fact(1) == 1);
    CHECK(fact(2) == 2);
    CHECK(fact(3) == 6);
    CHECK(fact(10) == 3628800);
    Checker a;
    CHECK(posChecker(1,2,3,4,5) == sf::Vector2i(1,2));
//    CHECK(Checkers.showDots() == Checker());
}