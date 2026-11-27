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
#include "while_start.h"
#include "while_end.h"

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

    int a = 0, b = 1;

    Loop loop = while_start(program, start, current_var, b); // while (b != 0) {
    minus(program, start); //     b--;
    go_to(program, start, current_var, a); //     переходим на a
    plus(program, start); //     a++;
    while_end(program, start, current_var, loop); // }

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
