/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <iel-asef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:22:20 by iel-asef          #+#    #+#             */
/*   Updated: 2025/12/17 22:23:55 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		this->_learned[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource const &copy)
{
	for (int i = 0; i < 4; ++i)
	{
		if (copy._learned[i])
			this->_learned[i] = copy._learned[i]->clone();
		else
			this->_learned[i] = 0;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (this->_learned[i])
			{
				delete this->_learned[i];
				this->_learned[i] = 0;
			}
			if (other._learned[i])
				this->_learned[i] = other._learned[i]->clone();
			else
				this->_learned[i] = 0;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->_learned[i])
		{
			delete this->_learned[i];
			this->_learned[i] = 0;
		}
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; ++i)
	{
		if (!this->_learned[i])
		{
			this->_learned[i] = m;
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->_learned[i] && this->_learned[i]->getType() == type)
			return (this->_learned[i]->clone());
	}
	return (0);
}
