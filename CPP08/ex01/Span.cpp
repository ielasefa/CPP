/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 16:55:38 by iel-asef          #+#    #+#             */
/*   Updated: 2026/02/16 18:59:53 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N):_N(N){}
 
Span::Span(const Span& other) :_N(other._N), _numbers(other._numbers)
{
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _N = other._N;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span()
{}

void Span::addNumber(int num)
{
    if (_numbers.size() >= _N)
        throw std::runtime_error("Span full");
    _numbers.push_back(num);
}

int Span::longestSpan()
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers");

    int minVal = *std::min_element(_numbers.begin(), _numbers.end());
    int maxVal = *std::max_element(_numbers.begin(), _numbers.end());

    return maxVal - minVal;
}


int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers");

    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());

    int shortest = tmp[1] - tmp[0];
    for (size_t i = 1; i < tmp.size() - 1; i++)
    {
        int diff = tmp[i + 1] - tmp[i];
        if (diff < shortest)
            shortest = diff;
    }
    return shortest;
}
