#include <iostream>
#include "calculator.h"

int main()
{
    std::cout << "( 5 + 7 ) * 2 - 3 is: " << Calculator::evaluate("( 5 + 7 ) * 2 - 3") << "\n";
}
