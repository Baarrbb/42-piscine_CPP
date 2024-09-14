/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:56:21 by marvin            #+#    #+#             */
/*   Updated: 2024/06/15 21:59:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap
{
	public:
	ScavTrap(void);
	ScavTrap(std::string name);
	ScavTrap(ScavTrap const &);
	~ScavTrap(void);
	
	ScavTrap& operator=(ScavTrap const &);

	int		getHitPoint(void) const;
	int		getEnergyPoint(void) const;
	int		getAttackPoint(void) const;

	void		guardGate(void);
	void		attack(const std::string &target);
};

#endif