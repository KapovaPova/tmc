//
// Created by Aleksandr on 11/25/2026.
//

#include "next_var.h"

void next_var(Program &program, int &start) {
    program.emplace_back(
        State{
            Rule{Symbol::Blank, Action::Right, start + 1},
            Rule{Symbol::Zero, Action::Right, start},
            Rule{Symbol::One, Action::Right, start}
        }
    );
    start += 1;
}
