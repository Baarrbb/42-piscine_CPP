/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:17:15 by marvin            #+#    #+#             */
/*   Updated: 2024/09/28 15:20:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void)
{
	this->type = "cure";
	std::cout << VERT "Cure default constructor called" RESET << std::endl;
}

Cure::Cure(std::string const &type)
{
	this->type = type;
	std::cout << VERT "Cure " << this->type << " constructor called" RESET << std::endl;
}

Cure::Cure(const Cure &cpy)
{
	this->type = cpy.type;
	std::cout << VERT "Cure copy constructor called" RESET << std::endl;
}

Cure::~Cure(void)
{
	std::cout << ROUGE "Cure desstructor called" RESET << std::endl;
}

Cure	&Cure::operator=(const Cure &i)
{
	std::cout << JAUNE "Cure affectation assignment operator called" RESET << std::endl;
	if (this == &i)
		return *this;
	this->type = i.type;
	return *this;
}

Cure*	Cure::clone(void) const
{
	return new Cure();
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
