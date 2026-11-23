//
// Created by Aleksandr on 11/23/2026.
//

#include "generator.h"

Program generator() {
    return {
        State{
            Rule{Symbol::Blank, Action::Stay,  -1},  // Blank: стоп
            Rule{Symbol::One,   Action::Right,  0},  // Zero: пишем One, вправо
            Rule{Symbol::One,   Action::Right,  0},  // One: пишем One, вправо
        }
    };
}