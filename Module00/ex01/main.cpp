/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:15:45 by marvin            #+#    #+#             */
/*   Updated: 2024/09/14 14:00:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main()
{
	std::string	choice;
	PhoneBook	book;
	int			id;

	id = 0;
	std::cout << std::endl;
	std::cout << GREEN "Welcome in the OLD PHONEBOOK" RESET << std::endl;
	while (1)
	{
		std::cout << std::endl << "Waiting for an instruction :" << std::endl;
		std::cout << YELLOW "1- ADD" RESET << " (save a new contact)" << std::endl;
		std::cout << YELLOW "2- SEARCH" RESET << " (display a specific contact)" << std::endl;
		std::cout << YELLOW "3- EXIT" RESET << std::endl;
		std::cout << "Your choice : ";
		std::getline(std::cin, choice);
		if (choice == "exit" || choice == "EXIT" || choice == "3" || std::cin.eof())
			break;
		else if (choice == "add" || choice == "ADD" || choice == "1")
		{
			if (book.add_contact(id))
				return 0;
			id++;
		}
		else if (choice == "search" || choice == "SEARCH" || choice == "2")
			book.search_contact(id);
	}
	std::cout << std::endl;
	return 0;
}
