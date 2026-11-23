#include <iostream>
#include "generator.h"
#include "machine.h"

int main() {
    Program program = generator();
    Tape tape = {Symbol::Zero, Symbol::Zero, Symbol::One};

    run(program, tape);

    for (auto s : tape) std::cout << static_cast<int>(s);
    std::cout << std::endl;
}