/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 17:55:45 by iel-asef          #+#    #+#             */
/*   Updated: 2026/02/14 18:07:21 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept> 

template <typename T>
class Array
{
    private:
        T*              _array;
        unsigned int    _size;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array &src);
        ~Array();
		
        Array &operator=(const Array &other);
        T &operator[](unsigned int index);
        unsigned int size() const;
};

template <typename T>
Array<T>::Array() : _array(NULL), _size(0){}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n){}

template <typename T>
Array<T>::Array(const Array &other) : _array(new T[other._size]), _size(other._size)
{
    for (unsigned int i = 0; i < _size; i++)
        _array[i] = other._array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    if (this != &other)
    {
        delete[] _array;
        _size = other._size;
        _array = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
            _array[i] = other._array[i];
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw std::out_of_range("Array index out of bounds");
    return _array[index];
}

template <typename T>
Array<T>::~Array()
{
    delete[] _array;
}

template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}

#endif
