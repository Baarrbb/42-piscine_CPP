/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:53:24 by marvin            #+#    #+#             */
/*   Updated: 2024/09/15 13:58:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	this->type = "Animal";
	std::cout << VERT "Animal default constructor called" RESET << std::endl;
}

Animal::Animal(const Animal &a)
{
	this->type = a.type;
	std::cout << VERT "Animal copy constructor called" RESET << std::endl;
}

Animal::~Animal(void)
{
	std::cout << ROUGE "Animal destructor called" RESET << std::endl;
}

Animal	&Animal::operator=(const Animal &a)
{
	std::cout << JAUNE "Animal copy assignment operator called" RESET << std::endl;
	if (this == &a)
		return *this;

	this->type = a.type;
	return *this;
}


std::string	Animal::getType(void) const
{
	return this->type;
}


void	Animal::makeSound(void) const
{
	std::cout << "Animal sound ??" << std::endl;
}