/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:54:54 by marvin            #+#    #+#             */
/*   Updated: 2024/09/14 14:06:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _valueNbFixed(0)
{
	std::cout << VERT "Default constructor called" RESET << std::endl;
}

Fixed::Fixed(int const nb)
{
	this->_valueNbFixed = (nb << this->_nbBits);
	std::cout << VERT "Int constructor called" RESET << std::endl;
}

Fixed::Fixed(const float nb)
{
	this->_valueNbFixed = roundf(nb * (1 << this->_nbBits));
	std::cout << VERT "Float constructor called" RESET << std::endl;
}

Fixed::Fixed(const Fixed &f) : _valueNbFixed(f._valueNbFixed)
{
	std::cout << VERT "Copy constructor called" RESET << std::endl;
}

Fixed &Fixed::operator=(const Fixed &f)
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
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_valueNbFixed;
}

void	Fixed::setRawBits(int const raw)
{
	this->_valueNbFixed = raw;
}

float	Fixed::toFloat(void) const
{
	return this->_valueNbFixed / (float)(1 << this->_nbBits);
}

int		Fixed::toInt(void) const
{
	return this->_valueNbFixed / (1 << this->_nbBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed &f)
{
	os << f.toFloat();
	return os;
}
