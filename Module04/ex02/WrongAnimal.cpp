/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:49:24 by marvin            #+#    #+#             */
/*   Updated: 2024/06/25 15:57:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	this->type = "WrongAnimal";
	std::cout << VERT "WrongAnimal default constructor called" RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &w)
{
	this->type = w.type;
	std::cout << VERT "WrongAnimal copy constructor called" RESET << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << ROUGE "WrongAnimal destructor called" RESET << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &w)
{
	if (this == &w)
		return *this;
	std::cout << JAUNE "WrongAnimal affectation assignment operator called" RESET << std::endl;
	this->type = w.type;
	return *this;
}

std::string	WrongAnimal::getType(void) const
{
	return this->type;
}


void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal sound ??" << std::endl;
}
