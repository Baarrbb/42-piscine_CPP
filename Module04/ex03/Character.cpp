/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:26:40 by marvin            #+#    #+#             */
/*   Updated: 2024/09/28 15:20:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void)
{
	this->name = "Unknown";
	for (int i = 0; i < 4; i++)
		this->m[i] = NULL;
	std::cout << VERT "Character default constructor called" RESET << std::endl;
}

Character::Character(std::string name)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
		this->m[i] = NULL;
	std::cout << VERT "Character " << this->name << " constructor called" RESET << std::endl;
}

Character::Character(const Character &cpy)
{
	this->name = cpy.name;
	for (int i = 0; i < 4; i++)
	{
		if (cpy.m[i] != NULL)
			this->m[i] = cpy.m[i]->clone();
		else
			this->m[i] = NULL;
	}
	std::cout << VERT "Character " << this->name << " copy constructor called" RESET << std::endl;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->m[i] != NULL)
		{
			delete this->m[i];
			this->m[i] = NULL;
		}
	}
	std::cout << ROUGE "Character destructor called" RESET << std::endl;
}

Character	&Character::operator=(const Character &c)
{
	std::cout << JAUNE "Character copy assignment operator called" RESET << std::endl;
	// if (this == &c)
	// 	return *this;
	this->name = c.name;
	for (int i = 0; i < 4; i++)
	{
		if (this->m[i] != NULL)
		{
			delete this->m[i];
			this->m[i] = NULL;
		}
		if (c.m[i] != NULL)
			this->m[i] = c.m[i]->clone();
		else
			this->m[i] = NULL;
	}
	return *this;
}

std::string const	&Character::getName(void) const
{
	return this->name;
}

void	Character::equip(AMateria *m)
{
	int i = 0;
	for (; i < 4; i++)
	{
		if (this->m[i] == NULL && m != NULL)
		{
			this->m[i] = m;
			break ;
		}
	}
	if(i == 4)
		delete m;
}

void	Character::unequip(int idx)
{
	if (idx > 3 || idx < 0)
	{
		std::cout << RED "Wrong index, only between 0 and 3" RESET << std::endl;
		return ;
	}
	this->m[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx > 3 || idx < 0)
		std::cout << RED "Wrong index, only between 0 and 3" RESET << std::endl;
	else if (m[idx] == NULL)
	{
		std::cout << RED "No Materia at this index" RESET << std::endl;
	}
	else
	{
		// std::cout << "Character " << this->name << " using ";
		m[idx]->use(target);
	}
	
}
