/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:07:11 by marvin            #+#    #+#             */
/*   Updated: 2024/09/15 15:27:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"
#include "Animal.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	this->id = new Brain();
	std::cout << VERT "Dog default constructor called" RESET << std::endl;
}

Dog::Dog(const Dog &d) : Animal(d)
{
	this->type = d.type;
	this->id = new Brain(*d.id);
	std::cout << VERT "Dog copy constructor called" RESET << std::endl;
}

Dog::~Dog(void)
{
	delete this->id;
	std::cout << ROUGE "Dog destructor called" RESET << std::endl;
}

Dog	&Dog::operator=(const Dog &d)
{
	if (this != &d)
	{
		this->type = d.type;
		delete this->id;
		this->id = new Brain(*d.id);
	}
	std::cout << JAUNE "Dog affectation assignment operator called" RESET << std::endl;
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << "Wouaf" << std::endl;
}
