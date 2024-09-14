/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:24:51 by marvin            #+#    #+#             */
/*   Updated: 2024/06/23 17:17:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class	Point
{
	public:
	Point(void);
	Point(const float, const float);
	Point(const Point&);
	~Point(void);

	Point	&operator=(const Point &);

	Fixed	getX(void) const;
	Fixed	getY(void) const;

	private:
	const Fixed	_x;
	const Fixed	_y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif