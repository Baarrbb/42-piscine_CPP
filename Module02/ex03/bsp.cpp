/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:02:55 by marvin            #+#    #+#             */
/*   Updated: 2024/06/23 17:53:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float	planeEquation(Point const a, Point const b, Point const point)
{
	return (b.getX().toFloat() - a.getX().toFloat()) * (point.getY().toFloat() - a.getY().toFloat())
		- (b.getY().toFloat() - a.getY().toFloat()) * (point.getX().toFloat() - a.getX().toFloat());
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float ab = planeEquation(a, b, point);
	float bc = planeEquation(b, c, point);
	float ca = planeEquation(c, a, point);

	if (ab > 0 && bc > 0 && ca > 0)
		return true;
	if (ab < 0 && bc < 0 && ca < 0)
		return true;

	return false;
}
