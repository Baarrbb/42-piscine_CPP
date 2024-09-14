/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 18:08:36 by marvin            #+#    #+#             */
/*   Updated: 2024/09/14 14:10:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class	DiamondTrap : public FragTrap, public ScavTrap
{
	public:
	DiamondTrap(void);
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap const &);
	~DiamondTrap(void);

	DiamondTrap& operator=(const DiamondTrap &);


	void	attack(const std::string &target);
	void	whoAmI(void);

	int		getHitPoint(void) const;
	int		getEnergyPoint(void) const;
	int		getAttackPoint(void) const;

	private:
	std::string	_name;
};

#endif