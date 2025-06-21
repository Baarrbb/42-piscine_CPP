/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:39:52 by marvin            #+#    #+#             */
/*   Updated: 2025/02/18 15:46:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template< typename T, typename U, typename V>
void	iter(T *tab, U const size, V func)
{
	if (!tab || !func)
		return ;
	for (U i = 0; i < size; i++)
		func(tab[i]);
}

#endif