/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 21:42:37 by iel-asef          #+#    #+#             */
/*   Updated: 2026/02/22 21:42:37 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other)
{
    *this = other;
}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
    this->_stack = other._stack;
    return *this;
}

RPN::~RPN() {}

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::checkInput(std::string &input)
{
    if (input.empty())
    {
        std::cerr << "Error" << std::endl;
        exit(1);
    }

    for (size_t i = 0; i < input.length(); i++)
    {
        if (!std::isdigit(input[i]) && !std::isspace(input[i]) && !isOperator(input[i]))
        {
            std::cerr << "Error" << std::endl;
            exit(1);
        }
    }
}

void RPN::execute(std::string &input)
{
    std::stringstream ss(input);
    std::string token;

    while (ss >> token)
    {
        if (token.length() == 1 && std::isdigit(token[0]))
        {
            _stack.push(token[0] - '0');
        }
        else if (token.length() == 1 && isOperator(token[0]))
        {
            if (_stack.size() < 2)
            {
                std::cerr << "Error" << std::endl;
                return;
            }

            int a = _stack.top(); _stack.pop();
            int b = _stack.top(); _stack.pop();
            int result = 0;

            if (token[0] == '+')
                result = b + a;
            else if (token[0] == '-')
                result = b - a;
            else if (token[0] == '*')
                result = b * a;
            else if (token[0] == '/')
            {
                if (a == 0)
                {
                    std::cerr << "Error" << std::endl;
                    return;
                }
                result = b / a;
            }
            _stack.push(result);
        }
        else
        {
            std::cerr << "Error" << std::endl;
            return;
        }
    }

    if (_stack.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        return;
    }

    std::cout << _stack.top() << std::endl;
}