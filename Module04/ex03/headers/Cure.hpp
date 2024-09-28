/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:16:39 by marvin            #+#    #+#             */
/*   Updated: 2024/06/18 14:17:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class	Cure : public AMateria
{
	public:
	Cure(void);
	Cure(std::string const &type);
	Cure(const Cure &);
	~Cure(void);

	Cure	&operator=(const Cure &);

	Cure*	clone(void) const;
	void	use(ICharacter &target);
};


#endif