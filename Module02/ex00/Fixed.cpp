/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:54:54 by marvin            #+#    #+#             */
/*   Updated: 2024/06/23 15:18:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _valueNbFixed(0)
{
	std::cout << VERT "Default constructor called" RESET << std::endl;
}

Fixed::Fixed(const Fixed &f) : _valueNbFixed(f._valueNbFixed)
{
	std::cout << VERT "Copy constructor called" RESET << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &f)
{
	std::cout << JAUNE "Copy assignment operator called" RESET << std::endl;
	if (this == &f)
		return *this;

	this->_valueNbFixed = f.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << ROUGE "Destructor called" RESET << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_valueNbFixed;
}

void	Fixed::setRawBits(int const raw)
{
	this->_valueNbFixed = raw;
}
