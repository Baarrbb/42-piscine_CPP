/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:50:27 by marvin            #+#    #+#             */
/*   Updated: 2024/06/15 18:05:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(FragTrap const &);
	~FragTrap(void);
	
	FragTrap& operator=(FragTrap const &);

	void	highFivesGuys(void);
};

#endif