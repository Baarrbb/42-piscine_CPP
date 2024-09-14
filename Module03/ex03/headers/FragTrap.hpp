/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:50:27 by marvin            #+#    #+#             */
/*   Updated: 2024/06/15 21:59:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{
	public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(FragTrap const &);
	~FragTrap(void);
	
	FragTrap& operator=(FragTrap const &);

	int		getHitPoint(void) const;
	int		getEnergyPoint(void) const;
	int		getAttackPoint(void) const;

	void	highFivesGuys(void);
};

#endif