/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:17:05 by marvin            #+#    #+#             */
/*   Updated: 2024/09/14 14:09:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << VERT "ClapTrap default constructor called" RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << VERT "ClapTrap " << this->_name << " constructor called" RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &c) :
	_name(c._name), _hitPoint(c._hitPoint), _energyPoint(c._energyPoint), _attackDamage(c._attackDamage)
{
	std::cout << VERT "ClapTrap " << this->_name << " copy constructor called" RESET << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << ROUGE "ClapTrap " << this->_name << " destructor called" RESET << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &c)
{
	std::cout << JAUNE "ClapTrap copy assignment operator called" RESET << std::endl;
	if (this == &c)
		return *this;

	this->_name = c._name;
	this->_hitPoint = c._hitPoint;
	this->_energyPoint = c._energyPoint;
	this->_attackDamage = c._attackDamage;
	return *this;
}


void	ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoint <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no hit point left." << std::endl;
		return ;
	}
	if (this->_energyPoint <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy point left." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target;
	std::cout << ", causing " << this->_attackDamage << " points of damage !" << std::endl;
	this->_energyPoint--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoint <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no hit point left." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " take " << amount << " points of damage." << std::endl;
	this->_hitPoint -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoint <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no hit point left." << std::endl;
		return ;
	}
	if (this->_energyPoint <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy point left." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " repairs itself. It gets ";
	std::cout << amount << " hit points back" << std::endl;
	this->_hitPoint += amount;
	this->_energyPoint--;
}
