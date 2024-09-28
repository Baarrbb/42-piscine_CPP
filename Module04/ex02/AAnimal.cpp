/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:53:24 by marvin            #+#    #+#             */
/*   Updated: 2024/09/15 19:31:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
	std::cout << VERT "AAnimal default construcotr called" RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal &a)
{
	this->type = a.type;
	std::cout << VERT "AAnimal copy construcotr called" RESET << std::endl;
}

AAnimal::~AAnimal(void)
{
	std::cout << ROUGE "AAnimal destructor called" RESET << std::endl;
}

AAnimal	&AAnimal::operator=(const AAnimal &a)
{
	if (this == &a)
		return *this;

	this->type = a.type;
	std::cout << JAUNE "AAnimal affectation assignment operator called" RESET << std::endl;
	return *this;
}


std::string	AAnimal::getType(void) const
{
	return this->type;
}


void	AAnimal::makeSound(void) const
{
	std::cout << "AAnimal sound ??" << std::endl;
}
