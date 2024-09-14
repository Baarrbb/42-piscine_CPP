/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:13:34 by marvin            #+#    #+#             */
/*   Updated: 2024/06/22 19:26:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << VERT "Zombie default constructor called" RESET << std::endl;
}

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << VERT "Zombie " << this->_name << " constructor called" RESET << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << ROUGE "Zombie " << this->_name << " destructor called" RESET << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(std::string name)
{
	this->_name = name;
}