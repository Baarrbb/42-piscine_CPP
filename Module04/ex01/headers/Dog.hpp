/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:04:53 by marvin            #+#    #+#             */
/*   Updated: 2024/06/25 14:48:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class	Dog : public Animal
{
	public:
	Dog(void);
	Dog(const Dog &);
	~Dog(void);
	Dog	&operator=(const Dog &);

	void	makeSound(void) const;

	private:
	Brain*	id;
};

#endif