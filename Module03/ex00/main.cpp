/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:17:13 by marvin            #+#    #+#             */
/*   Updated: 2024/09/14 14:09:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	std::cout << YELLOW "TEST DEFAULT CONSTRUCTOR" RESET << std::endl;
	{
		ClapTrap test1;
		test1.attack("a1");
	}

	std::cout << YELLOW "TEST ATTACK ET DIFFERENT CONSTRUCTOR" RESET << std::endl;
	{
		ClapTrap test2("TEST2");
		for (int i = 0 ; i < 10; i++)
		{
			std::cout << i + 1 << " ";
			test2.attack("a2");
		}
		test2.attack("a2");

		// test constructeur copy
		ClapTrap test3(test2);
		test3.beRepaired(2);

		// test constructeur copy assignment
		ClapTrap test4;
		test4 = test3;
		test4.beRepaired(2);
	}

	std::cout << YELLOW "COMPLEMENTARY TESTS" RESET << std::endl;
	{
		ClapTrap test5("TEST5");
		test5.beRepaired(2);

		ClapTrap test6;
		test6 = test5;
		test6.attack("a3");
		test6.takeDamage(10);
		test6.attack("a4");
		test6.takeDamage(3);
		test6.attack("a4");
	}

	return 0;
}