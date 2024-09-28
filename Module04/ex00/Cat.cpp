/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:11:35 by marvin            #+#    #+#             */
/*   Updated: 2024/06/25 14:44:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << VERT "Cat default constructor called" RESET << std::endl;
}

Cat::Cat(const Cat &c) : Animal(c)
{
	this->type = c.type;
	std::cout << VERT "Cat copy constructor called" RESET << std::endl;
}

Cat::~Cat(void)
{
	std::cout << ROUGE "Cat destructor called" RESET << std::endl;
}

Cat	&Cat::operator=(const Cat &c)
{
	std::cout << JAUNE "Cat copy assignment operator called" RESET << std::endl;
	if (this == &c)
		return *this;
	this->type = c.type;
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "Miaou" << std::endl;
}
