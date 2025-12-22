/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 23:59:24 by iel-asef          #+#    #+#             */
/*   Updated: 2025/12/22 01:23:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "=== Test 1: Creating animals ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << "\n=== Test 2: Getting types and sounds ===" << std::endl;
    std::cout << "Dog type: " << j->getType() << std::endl;
    std::cout << "Cat type: " << i->getType() << std::endl;
    std::cout << "Cat sound: "; i->makeSound();
    std::cout << "Dog sound: "; j->makeSound();
    std::cout << "Animal sound: "; meta->makeSound();

    std::cout << "\n=== Test 3: Copying animals ===" << std::endl;
    Dog originalDog;
    Dog copiedDog = originalDog; // Copy constructor
    Dog assignedDog;
    assignedDog = originalDog; // Assignment operator
    
    std::cout << "\n=== Test 4: Cleanup ===" << std::endl;
    delete meta;
    delete j;
    delete i;
    
    std::cout << "\n=== Test 5: Stack objects destroyed ===" << std::endl;
    return 0;
}