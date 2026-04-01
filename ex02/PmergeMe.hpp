#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cctype>
#include <utility>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();
};

void parseInput(int argc, char **argv, std::vector<int> &numbers);
std::vector<size_t> buildInsertPlan(size_t size);
size_t jNumber(size_t n);

template<typename Container>
void insertWithBinary(Container& chain, int value,
    typename Container::iterator limit)
{
    typename Container::iterator pos;

    pos = std::lower_bound(chain.begin(), limit, value);
    chain.insert(pos, value);
}

template<typename Container, typename PairList>
void addSmallValues(Container& chain, const PairList& pairList)
{
    std::vector<size_t> plan;
    std::vector<bool> done;
    size_t i;
    size_t id;
    int small;
    int big;
    typename Container::iterator bound;

    plan = buildInsertPlan(pairList.size());
    done = std::vector<bool>(pairList.size(), false);

    i = 0;
    while (i < plan.size())
    {
        id = plan[i];
        done[id] = true;

        small = pairList[id].first;
        big = pairList[id].second;

        bound = std::find(chain.begin(), chain.end(), big);
        insertWithBinary(chain, small, bound);
        i++;
    }

    i = 0;
    while (i < pairList.size())
    {
        if (!done[i])
        {
            small = pairList[i].first;
            big = pairList[i].second;

            bound = std::find(chain.begin(), chain.end(), big);
            insertWithBinary(chain, small, bound);
        }
        i++;
    }
}

template<typename Container>
void mergeInsertAlgo(Container& data)
{
    typedef std::pair<int,int> PairType;

    std::vector<PairType> groups;
    Container sortedPart;
    typename Container::size_type i;
    bool leftover;
    int extra;
    int x;
    int y;

    if (data.size() <= 1)
        return;

    i = 0;
    while (i + 1 < data.size())
    {
        x = data[i];
        y = data[i + 1];

        if (x > y)
            std::swap(x, y);

        groups.push_back(std::make_pair(x, y));
        i += 2;
    }

    leftover = (i < data.size());
    if (leftover)
        extra = data[i];

    i = 0;
    while (i < groups.size())
    {
        sortedPart.push_back(groups[i].second);
        i++;
    }

    mergeInsertAlgo(sortedPart);
    addSmallValues(sortedPart, groups);

    if (leftover)
    {
        typename Container::iterator pos;

        pos = std::lower_bound(sortedPart.begin(),
                               sortedPart.end(), extra);
        sortedPart.insert(pos, extra);
    }

    data = sortedPart;
}

template<typename Container>
void fordJohnsonSort(Container& data)
{
    mergeInsertAlgo(data);
}

void sortVector(std::vector<int> &vec);
void sortDeque(std::deque<int> &deq);

#endif