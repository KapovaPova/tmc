//
// Created by Aleksandr on 11/25/2026.
//

#include "while_start.h"

#include "go_to.h"

Loop while_start(Program &program, int &start, int &current_var, const int &target_var) {
    go_to(program, start, current_var, target_var);
    int loop_start = start;

    program.emplace_back(
        State{
            Rule{Symbol::Blank, Action::Right, start + 1},
            Rule{Symbol::Zero, Action::Left, start},
            Rule{Symbol::One, Action::Left, start}
        }
    );
    program.emplace_back(
        State{
            Rule{Symbol::Blank, Action::Left, -1},
            // дошли до конца, единиц нет -> число == 0! (адрес -1 перезапишет while_end)
            Rule{Symbol::Zero, Action::Right, start + 1}, // пока нули -> смотрим следующий бит
            Rule{Symbol::One, Action::Stay, start + 2} // нашли 1 -> число != 0! Заходим в тело цикла
        }
    );

    start += 2;
    return {loop_start, target_var};
}
