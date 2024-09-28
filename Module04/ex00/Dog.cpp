/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:07:11 by marvin            #+#    #+#             */
/*   Updated: 2024/06/25 14:46:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	std::cout << VERT "Dog default constructor called" RESET << std::endl;
}

Dog::Dog(const Dog &d) : Animal(d)
{
	this->type = d.type;
	std::cout << VERT "Dog copy constructor called" RESET << std::endl;
}

Dog::~Dog(void)
{
	std::cout << ROUGE "Dog destructor called" RESET << std::endl;
}

Dog	&Dog::operator=(const Dog &d)
{
	std::cout << JAUNE "Dog copy assignment operator called" RESET << std::endl;
	if (this == &d)
		return *this;
	this->type = d.type;
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << "Wouaf" << std::endl;
}
