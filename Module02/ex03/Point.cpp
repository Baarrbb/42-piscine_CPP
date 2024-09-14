/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:24:53 by marvin            #+#    #+#             */
/*   Updated: 2024/06/23 17:20:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
	// std::cout << VERT "Point constructor called" RESET << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
	// std::cout << VERT "Point constructor called" RESET << std::endl;
}

Point::Point(const Point &p) : _x(p._x), _y(p._y)
{
	// std::cout << VERT "Point constructor called" RESET << std::endl;
}

Point::~Point(void)
{
	// std::cout << ROUGE "Point destructor called" RESET << std::endl;
}

Point	&Point::operator=(const Point &p)
{
	// std::cout << JAUNE "Point copy assignment constructor called" RESET << std::endl;
	if (this == &p)
		return *this;
	(Fixed)_x = p.getX();
	(Fixed)_y = p.getY();
	return *this;
}


Fixed	Point::getX(void) const
{
	return this->_x;
}

Fixed	Point::getY(void) const
{
	return this->_y;
}

