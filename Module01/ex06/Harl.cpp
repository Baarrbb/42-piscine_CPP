/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:40:23 by marvin            #+#    #+#             */
/*   Updated: 2024/09/14 14:03:57 by marvin           ###   ########.fr       */
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
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "1 - I love having extra bacon for my "
	<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "
	<< "I really do !" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "2 - I cannot believe adding extra bacon costs "
	<< "more money. You didn’t put enough bacon in my burger !"
	<< " If you did, I wouldn’t be asking for more !" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "3 - I think I deserve to have some extra bacon for free."
	<< " I’ve been coming for years whereas you started working here "
	<< "since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "4 - This is unacceptable ! I want to speak to the manager now.";
	std::cout<< std::endl;
}

void	Harl::complain(std::string level)
{
	void		(Harl::*tabFunc[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
	std::string	name[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	int	i = 0;
	for (; i < 4; i++)
	{
		if (level.compare(name[i]) == 0)
			break;
	}
	for (; i < 4; i++)
	{
		switch (i)
		{
			case 0:
				(this->*tabFunc[0])();
				break;
			case 1:
				(this->*tabFunc[1])();
				break;
			case 2:
				(this->*tabFunc[2])();
				break;
			default:
				(this->*tabFunc[3])();
		}
		std::cout << std::endl;
	}
}
