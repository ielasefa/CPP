/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 03:46:00 by iel-asef          #+#    #+#             */
/*   Updated: 2026/04/01 16:08:59 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <deque>
#include <iomanip>
#include <ctime>

static void printNumbers(const std::vector<int> &v, const std::string &label)
{
    std::cout << label;
    for (size_t i = 0; i < v.size(); ++i)
    {
        if (i) std::cout << " ";
        std::cout << v[i];
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    try
    {
        std::vector<int> numbers;
        parseInput(argc, argv, numbers);

        printNumbers(numbers, "Before: ");

        clock_t start_vec = clock();
        std::vector<int> sortedVec(numbers);
        sortVector(sortedVec);
        clock_t end_vec = clock();
        double timeVec = double(end_vec - start_vec) * 1e6 / CLOCKS_PER_SEC;

        printNumbers(sortedVec, "After : ");
        std::cout << "Time to process a range of " << numbers.size()
                  << " elements with std::vector : " << std::fixed << std::setprecision(2)
                  << timeVec << " us" << std::endl;

        std::deque<int> deq(numbers.begin(), numbers.end());
        clock_t start_deq = clock();
        sortDeque(deq);
        clock_t end_deq = clock();
        double timeDeque = double(end_deq - start_deq) * 1e6 / CLOCKS_PER_SEC;

        std::cout << "Time to process a range of " << deq.size()
                  << " elements with std::deque : " << std::fixed << std::setprecision(2)
                  << timeDeque << " us" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}