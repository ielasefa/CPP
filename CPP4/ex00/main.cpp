/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 23:59:24 by iel-asef          #+#    #+#             */
/*   Updated: 2025/12/21 00:31:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

// int main()
// {
//     const Animal* meta = new Animal();
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();
//     std::cout << j->getType() << " " << std::endl;
//     std::cout << i->getType() << " " << std::endl;
//     i->makeSound(); //will output the cat sound!
//     j->makeSound();
//     meta->makeSound();

//     delete meta;
//     delete j;
//     delete i;
// }

int main()
{
    std::cout << "=== Correct polymorphism ===" << std::endl;

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << "Animal sound: ";
    meta->makeSound();

    std::cout << "Dog sound: ";
    j->makeSound();

    std::cout << "Cat sound: ";
    i->makeSound();
    
    std::cout << "\n=== Wrong polymorphism ===" << std::endl;

    const WrongAnimal* wrong = new WrongCat();

    std::cout << "WrongAnimal sound: ";
    wrong->makeSound();

    delete wrong;
    delete meta;
    delete j;
    delete i;
    return 0;
}
