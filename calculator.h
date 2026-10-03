#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <regex>
#include <sstream>
#include "queue.h"
#include "stack.h"

class Calculator
{
public:
    Calculator();
    static double evaluate(std::string expression);

private:
    static std::string shuntingYard(std::string expression);
    static bool hasGreaterPrecedence(const std::string& o1, const std::string& o2);
};

#endif // CALCULATOR_H
