/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:56:29 by marvin            #+#    #+#             */
/*   Updated: 2024/09/14 14:10:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << VERT "ScavTrap default constructor called" RESET << std::endl;
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;
	std::cout << VERT "ScavTrap " << this->_name << " constructor called" RESET << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &s) : ClapTrap(s)
{
	this->_name = s._name;
	this->_hitPoint = s._hitPoint;
	this->_energyPoint = s._energyPoint;
	this->_attackDamage = s._attackDamage;
	std::cout << VERT "ScavTrap " << this->_name << " copy constructor called" RESET << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << ROUGE "ScavTrap " << this->_name << " destructor called" RESET << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &s)
{
	std::cout << JAUNE "ScavTrap copy assignment operator called" RESET << std::endl;
	if (&s == this)
		return *this;
	this->_name = s._name;
	this->_hitPoint = s._hitPoint;
	this->_energyPoint = s._energyPoint;
	this->_attackDamage = s._attackDamage;
	return *this;
}


void	ScavTrap::guardGate(void)
{
	if (this->_hitPoint <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " is dead." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoint <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " has no hit point left." << std::endl;
		return ;
	}
	if (this->_energyPoint <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " has no energy point left." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target;
	std::cout << ", causing " << this->_attackDamage << " points of damage !" << std::endl;
	this->_energyPoint--;
}
