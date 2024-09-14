/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:17:13 by marvin            #+#    #+#             */
/*   Updated: 2024/09/14 14:09:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	// std::cout << YELLOW "CLAPTRAP TEST DEFAULT CONSTRUCTOR" RESET << std::endl;
	// {
	// 	ClapTrap test1;
	// 	test1.attack("a1");
	// }
	// std::cout << YELLOW "CLAPTRAP TEST ATTACK ET DIFFERENT CONSTRUCTOR" RESET << std::endl;
	// {
	// 	ClapTrap test2("TEST2");
	// 	for (int i = 0 ; i < 10; i++)
	// 	{
	// 		std::cout << i + 1 << " ";
	// 		test2.attack("a2");
	// 	}
	// 	test2.attack("a2");
	// 	// test constructeur copy
	// 	ClapTrap test3(test2);
	// 	test3.beRepaired(2);
	// 	// test constructeur copy assignment
	// 	ClapTrap test4;
	// 	test4 = test3;
	// 	test4.beRepaired(2);
	// }
	// std::cout << YELLOW "CLAPTRAP COMPLEMENTARY TESTS" RESET << std::endl;
	// {
	// 	ClapTrap test5("TEST5");
	// 	test5.beRepaired(2);
	// 	ClapTrap test6;
	// 	test6 = test5;
	// 	test6.attack("a3");
	// 	test6.takeDamage(10);
	// 	test6.attack("a4");
	// 	test6.takeDamage(3);
	// 	test6.attack("a4");
	// }
	// std::cout << std::endl;
	// std::cout << std::endl;
	// std::cout << YELLOW "SCAVTRAP TEST DEFAULT CONSTRUCTOR" RESET << std::endl;
	// {
	// 	ScavTrap t1;
	// 	t1.attack("a1");
	// }
	// std::cout << YELLOW "SCAVTRAP TEST ATTACK & CONSTRUCTOR" RESET << std::endl;
	// {
	// 	ScavTrap t2("t2");
	// 	for (int i = 0 ; i < 50; i++)
	// 	{
	// 		std::cout << i + 1 << " ";
	// 		t2.attack("a2");
	// 	}
	// 	t2.attack("a2");
	// 	ScavTrap t3(t2);
	// 	t3.beRepaired(2);
	// }
	// std::cout << YELLOW "SCAVTRAP COMPLEMENTARY TESTS" RESET << std::endl;
	// {
	// 	ScavTrap t4("t4");
	// 	t4.beRepaired(2);
	// 	ScavTrap t5;
	// 	t5 = t4;
	// 	t5.takeDamage(100);
	// 	t5.attack("a3");
	// 	t5.takeDamage(2);
	// 	t5.attack("a3");
	// 	t5.guardGate();
	// }

	// std::cout << YELLOW "FragTrap TEST DEFAULT CONSTRUCTOR" RESET << std::endl;
	// {
	// 	FragTrap t1;
	// 	t1.attack("a1");
	// }
	// std::cout << YELLOW "FragTrap TEST ATTACK & CONSTRUCTOR" RESET << std::endl;
	// {
	// 	FragTrap t2("t2");
	// 	for (int i = 0 ; i < 100; i++)
	// 	{
	// 		std::cout << i + 1 << " ";
	// 		t2.attack("a2");
	// 	}
	// 	t2.attack("a2");
	// 	FragTrap t3(t2);
	// 	t3.beRepaired(2);
	// }

	std::cout << YELLOW "FragTrap COMPLEMENTARY TESTS" RESET << std::endl;
	{
		FragTrap t4("t4");
		t4.beRepaired(2);

		FragTrap t5;
		t5 = t4;
		t5.takeDamage(100);
		t5.attack("a3");
		t5.takeDamage(2);
		t5.attack("a3");
		t5.highFivesGuys();

		FragTrap t6("t6");
		t6.highFivesGuys();
	}

	return 0;
}
