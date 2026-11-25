#include <iostream>
#include "generator.h"
#include "machine.h"

int main() {
    Program program = generator();
    Tape tape = {
        Symbol::Blank, // разделитель
        Symbol::Zero, Symbol::Zero, Symbol::Zero, Symbol::One, //переменная 0
        Symbol::Blank, // разделитель
        Symbol::Zero, Symbol::Zero, Symbol::Zero, Symbol::One, //переменная 1
        Symbol::Blank // разделитель
    };

    run(program, tape);

    for (auto s: tape) {
        if (s == Symbol::Blank) std::cout << '_';
        else if (s == Symbol::Zero) std::cout << '0';
        else std::cout << '1';
    }
}
