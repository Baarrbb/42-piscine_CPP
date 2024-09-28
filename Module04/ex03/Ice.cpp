/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:07:32 by marvin            #+#    #+#             */
/*   Updated: 2024/09/28 15:20:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void)
{
	this->type = "ice";
	std::cout << VERT "Ice default constructor called" RESET << std::endl;
}

Ice::Ice(std::string const &type)
{
	this->type = type;
	std::cout << VERT "Ice " << this->type << " constructor called" RESET << std::endl;
}

Ice::Ice(const Ice &cpy)
{
	this->type = cpy.type;
	std::cout << VERT "Ice copy constructor called" RESET << std::endl;
}

Ice::~Ice(void)
{
	std::cout << ROUGE "Ice desstructor called" RESET << std::endl;
}

Ice	&Ice::operator=(const Ice &i)
{
	std::cout << JAUNE "Ice affectation assignment operator called" RESET << std::endl;
	if (this == &i)
		return *this;
	this->type = i.type;
	return *this;
}

Ice*	Ice::clone(void) const
{
	return new Ice();
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots ice bolt at " << target.getName() << " *" << std::endl;
}