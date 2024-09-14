/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:17:13 by marvin            #+#    #+#             */
/*   Updated: 2024/09/14 14:10:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

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
	// 	t5.guardGate(); // mettre condition si mort ???
	// }
	// std::cout << YELLOW "FRAGTRAP TESTS" RESET << std::endl;
	// {
	// 	ScavTrap s1("Lala");
	// 	s1.attack("qqn");
	// 	s1.guardGate();
	// 	FragTrap f("frag");
	// 	f.attack("jsp");
	// 	f.highFivesGuys();
	// 	ClapTrap c("clap");
	// 	c.attack("frag");
	// }

	std::cout << YELLOW "FIRST TEST" RESET << std::endl;
	{
		DiamondTrap t("ShineBrightLikeADiamond");
		t.whoAmI();
	}
	
	std::cout << YELLOW "TESTS VALUES" RESET << std::endl;
	{
		DiamondTrap d;
		ScavTrap s;
		FragTrap f;
	
		d.whoAmI();
		std::cout << std::endl;
		std::cout << "DiamondTrap hit points " << d.getHitPoint() << std::endl;
		std::cout << "ScavTrap hit points " << f.getHitPoint() << std::endl;
	
		std::cout << "DiamondTrap energy points " << d.getEnergyPoint() << std::endl;
		std::cout << "FragTrap energy points " << s.getEnergyPoint() << std::endl;
	
		std::cout << "DiamondTrap attack points " << d.getAttackPoint() << std::endl;
		std::cout << "FragTrap attack points " << f.getAttackPoint() << std::endl;
	}

	std::cout << YELLOW "DIAMONDTRAP TEST ATTACK & CONSTRUCTOR" RESET << std::endl;
	{
		DiamondTrap t2("t2");
		for (int i = 0 ; i < 50; i++)
		{
			std::cout << i + 1 << " ";
			t2.attack("a2");
		}
		t2.attack("a2");

		DiamondTrap t3(t2);
		t3.beRepaired(2);
	}

	std::cout << YELLOW "DIAMONDTRAP COMPLEMENTARY TESTS" RESET << std::endl;
	{
		DiamondTrap t4("t4");
		t4.beRepaired(2);

		DiamondTrap t5;
		t5 = t4;
		t5.takeDamage(100);
		t5.attack("a3");
		t5.takeDamage(2);
		t5.attack("a3");
		t5.guardGate();
	}
	
	std::cout << YELLOW "DIAMONDTRAP TESTS" RESET << std::endl;
	{
		DiamondTrap s1("Lala");

		s1.attack("qqn");
		s1.guardGate();

		DiamondTrap f("frag");
		f.attack("jsp");
		f.highFivesGuys();

		DiamondTrap c("clap");
		c.attack("frag");
	}

	std::cout << YELLOW "DIAMONDTRAP TESTS" RESET << std::endl;
	{
		DiamondTrap	d("PPPP");
		d.attack("kkk");
		d.whoAmI();
	}

	return 0;
}
