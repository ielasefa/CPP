/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 22:01:58 by iel-asef          #+#    #+#             */
/*   Updated: 2026/04/01 22:04:33 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    (void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    (void)other;
    return *this;
}

PmergeMe::~PmergeMe()
{}

bool isPositiveNumber(const std::string &s)
{
    size_t i;

    if (s.empty())
        return false;
    i = 0;
    while (i < s.size())
    {
        if (!isdigit((unsigned char)s[i]))
            return false;
        i++;
    }
    return true;
}

void parseInput(int argc, char **argv, std::vector<int> &numbers)
{
    int i;
    long n;
    std::string arg;

    i = 1;
    while (i < argc)
    {
        arg = argv[i];
        if (!isPositiveNumber(arg))
            throw std::runtime_error("Error");

        n = std::atol(arg.c_str());
        if (n < 0 || n > 2147483647)
            throw std::runtime_error("Error");

        numbers.push_back((int)n);
        i++;
    }
    if (numbers.size() < 2)
        throw std::runtime_error("Error");
}

size_t jNumber(size_t n)
{
    size_t a;
    size_t b;
    size_t c;
    size_t i;

    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    a = 0;
    b = 1;
    i = 2;
    while (i <= n)
    {
        c = b + 2 * a;
        a = b;
        b = c;
        i++;
    }
    return b;
}

std::vector<size_t> buildInsertPlan(size_t size)
{
    std::vector<size_t> plan;
    size_t step;
    size_t current;
    size_t previous;
    size_t i;

    step = 1;
    while (jNumber(step) < size)
    {
        current = jNumber(step);
        previous = jNumber(step - 1);

        i = current;
        while (i > previous)
        {
            plan.push_back(i - 1);
            i--;
        }
        step++;
    }
    return plan;
}

void sortVector(std::vector<int> &vec)
{
    fordJohnsonSort(vec);
}

void sortDeque(std::deque<int> &deq)
{
    fordJohnsonSort(deq);
}

template void fordJohnsonSort<std::vector<int> >(std::vector<int> &);
template void fordJohnsonSort<std::deque<int> >(std::deque<int> &);