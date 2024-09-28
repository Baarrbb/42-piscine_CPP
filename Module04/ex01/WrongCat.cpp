/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:54:24 by marvin            #+#    #+#             */
/*   Updated: 2024/06/25 15:03:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->type = "WrongCat";
	std::cout << VERT "WrongCat default constructor called" RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &w) : WrongAnimal(w)
{
	this->type = w.type;
	std::cout << VERT "WrongCat copy constructor called" RESET << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << ROUGE "WrongCat destructor called" RESET << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &w)
{
	if (this == &w)
		return *this;
	std::cout << JAUNE "WrongCat affectation assignment operator called" RESET << std::endl;
	this->type = w.type;
	return *this;
}


void	WrongCat::makeSound(void) const
{
	std::cout << "Wrong miaou" << std::endl;
}
