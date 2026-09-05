/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:53:13 by iel-asef          #+#    #+#             */
/*   Updated: 2026/01/15 19:53:14 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "data.hpp"

int main()
{
    Data data;

    data.name = "test";
    data.number = 42;

    Data* originalPtr = &data;

    uintptr_t raw = Serializer::serialize(originalPtr);

    Data* newPtr = Serializer::deserialize(raw);

    std::cout << "Original pointer : " << originalPtr << std::endl;
    std::cout << "Deserialized ptr : " << newPtr << std::endl;

    if (originalPtr == newPtr)
        std::cout << "✅ Same pointer, OK!" << std::endl;
    else
        std::cout << "❌ Different pointer, ERROR!" << std::endl;

    std::cout << "Data values: name = " << newPtr->name
              << ", number = " << newPtr->number << std::endl;

    return 0;
}
