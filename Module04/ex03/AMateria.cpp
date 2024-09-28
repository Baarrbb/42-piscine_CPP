/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:44:05 by marvin            #+#    #+#             */
/*   Updated: 2024/09/15 19:43:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void)
{
	std::cout << VERT "AMateria default constructor called" RESET << std::endl;
}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
	std::cout << VERT "AMateria " << this->type << " constructor called" RESET << std::endl;
}

AMateria::AMateria(const AMateria &cpy)
{
	this->type = cpy.type;
	std::cout << VERT "AMateria copy constructor called" RESET << std::endl;
}

AMateria::~AMateria(void)
{
	std::cout << ROUGE "AMateria destructor called" RESET << std::endl;
}

AMateria	&AMateria::operator=(const AMateria &a)
{
	std::cout << JAUNE "AMateria affectation assignment operator called" RESET << std::endl;
	if (this == &a)
		return *this;
	this->type = a.type;
	return *this;
}


std::string	const &AMateria::getType(void) const
{
	return this->type;
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "AMateria use " << target.getName() << std::endl;
}
