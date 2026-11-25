//
// Created by Aleksandr on 11/23/2026.
//

#include "generator.h"

#include "minus.h"
#include "plus.h"
#include "while.h"

Program generator() {
    //+1
    int start = 0; // команда, с которой начать
    Program program; // программа

    plus(program, start);
    plus(program, start);
    minus(program, start);
    minus(program, start);
    while_loop(program, start);

    //конец
    program.emplace_back(
        State{
            Rule{Symbol::Blank, Action::Stay, -1},
            Rule{Symbol::Zero, Action::Stay, -1},
            Rule{Symbol::One, Action::Stay, -1}
        }
    );
    return program;
}
