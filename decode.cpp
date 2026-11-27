//
// Created by Aleksandr on 11/27/2026.
//

#include "decode.h"

std::vector<unsigned> decode(const Tape &tape) {
    std::vector<unsigned> result;
    unsigned current_number = 0;
    bool in_number = false;

    for (const Symbol symbol: tape) {
        if (symbol == Symbol::Blank) {
            if (in_number) result.push_back(current_number);
            current_number = 0;
            in_number = false;
        } else {
            current_number = current_number << 1 | (symbol == Symbol::One ? 1u : 0u); // двигаем влево и ставим символ
            in_number = true;
        }
    }
    if (in_number) result.push_back(current_number);

    return result;
}
