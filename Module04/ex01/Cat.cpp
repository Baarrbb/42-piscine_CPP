/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:11:35 by marvin            #+#    #+#             */
/*   Updated: 2024/09/28 15:20:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"
#include "Animal.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	this->id = new Brain();
	std::cout << VERT "Cat default constructor called" RESET << std::endl;
}

Cat::Cat(const Cat &c) : Animal(c)
{
	this->type = c.type;
	this->id = new Brain(*c.id);
	std::cout << VERT "Cat copy constructor called" RESET << std::endl;
}

Cat::~Cat(void)
{
	delete this->id;
	std::cout << ROUGE "Cat destructor called" RESET << std::endl;
}

Cat	&Cat::operator=(const Cat &c)
{
	if (this != &c)
	{
		this->type = c.type;
		delete this->id;
		this->id = new Brain(*c.id);
	}
	std::cout << JAUNE "Cat affectation assignment operator called" RESET << std::endl;
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "Miaou" << std::endl;
}



// std::string Cat::getId(int i)
// {
// 	return this->id[i].getIdea(i);
// }

// void	Cat::setId(int i, std::string s)
// {
// 	this->id[i].setIdea(i, s);
// }
