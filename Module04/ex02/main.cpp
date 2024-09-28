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
#include "AAnimal.hpp"

int main()
{
	{
		// preuve non instanciable pcq abstrait
		// const AAnimal* test = new AAnimal();
		// AAnimal test;
	}

	{
		const AAnimal* i = new Cat();
		const AAnimal* j = new Dog();
		std::cout << "Cat type : " << i->getType() << std::endl;
		std::cout << "Dog type : " << j->getType() << std::endl;
		i->makeSound();
		j->makeSound();

		delete j;
		delete i;
	}

	std::cout << std::endl;
	{
		const Dog* test = new Dog();
		const Dog* test1(test);
		std::cout << "Dog type : " << test->getType() << std::endl;
		std::cout << "Dog type : " << test1->getType() << std::endl;
		test->makeSound();
		test1->makeSound();
		delete test;
	}

	std::cout << std::endl;
	{
		const Cat* test = new Cat();
		const Cat* test1;
		test1 = test;
		std::cout << "Cat type : " << test->getType() << std::endl;
		std::cout << "Cat type : " << test1->getType() << std::endl;
		test->makeSound();
		test1->makeSound();
		delete test;
	}

	return 0;
}