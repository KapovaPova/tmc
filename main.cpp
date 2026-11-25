#include <iostream>
#include "generator.h"
#include "machine.h"

int main() {
    Program program = generator();
    Tape tape = {Symbol::Zero, Symbol::Zero, Symbol::One, Symbol::Blank};

    run(program, tape);

    for (auto s: tape) {
        if (s == Symbol::Blank) std::cout << '_';
        else if (s == Symbol::Zero) std::cout << '0';
        else std::cout << '1';
    }
}