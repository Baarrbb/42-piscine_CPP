/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:01:30 by marvin            #+#    #+#             */
/*   Updated: 2024/09/14 14:02:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::cout << YELLOW "TEST PREMIERE PARTIE" RESET << std::endl;
	{
		Zombie z1("Zombie1");
		z1.announce();
		std::cout << std::endl;

		Zombie z2("Zombie2");
		z2.announce();
		std::cout << std::endl;
	}
	std::cout << YELLOW "FIN PREMIERE PARTIE" RESET << std::endl << std::endl;

	std::cout << YELLOW "TEST DEUXIEME PARTIE" RESET << std::endl;
	{
		Zombie *zomb = newZombie("test");
		zomb->announce();
		delete zomb;
		std::cout << std::endl;
		
		randomChump("foo");
		std::cout << std::endl;
		randomChump("bar");
		std::cout << std::endl;
	}
	std::cout << YELLOW "FIN DEUXIEME PARTIE" RESET << std::endl << std::endl;

	return 0;
}
