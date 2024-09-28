/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:11:05 by marvin            #+#    #+#             */
/*   Updated: 2024/06/25 15:55:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class	Cat : public AAnimal
{
	public:
	Cat(void);
	Cat(const Cat &);
	~Cat(void);
	Cat	&operator=(const Cat &);

	void	makeSound(void) const;

	private:
	Brain* id;
};

#endif