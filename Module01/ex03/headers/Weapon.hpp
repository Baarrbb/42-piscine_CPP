/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:33:54 by marvin            #+#    #+#             */
/*   Updated: 2024/06/22 19:52:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

# define RESET "\033[0m"
# define ROUGE "\033[38;5;88m"
# define VERT "\033[38;5;29m"
# define YELLOW "\x1B[33m"

class	Weapon
{
	public:
	Weapon(void);
	Weapon(std::string type);
	~Weapon(void);

	std::string	getType(void) const;
	void		setType(std::string type);

	private:
	std::string	_type;
};

#endif