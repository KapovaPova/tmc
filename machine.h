//
// Created by Aleksandr on 11/23/2026.
//

#ifndef MAIN_MACHINE_H
#define MAIN_MACHINE_H
#include "types.h"

// Выполняет программу над лентой до остановки (next == -1).
// tape меняется на месте, результат остаётся у вызывающего.
void run(const std::vector<State> &program, std::vector<Symbol> &tape);

#endif //MAIN_MACHINE_H
