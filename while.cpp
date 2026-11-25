//
// Created by Aleksandr on 11/25/2026.
//

#include "while.h"

void while_loop(Program &program, int &start) {
    program.emplace_back(
        State{
            Rule{Symbol::Blank, Action::Left, start + 1},
            Rule{Symbol::Zero, Action::Right, start},
            Rule{Symbol::One, Action::Right, start}
        }
    );
    program.emplace_back(
        State{
            Rule{Symbol::Blank, Action::Right, start + 2},
            Rule{Symbol::One, Action::Left, start + 1},
            Rule{Symbol::Zero, Action::Stay, start}
        }
    );
    start += 2;
}
