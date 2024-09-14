/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 18:08:56 by marvin            #+#    #+#             */
/*   Updated: 2024/09/14 14:10:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("_clap_name"), FragTrap(), ScavTrap()
{
	std::cout << VERT "DiamondTrap default constructor called" RESET << std::endl;

	this->_hitPoint = FragTrap::getHitPoint();
	this->_energyPoint = ScavTrap::getEnergyPoint();
	this->_attackDamage = FragTrap::getAttackPoint();
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	std::cout << VERT "DiamondTrap " << this->_name << " constructor called" RESET << std::endl;
	this->_hitPoint = FragTrap::getHitPoint();
	this->_energyPoint = ScavTrap::getEnergyPoint();
	this->_attackDamage = FragTrap::getAttackPoint();
}

DiamondTrap::DiamondTrap(DiamondTrap const &d) : ClapTrap(d), FragTrap(d), ScavTrap(d)
{
	this->_name = d._name;
	this->_hitPoint = d._hitPoint;
	this->_energyPoint = d._energyPoint;
	this->_attackDamage = d._attackDamage;
	std::cout << VERT "DiamondTrap " << this->_name << " constructor called" RESET << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << ROUGE "DiamondTrap " << this->_name << " destructor called" RESET << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &d)
{
	std::cout << JAUNE "DiamondTrap copy assignment operator called" RESET << std::endl;
	if (&d == this)
		return *this;
	this->_name = d._name;
	this->_hitPoint = d._hitPoint;
	this->_energyPoint = d._energyPoint;
	this->_attackDamage = d._attackDamage;
	return *this;
}

// Getters

int		DiamondTrap::getHitPoint(void) const
{
	return this->_hitPoint;
}
int		DiamondTrap::getEnergyPoint(void) const
{
	return this->_energyPoint;
}

int		DiamondTrap::getAttackPoint(void) const
{
	return this->_attackDamage;
}


void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "My name is " << this->_name << std::endl;
	std::cout << "ClapTrap name is " << ClapTrap::_name << std::endl;
}
