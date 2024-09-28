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
#include "Animal.hpp"

int main()
{
	std::cout << YELLOW "MAIN TESTS SUBJECT" RESET << std::endl;
	{
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << "Type Dog : " << j->getType() << " " << std::endl;
		std::cout << "Type Cat : " << i->getType() << " " << std::endl;
		std::cout << "Type Animal : " << meta->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}

	std::cout << YELLOW "SAME WITH WRONGANIMAL" RESET << std::endl;
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		const WrongCat* wcat = new WrongCat();
		std::cout  << "Type WrongCat : " << i->getType() << " " << std::endl;
		std::cout  << "Type WrongAnimal : " << meta->getType() << " " << std::endl;
		std::cout  << "Type Wrongcat si appele via WrongCat : " << wcat->getType() << " " << std::endl;
		meta->makeSound();
		i->makeSound();
		wcat->makeSound();

		delete meta;
		delete i;
		delete wcat;
	}

	return 0;
}