/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 19:35:45 by iel-asef          #+#    #+#             */
/*   Updated: 2026/02/14 19:35:46 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

void increment(int &x) {
    x += 5;
}

void printInt(const int &x) {
    std::cout << x << std::endl;
}

void toUpper(char &c) {
    if (c >= 'a' && c <= 'z')
        c = c - 32;
}

void printChar(const char &c) {
    std::cout << c << ' ';
}

int main() {
    std::cout << "=== Test int array ===" << std::endl;
    int intArr[5] = {1, 2, 3, 4, 5};

    iter(intArr, 5, increment);  
    iter(intArr, 5, printInt);  

    std::cout << "\n=== Test char array ===" << std::endl;
    char charArr[6] = {'a','b','c','d','e','f'};

    iter(charArr, 6, toUpper);
    iter(charArr, 6, printChar); 
    std::cout << std::endl;

    return 0;
}
