//
// Created by Aleksandr on 11/23/2026.
//

#ifndef MAIN_TYPES_H
#define MAIN_TYPES_H
#include <array>
#include <vector>

// Символы, которые могут лежать в клетке ленты.
// Blank - пустая клетка (на ленте её "нет", но машина её видит как символ).
enum class Symbol { Blank, Zero, One };

// Куда головка двигается после выполнения правила.
enum class Action { Left, Right, Stay };

// Одно правило = одна клетка таблицы переходов.
// Выбирается по паре (текущее состояние, символ под головкой).
struct Rule {
    Symbol write; // что записать в клетку под головкой (затирает старый символ)
    Action move; // куда сдвинуть головку после записи
    int next; // номер состояния, в которое перейти; -1 = остановить машину
};

struct Loop {
    int start;
    int target_var;
};

// Одно состояние машины = три правила, по одному на каждый возможный символ.
// Индекс в массиве равен значению enum: [0] - Blank, [1] - Zero, [2] - One.
// Так правило для нужного символа достаётся без поиска: rules[(size_t)symbol].
using State = std::array<Rule, 3>;

// program - вся программа: program[i] это состояние номер i.
//           Только читается, поэтому const.
using Program = std::vector<State>;

// tape    - лента. Меняется по ходу работы, поэтому передана по ссылке:
//           результат остаётся у вызывающего кода.
using Tape = std::vector<Symbol>;

#endif //MAIN_TYPES_H
