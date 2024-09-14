/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:33:45 by marvin            #+#    #+#             */
/*   Updated: 2024/09/14 14:03:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(void)
{
	this->_weapon = NULL;
	std::cout << VERT "HumanB default constructor called" RESET << std::endl;
}

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_weapon = NULL;
	std::cout << VERT "HumanB " << this->_name << " constructor called" RESET << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << ROUGE "HumanB " << this->_name << " destructor called" RESET << std::endl;
}

void	HumanB::attack(void)
{
	if (!this->_weapon)
		std::cout << this->_name << " attacks with nothing";
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType();
	std::cout << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}