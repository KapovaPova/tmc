//
// Created by Aleksandr on 11/25/2026.
//

#include "plus.h"

void plus(Program &program, int &start) {
    program.emplace_back(
        State{
            Rule{Symbol::Blank, Action::Left, start + 1}, // нашли конечный символ, идем добавлять 1
            Rule{Symbol::Zero, Action::Right, start}, // идем пока не найдем последний символ
            Rule{Symbol::One, Action::Right, start} // идем пока не найдем последний символ
        }
    );
    program.emplace_back(
        State{
            Rule{Symbol::Blank, Action::Right, start + 2}, // заканчиваем
            Rule{Symbol::One, Action::Stay, start + 2}, // 0 меняем на 1 и заканчиваем
            Rule{Symbol::Zero, Action::Left, start + 1} // 1 меняем на 0 и добавляем вперед 1
        }
    );
    start += 2;
}
