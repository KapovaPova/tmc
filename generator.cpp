//
// Created by Aleksandr on 11/23/2026.
//

#include "generator.h"

#include "go_to.h"
#include "minus.h"
#include "next_var.h"
#include "prev_var.h"
#include "plus.h"
#include "while.h"

Program generator() {
    int start = 1; // команда, с которой начать и куда писать после
    int current_var = 0; // индекс текущей переменной
    Program program; // программа
    program.emplace_back(
        State{
            Rule{Symbol::Blank, Action::Right, 0},
            Rule{Symbol::Zero, Action::Stay, 1},
            Rule{Symbol::One, Action::Stay, 1}
        }
    ); // ставим указатель на 1 переменную

    //plus(program, start);
    //minus(program, start);
    //while_loop(program, start);

    // plus(program, start);
    // next_var(program, start);
    // plus(program, start);
    // prev_var(program, start);
    // plus(program, start);

    int a = 0, b = 1; // индексы переменных

    go_to(program, start, current_var, b);
    minus(program, start);

    go_to(program, start, current_var, a);
    plus(program, start);

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
