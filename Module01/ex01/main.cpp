/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:01:30 by marvin            #+#    #+#             */
/*   Updated: 2024/06/11 14:10:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *zomb = zombieHorde(2, "KK");
	std::cout << std::endl;

	Zombie *zombis = zombieHorde(5, "Lala");
	std::cout << std::endl;

	for (int i = 0; i < 2; i++)
	{
		std::cout << "Zombie " << i << std::endl;
		zomb[i].announce();
	}
	
	std::cout << std::endl;
	delete [] zomb;
	std::cout << std::endl;

	for (int i = 0; i < 5; i++)
	{
		std::cout << "Zombie " << i << std::endl;
		zombis[i].announce();
	}

	std::cout << std::endl;
	delete [] zombis;

	return 0;
}
