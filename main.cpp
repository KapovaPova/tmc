#include <iostream>

#include "decode.h"
#include "encode.h"
#include "generator.h"
#include "machine.h"

int main() {
    Program program = generator();
    // Tape tape = {
    //     Symbol::Blank, // разделитель
    //     Symbol::Zero, Symbol::One, Symbol::Zero, Symbol::One, //переменная 0
    //     Symbol::Blank, // разделитель
    //     Symbol::Zero, Symbol::One, Symbol::Zero, Symbol::One, //переменная 1
    //     Symbol::Blank // разделитель
    // };
    Tape tape = encode({16, 3}, 4);

    run(program, tape);

    for (const unsigned value: decode(tape)) std::cout << value << ' ';
    // for (auto s: tape) {
    //     if (s == Symbol::Blank) std::cout << '_';
    //     else if (s == Symbol::Zero) std::cout << '0';
    //     else std::cout << '1';
    // }
}
