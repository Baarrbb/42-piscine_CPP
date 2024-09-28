/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:52:28 by marvin            #+#    #+#             */
/*   Updated: 2024/09/28 15:20:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include "Animal.hpp"

int main()
{
	std::cout << YELLOW "ASK IN EXERCICE" RESET << std::endl;
	{
		Animal *a[100];
		for (int i = 0; i < 50; i++)
			a[i] = new Cat();
		for (int i = 50; i < 100; i++)
			a[i] = new Dog();
		for (int i = 0; i < 100; i++)
			std::cout << i << " : " << a[i]->getType() << std::endl;
		for (int i = 0; i < 100; i++)
			delete a[i];
	}

	std::cout << YELLOW "MAIN IN EXO" RESET << std::endl;
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j; //should not create a leak
		delete i;
	}

	// std::cout << YELLOW "COMPLEMENTARY TESTS" RESET << std::endl;
	// {
	// 	Cat a1;
	// 	Dog a2;
	// 	// a1.setId(0, "Bonjour");
	// 	std::cout << YELLOW "Tests copy constructor" RESET << std::endl;
	// 	{
	// 		Cat a3(a1);
	// 		Dog a4(a2);
	// 		// std::cout << "a1 : " << a1.getId(0) << std::endl;
	// 		// std::cout << "a3 : " << a3.getId(0) << std::endl;
	// 		// std::cout << "set diff sur a3" << std::endl;
	// 		// a3.setId(0, "Hello");
	// 		// std::cout << "a1 : " << a1.getId(0) << std::endl;
	// 		// std::cout << "a3 : " << a3.getId(0) << std::endl;
	// 		std::cout << "avant destructeur" << std::endl;
	// 	}
	// 	std::cout << "apres destructeur" << std::endl;
	// 	std::cout << YELLOW "Tests assignment constructor" RESET << std::endl;
	// 	{
	// 		Cat a3;
	// 		a3 = a1;
	// 		Dog a4;
	// 		a4 = a2;
	// 		// std::cout << "a1 : " << a1.getId(0) << std::endl;
	// 		// std::cout << "a3 : " << a3.getId(0) << std::endl;
	// 		// std::cout << "set diff sur a3" << std::endl;
	// 		// a3.setId(0, "Hello");
	// 		// std::cout << "a1 : " << a1.getId(0) << std::endl;
	// 		// std::cout << "a3 : " << a3.getId(0) << std::endl;
	// 		std::cout << "avant destructeur" << std::endl;
	// 	}
	// 	std::cout << "apres destructeur" << std::endl;
	// }

	// std::cout << YELLOW "COMPLEMENTARY TESTS" RESET << std::endl;
	// {
	// 	Cat *a1 = new Cat();
	// 	Dog *a2 = new Dog();
	// 	// a1->setId(0, "Bonjour");
	// 	std::cout << YELLOW "Tests copy constructor" RESET << std::endl;
	// 	{
	// 		Cat a3(*a1);
	// 		Dog a4(*a2);
	// 		// std::cout << "a1 : " << a1->getId(0) << std::endl;
	// 		// std::cout << "a3 : " << a3.getId(0) << std::endl;
	// 		// std::cout << "set diff sur a3" << std::endl;
	// 		// a3.setId(0, "Hello");
	// 		// std::cout << "a1 : " << a1->getId(0) << std::endl;
	// 		// std::cout << "a3 : " << a3.getId(0) << std::endl;
	// 		std::cout << "avant destructeur" << std::endl;
	// 	}
	// 	std::cout << "apres destructeur" << std::endl;
	// 	std::cout << YELLOW "Tests assignment constructor" RESET << std::endl;
	// 	{
	// 		Cat *a3 = new Cat();
	// 		*a3 = *a1;
	// 		Dog *a4 = new Dog();
	// 		*a4 = *a2;
	// 		// std::cout << "a1 : " << a1->getId(0) << std::endl;
	// 		// std::cout << "a3 : " << a3->getId(0) << std::endl;
	// 		// std::cout << "set diff sur a3" << std::endl;
	// 		// a3->setId(0, "Hello");
	// 		// std::cout << "a1 : " << a1->getId(0) << std::endl;
	// 		// std::cout << "a3 : " << a3->getId(0) << std::endl;
	// 		std::cout << "avant destructeur" << std::endl;
	// 		delete a3;
	// 		delete a4;
	// 	}
	// 	std::cout << "apres destructeur" << std::endl;
	// 	delete a1;
	// 	delete a2;
	// }

	return 0;
}