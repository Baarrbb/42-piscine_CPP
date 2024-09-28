/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:34:03 by marvin            #+#    #+#             */
/*   Updated: 2024/09/28 15:20:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main(void)
{
	std::cout << YELLOW "TESTS AMATERIA ICE AND CURE" RESET << std::endl;
	{
		const AMateria* test = new Ice();
		const AMateria* test1 = new Cure();
		std::cout << "Ice type : " << test->getType() << std::endl;
		std::cout << "Cure type : " << test1->getType() << std::endl;
		delete test1;
		delete test;
	}
	
	std::cout << YELLOW "TEST MAIN EXO" RESET << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	std::cout << YELLOW "COMPLEMENTARY TESTS" RESET << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		ICharacter* bob = new Character("bob");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);

		tmp = src->createMateria("cure");
		me->equip(tmp);

		tmp = src->createMateria("pppp");
		me->equip(tmp);

		std::cout << CYAN "attack1" RESET << std::endl;
		me->use(0, *bob);

		std::cout << CYAN "attack2" RESET << std::endl;
		me->use(1, *bob);
		
		std::cout << CYAN "attack3 nothing" RESET  << std::endl;
		me->use(2, *bob);

		std::cout << CYAN "attack4 nothing" RESET << std::endl;
		me->use(3, *bob);

		std::cout << CYAN "attack5 wrong index" RESET << std::endl;
		me->use(4, *bob);

		delete bob;
		delete me;
		delete src;
	}

	std::cout << YELLOW "COMPLEMENTARY TESTS" RESET << std::endl;
	{
		AMateria *tmp = new Cure();
		ICharacter* me = new Character("me");
		ICharacter* bob = new Character("bob");

		me->equip(tmp);
		me->use(0, *bob);
		me->unequip(0);
		me->use(0, *bob);

		delete bob;
		delete me;
		delete tmp;
	}

	return 0;
}