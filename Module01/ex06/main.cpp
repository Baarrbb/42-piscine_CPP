/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:17:05 by marvin            #+#    #+#             */
/*   Updated: 2024/06/22 20:43:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "[ Nothing to complain about ]" << std::endl;
		return 0;
	}
	if (ac > 2)
	{
		std::cout << RED "[Error]" RESET << std::endl;
		std::cout << "./harlFilter takes only one parameter" << std::endl;
		return 0;
	}

	std::string param[4];
	param[0] = "DEBUG";
	param[1] = "INFO";
	param[2] = "WARNING";
	param[3] = "ERROR";

	int i = 0;
	for (; i < 4; i++)
	{
		if (std::string(av[1]).compare(param[i]) == 0)
			break ;
	}
	if (i == 4)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return 0;
	}

	Harl h;
	h.complain(av[1]);
	
	return 0;
}