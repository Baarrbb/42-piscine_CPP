/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:05:48 by marvin            #+#    #+#             */
/*   Updated: 2024/09/24 17:29:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template< typename T >
void	swap(T &x, T &y)
{
	T tmp = x;
	x = y;
	y = tmp;
}

template< typename T >
T	min( T const &x, T const &y )
{
	return ( (x > y) ? y : x);
}

template< typename T >
T	max( T const &x, T const &y )
{
	return ( (x > y) ? x : y);
}

#endif