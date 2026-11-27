//
// Created by Aleksandr on 11/25/2026.
//

#include "while_end.h"

#include "go_to.h"

void while_end(Program &program, int &start, int &current_var, const Loop &loop) {
    go_to(program, start, current_var, loop.target_var);

    program.emplace_back(
        State{
            Rule{Symbol::Blank, Action::Stay, loop.start},
            Rule{Symbol::Zero, Action::Stay, loop.start},
            Rule{Symbol::One, Action::Stay, loop.start}
        }
    );
    start += 1;

    program[loop.start + 1][static_cast<size_t>(Symbol::Blank)].next = start;
}
