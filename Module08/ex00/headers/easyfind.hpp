/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:20:51 by marvin            #+#    #+#             */
/*   Updated: 2025/02/18 16:19:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

/*
template< typename T >
void	easyfind(T cont, int const val)
{
	typename T::const_iterator	it = cont.begin();
	typename T::const_iterator	ite = cont.end();
	typename T::const_iterator res = find(it, ite, val);

	if (res == ite)
		throw std::runtime_error("Value not found.");
	std::cout << "Element " << *res << " found." << std::endl;
}
*/

template< typename T >
void	easyfind(T cont, int val)
{
	typename T::const_iterator res;

	if ((res = find(cont.begin(), cont.end(), val)) != cont.end())
		std::cout << "Element " << *res << " found." << std::endl;
	else
		throw std::runtime_error("Value not found.");
}


#endif
