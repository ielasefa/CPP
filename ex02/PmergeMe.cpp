/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 03:43:54 by iel-asef          #+#    #+#             */
/*   Updated: 2026/03/05 08:57:24 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <map>

void parseInput(int argc, char **argv, std::vector<int> &numbers)
{
    numbers.reserve(argc > 1 ? static_cast<size_t>(argc - 1) : 0);
    for (int i = 1; i < argc; ++i)
    {
        std::string arg(argv[i]);
        if (arg.empty())
            throw std::runtime_error("Error");

        for (size_t j = 0; j < arg.size(); ++j)
        {
            if (!std::isdigit(static_cast<unsigned char>(arg[j])))
                throw std::runtime_error("Error");
        }

        long num = std::atol(arg.c_str());
        if (num < 0 || num > 2147483647)
            throw std::runtime_error("Error");

        numbers.push_back(static_cast<int>(num));
    }

    if (numbers.empty())
        throw std::runtime_error("Error");
}

size_t jNumber(size_t n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return jNumber(n - 1) + 2 * jNumber(n - 2);
}

std::vector<size_t> buildInsertPlan(size_t size)
{
    std::vector<size_t> plan;
    size_t step = 1;
    
    while (jNumber(step) < size)
    {
        size_t current = jNumber(step);
        size_t previous = jNumber(step - 1);

        for (size_t i = current; i > previous; --i)
            plan.push_back(i - 1);

        step++;
    }

    return plan;
}

template<typename Container>
void insertWithBinary(Container& chain, int value, typename Container::iterator limit)
{
    typename Container::iterator pos =
        std::lower_bound(chain.begin(), limit, value);

    chain.insert(pos, value);
}

template<typename Container, typename PairList>
void addSmallValues(Container& chain, const PairList& pairList)
{
    std::vector<size_t> plan = buildInsertPlan(pairList.size());
    std::vector<bool> done(pairList.size(), false);

    for (size_t i = 0; i < plan.size(); ++i)
    {
        size_t id = plan[i];
        done[id] = true;

        int small = pairList[id].first;
        int big = pairList[id].second;

        typename Container::iterator bound =
            std::find(chain.begin(), chain.end(), big);

        insertWithBinary(chain, small, bound);
    }

    for (size_t i = 0; i < pairList.size(); ++i)
    {
        if (done[i])
            continue;

        int small = pairList[i].first;
        int big = pairList[i].second;

        typename Container::iterator bound =
            std::find(chain.begin(), chain.end(), big);

        insertWithBinary(chain, small, bound);
    }
}

template<typename Container>
void mergeInsertAlgo(Container& data)
{
    if (data.size() <= 1)
        return;

    typedef std::pair<int,int> PairType;

    std::vector<PairType> groups;

    bool leftover = false;
    int extra = 0;

    typename Container::size_type i = 0;

    for (; i + 1 < data.size(); i += 2)
    {
        int x = data[i];
        int y = data[i + 1];

        if (x > y)
            std::swap(x, y);

        groups.push_back(std::make_pair(x, y));
    }

    if (i < data.size())
    {
        leftover = true;
        extra = data[i];
    }

    Container sortedPart;

    for (size_t j = 0; j < groups.size(); ++j)
        sortedPart.push_back(groups[j].second);

    mergeInsertAlgo(sortedPart);

    addSmallValues(sortedPart, groups);

    if (leftover)
    {
        typename Container::iterator pos =
            std::lower_bound(sortedPart.begin(), sortedPart.end(), extra);

        sortedPart.insert(pos, extra);
    }

    data = sortedPart;
}

template<typename Container>
void fordJohnsonSort(Container& data)
{
    mergeInsertAlgo(data);
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
