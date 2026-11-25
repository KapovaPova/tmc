//
// Created by Aleksandr on 11/25/2026.
//

#include "while_end.h"

void while_end(Program &program, int &start, const int &loop_start) {
    program.emplace_back(
        State{
            Rule{Symbol::Blank, Action::Stay, loop_start},
            Rule{Symbol::Zero, Action::Stay, loop_start},
            Rule{Symbol::One, Action::Stay, loop_start}
        }
    );
    start += 1;

    program[loop_start + 1][static_cast<size_t>(Symbol::Blank)].next = start;
}