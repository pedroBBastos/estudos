#include <calculator.h>

namespace pedro::studies::calculator {

    Calculator::Calculator() = default;
    Calculator::~Calculator() = default;

    int Calculator::sum(int a, int b) {
        return a + b;
    }

    int Calculator::subtract(int a, int b) {
        return a - b;
    }

    int Calculator::multiply(int a, int b) {
        return a * b;
    }

    int Calculator::divide(int a, int b) {
        // TODO: Discover how C++ handles division by 0
        // Floating point exception (core dumped)
        return a / b;
    }
}
