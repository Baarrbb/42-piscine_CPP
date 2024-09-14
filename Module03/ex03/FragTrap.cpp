/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:50:37 by marvin            #+#    #+#             */
/*   Updated: 2024/09/14 14:10:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_attackDamage = 30;
	std::cout << VERT "FragTrap default constructor called" RESET << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_attackDamage = 30;
	std::cout << VERT "FragTrap " << this->_name << " constructor called" RESET << std::endl;
}

FragTrap::FragTrap(FragTrap const &s) : ClapTrap(s)
{
	this->_name = s._name;
	this->_hitPoint = s._hitPoint;
	this->_energyPoint = s._energyPoint;
	this->_attackDamage = s._attackDamage;
	std::cout << VERT "FragTrap " << this->_name << " copy constructor called" RESET << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << ROUGE "FragTrap " << this->_name << " destructor called" RESET << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &f)
{
	std::cout << JAUNE "FragTrap copy assignment operator called" RESET << std::endl;
	if (&f == this)
		return *this;
	this->_name = f._name;
	this->_hitPoint = f._hitPoint;
	this->_energyPoint = f._energyPoint;
	this->_attackDamage = f._attackDamage;
	return *this;
}


int	FragTrap::getHitPoint(void) const
{
	return 100;
}

int	FragTrap::getEnergyPoint(void) const
{
	return 100;
}

int	FragTrap::getAttackPoint(void) const
{
	return 30;
}


void	FragTrap::highFivesGuys(void)
{
	if (this->_hitPoint <= 0)
	{
		std::cout << "FragTrap " << this->_name << " is dead." << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << " high five request accepted." << std::endl;
}
