/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:54:54 by marvin            #+#    #+#             */
/*   Updated: 2024/06/23 17:06:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _valueNbFixed(0)
{
	// std::cout << VERT "Default constructor called" RESET << std::endl;
}

Fixed::Fixed(int const nb)
{
	this->_valueNbFixed = nb * (1 << this->_nbBits);
	// std::cout << VERT "Int constructor called" RESET << std::endl;
}

Fixed::Fixed(const float nb)
{
	this->_valueNbFixed = roundf(nb * (1 << this->_nbBits));
	// std::cout << VERT "Float constructor called" RESET << std::endl;
}

Fixed::Fixed(const Fixed &f) : _valueNbFixed(f._valueNbFixed)
{
	// std::cout << VERT "Copy constructor called" RESET << std::endl;
}

Fixed::~Fixed(void)
{
	// std::cout << ROUGE "Destructor called" RESET << std::endl;
}

Fixed &Fixed::operator=(const Fixed &f)
{
	if (this == &f)
		return *this;

	// std::cout << JAUNE "Copy assignment operator called" RESET << std::endl;
	this->_valueNbFixed = f.getRawBits();
	return *this;
}


bool	Fixed::operator>(const Fixed &f) const
{
	if (this->_valueNbFixed > f.getRawBits())
		return true;
	else
		return false;
}

bool	Fixed::operator<(const Fixed &f) const
{
	if (this->_valueNbFixed < f.getRawBits())
		return true;
	else
		return false;
}

bool	Fixed::operator>=(const Fixed &f) const
{
	if (this->_valueNbFixed >= f.getRawBits())
		return true;
	else
		return false;
}

bool	Fixed::operator<=(const Fixed &f) const
{
	if (this->_valueNbFixed <= f.getRawBits())
		return true;
	else
		return false;
}

bool	Fixed::operator==(const Fixed &f) const
{
	if (this->_valueNbFixed == f.getRawBits())
		return true;
	else
		return false;
}

bool	Fixed::operator!=(const Fixed &f) const
{
	if (this->_valueNbFixed != f.getRawBits())
		return true;
	else
		return false;
}


Fixed	Fixed::operator+(const Fixed &f)
{
	Fixed tmp;
	tmp._valueNbFixed = this->_valueNbFixed + f._valueNbFixed;
	return tmp;
}

Fixed	Fixed::operator-(const Fixed &f)
{
	Fixed tmp;
	tmp._valueNbFixed = this->_valueNbFixed - f._valueNbFixed;
	return tmp;
}

Fixed	Fixed::operator*(const Fixed &f)
{
	Fixed tmp;
	tmp._valueNbFixed = this->_valueNbFixed * f.toFloat();
	return tmp;
}

Fixed	Fixed::operator/(const Fixed &f)
{
	Fixed tmp;
	tmp._valueNbFixed = this->_valueNbFixed / f.toFloat();
	return tmp;
}


Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	this->_valueNbFixed++;
	return tmp;
}

Fixed	&Fixed::operator++(void)
{
	this->_valueNbFixed++;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	this->_valueNbFixed--;
	return tmp;
}

Fixed	&Fixed::operator--(void)
{
	this->_valueNbFixed--;
	return *this;
}


const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	else
		return b;
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	else
		return b;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	else
		return b;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	else
		return b;
}


int	Fixed::getRawBits(void) const
{
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
	os << f.toFloat();;
	return os;
}
