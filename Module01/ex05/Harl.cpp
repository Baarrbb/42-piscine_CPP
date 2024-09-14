/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:40:23 by marvin            #+#    #+#             */
/*   Updated: 2024/09/14 14:03:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << VERT "Harl default constructor called" RESET << std::endl;
}

Harl::~Harl(void)
{
	std::cout << ROUGE "Harl default destructor called" RESET << std::endl;
}

void	Harl::debug(void)
{
	std::cout << "1 - I love having extra bacon for my "
	<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "
	<< "I really do !" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "2 - I cannot believe adding extra bacon costs "
	<< "more money. You didn't put enough bacon in my burger !"
	<< " If you did, I wouldn't be asking for more !" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "3 - I think I deserve to have some extra bacon for free."
	<< " I've been coming for years whereas you started working here "
	<< "since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "4 - This is unacceptable ! I want to speak to the manager now.";
	std::cout<< std::endl;
}

void	Harl::complain(std::string level)
{
	// void		(Harl::*tabFunc[4])(void);
	// tabFunc[0] = &Harl::debug;
	// tabFunc[1] = &Harl::info;
	// tabFunc[2] = &Harl::warning;
	// tabFunc[3] = &Harl::error;

	// std::string	name[4];
	// name[0] = "DEBUG";
	// name[1] = "INFO";
	// name[2] = "WARNING";
	// name[3] = "ERROR";

	void	(Harl::*tabFunc[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string	name[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	for (int i = 0; i < 4; i++)
	{
		if (level.compare(name[i]) == 0)
			(this->*tabFunc[i])();
	}
}
