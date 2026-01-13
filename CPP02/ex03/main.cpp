/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:47:18 by iel-asef          #+#    #+#             */
/*   Updated: 2025/11/12 09:47:18 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main() 
{
    Point A(0, 0);
    Point B(4, 0);
    Point C(0, 4);

    Point P1(1, 1);   
    Point P2(2, 0);   
    Point P3(5, 5);  

    std::cout << std::boolalpha;

    std::cout << "P1 inside: " << bsp(A, B, C, P1) << std::endl;
    std::cout << "P2 on edge: " << bsp(A, B, C, P2) << std::endl;
    std::cout << "P3 outside: " << bsp(A, B, C, P3) << std::endl;

    return 0;
}
