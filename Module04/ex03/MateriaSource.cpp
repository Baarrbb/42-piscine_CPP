/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:21:26 by marvin            #+#    #+#             */
/*   Updated: 2024/09/28 15:20:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->m[i] = NULL;
	std::cout << VERT "MateriaSource default constructor called" RESET << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &cpy)
{
	for (int i = 0; i < 4; i++)
	{
		// if (this->m[i] != NULL)
		// {
		// 	delete this->m[i];
		// 	this->m[i] = NULL;
		// }
		if (cpy.m[i] != NULL)
			this->m[i] = cpy.m[i]->clone();
		else
			this->m[i] = NULL;
	}
	std::cout << VERT "MateriaSource copy constructor called" RESET << std::endl;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->m[i] != NULL)
		{
			delete this->m[i];
			this->m[i] = NULL;
		}
	}
	std::cout << ROUGE "MateriaSource destructor called" RESET << std::endl;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &m)
{
	std::cout << JAUNE "MateriaSource affectation assignment operator called" RESET << std::endl;
	// if (this == &m)
	// 	return *this;
	for (int i = 0; i < 4; i++)
	{
		if (this->m[i] != NULL)
		{
			delete this->m[i];
			this->m[i] = NULL;
		}
		if (m.m[i] != NULL)
			this->m[i] = m.m[i]->clone();
		else
			this->m[i] = NULL;
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria *m)
{
	int i = 0;
	for (; i < 4; i++)
	{
		if (this->m[i] == NULL)
		{
			this->m[i] = m;
			break ;
		}
	}
	if (i == 4)
		delete m;
}

AMateria	*MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->m[i] && !this->m[i]->getType().compare(type))
		{
			return this->m[i]->clone();
		}
	}
	return 0;
}