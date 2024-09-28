/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:04:35 by marvin            #+#    #+#             */
/*   Updated: 2024/06/18 14:14:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class	Ice : public AMateria
{
	public:
	Ice(void);
	Ice(std::string const &type);
	Ice(const Ice &);
	~Ice(void);

	Ice	&operator=(const Ice &);

	Ice*	clone(void) const;
	void	use(ICharacter &target);
};


#endif