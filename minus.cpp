//
// Created by Aleksandr on 11/25/2026.
//

#include "minus.h"

#include "go_to.h"

void minus(Program &program, int &start, int &current_var, const int &target_var) {
    go_to(program, start, current_var, target_var);

    program.emplace_back(
        State{
            Rule{Symbol::Blank, Action::Left, start + 1}, // нашли конечный символ, идем вычитать 1
            Rule{Symbol::Zero, Action::Right, start}, // идем пока не найдем последний символ
            Rule{Symbol::One, Action::Right, start} // идем пока не найдем последний символ
        }
    );
    program.emplace_back(
        State{
            Rule{Symbol::Blank, Action::Right, start + 2}, //заканчиваем
            Rule{Symbol::One, Action::Left, start + 1}, // 0 меняем на 1 и идем дальше вычитать
            Rule{Symbol::Zero, Action::Stay, start + 2} // 1 меняем на 0 и заканчиваем
        }
    );
    start += 2;
}
