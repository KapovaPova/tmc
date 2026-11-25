//
// Created by Aleksandr on 11/25/2026.
//

#include "prev_var.h"

void prev_var(Program &program, int &start) {
    program.emplace_back(
        State{
            Rule{Symbol::Blank, Action::Left, start + 1},
            Rule{Symbol::Zero, Action::Left, start},
            Rule{Symbol::One, Action::Left, start}
        }
    );
    start += 1;
}