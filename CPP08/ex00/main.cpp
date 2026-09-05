/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 14:41:33 by iel-asef          #+#    #+#             */
/*   Updated: 2026/02/15 23:53:02 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    std::vector<int> v;
    std::list<int> l;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

    try
    {
        easyfind(v, 1);
        std::cout << "2 found in vector ✅" << std::endl;

        easyfind(v, 20); 
        std::cout << "100 found in vector ✅" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Value not found in vector ❌" << std::endl;
    }

    try
    {
        easyfind(l, 20);
        std::cout << "20 found in list ✅" << std::endl;

        easyfind(l, 5); 
        std::cout << "5 found in list ✅" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Value not found in list ❌" << std::endl;
    }

    return 0;
}
