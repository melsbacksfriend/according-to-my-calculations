#include "calculator.h"

Calculator::Calculator() {}

std::string Calculator::shuntingYard(std::string expression)
{
    Stack<std::string> operators;
    Queue<std::string> output;
    std::stringstream sstr(expression);
    while (!sstr.eof())
    {
        std::string token;
        std::getline(sstr, token, ' ');
        try
        {
            // jump to catch block when token isn't a number
            std::stod(token);
            output.push(token);
        }
        catch (std::exception& e)
        {
            // handle extra spaces
            if (std::regex_match(token, std::regex(R"([\+\-\*\(\)/])")))
            {
                if (operators.empty() || hasGreaterPrecedence(token, operators.peek()) || token == "(")
                {
                    operators.push(token);
                }
                else if (token == ")")
                {
                    while (!operators.empty() && operators.peek() != "(")
                    {
                        output.push(operators.pop());
                    }
                    if (operators.empty()) throw std::runtime_error("No matching parenthesis found!");
                    operators.pop();
                }
                else
                {
                    while (!operators.empty() && !hasGreaterPrecedence(token, operators.peek()) && operators.peek() != "(")
                    {
                        output.push(operators.pop());
                    }
                    operators.push(token);
                }
            }
        }
    }
    while (!operators.empty())
    {
        output.push(operators.pop());
    }
    std::string result = output.pop();
    while (!output.empty())
    {
        result += " " + output.pop();
    }
    return result;
}

double Calculator::evaluate(std::string expression)
{
    Stack<double> numbers;
    expression = shuntingYard(expression);
    std::stringstream sstr(expression);
    while (!sstr.eof())
    {
        std::string token;
        std::getline(sstr, token, ' ');
        try
        {
            numbers.push(std::stod(token));
        }
        catch (std::exception& e)
        {
            double rhs = numbers.pop();
            double lhs = numbers.pop();
            if (token == "+") numbers.push(lhs + rhs);
            else if (token == "-") numbers.push(lhs - rhs);
            else if (token == "*") numbers.push(lhs * rhs);
            else if (token == "/") numbers.push(lhs / rhs);
        }
    }
    return numbers.pop();
}

bool Calculator::hasGreaterPrecedence(const std::string& o1, const std::string& o2)
{
    return (((o1 == "*" || o1 == "/") && (o2 == "+" || o2 == "-")) || o2 == "(");
}