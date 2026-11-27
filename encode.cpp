//
// Created by Aleksandr on 11/27/2026.
//

#include "encode.h"

Tape encode(const std::vector<unsigned> &values, const int &width) {
    Tape tape = {Symbol::Blank};

    for (const unsigned value: values) {
        for (int bit_index = width - 1; bit_index >= 0; bit_index--)
            tape.push_back((value >> bit_index) & 1 ? Symbol::One : Symbol::Zero); // побитовая запись в ленту
        tape.push_back(Symbol::Blank);
    }

    return tape;
}
