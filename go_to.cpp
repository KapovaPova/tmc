//
// Created by Aleksandr on 11/25/2026.
//

#include "go_to.h"

#include "next_var.h"
#include "prev_var.h"

void go_to(Program &program, int &start, int &current_var, const int &target_var) {
    while (current_var < target_var) {
        next_var(program, start);
        current_var++;
    }
    while (current_var > target_var) {
        prev_var(program, start);
        current_var--;
    }
}
