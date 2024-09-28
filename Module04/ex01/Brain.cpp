/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:17:27 by marvin            #+#    #+#             */
/*   Updated: 2024/09/28 15:20:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << VERT "Brain default constructor called" RESET << std::endl;
}

Brain::Brain(const Brain &b)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = b.ideas[i];
	std::cout << VERT "Brain copy constructor called" RESET << std::endl;
}

Brain::~Brain(void)
{
	std::cout << ROUGE "Brain destructor called" RESET << std::endl;
}

Brain	&Brain::operator=(const Brain &b)
{
	if (this == &b)
		return *this;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = b.ideas[i];
	std::cout << JAUNE "Brain affectation assignment operator called" RESET << std::endl;
	return *this;
}



// std::string Brain::getIdea(int i)
// {
// 	return this->ideas[i];
// }

// void	Brain::setIdea(int i, std::string s)
// {
// 	this->ideas[i] = s;
// }
