/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 03:45:29 by iel-asef          #+#    #+#             */
/*   Updated: 2026/03/05 08:30:43 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <set>
#include <ctime>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cctype>
#include <utility>

void parseInput(int argc, char **argv, std::vector<int> &numbers);
template<typename Container>
void insertWithBinary(Container& chain, int value, typename Container::iterator limit);
template<typename Container, typename PairList> 
void addSmallValues(Container& chain, const PairList& pairList);
std::vector<size_t> buildInsertPlan(size_t size);
size_t jNumber(size_t n);

template<typename Container>
void fordJohnsonSort(Container& data);
void sortVector(std::vector<int> &vec);
void sortDeque(std::deque<int> &deq);

#endif
