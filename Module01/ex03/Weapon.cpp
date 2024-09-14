/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:33:51 by marvin            #+#    #+#             */
/*   Updated: 2024/06/22 19:44:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{
	std::cout << VERT "Weapon default constructor called" RESET << std::endl;
}

Weapon::Weapon(std::string type) : _type(type)
{
	std::cout << VERT "Weapon " << this->_type << " constructor called" RESET << std::endl;
}

Weapon::~Weapon(void)
{
	std::cout << ROUGE "Weapon " << this->_type << " destructor called" RESET << std::endl;
}

std::string	Weapon::getType(void) const
{
	return this->_type;
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}
