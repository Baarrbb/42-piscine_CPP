/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:48:02 by marvin            #+#    #+#             */
/*   Updated: 2024/09/14 14:00:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <cctype>

PhoneBook::PhoneBook(void)
{
	std::cout << VERT "PhoneBook default constructor called" RESET << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << ROUGE "Destructor PhoneBook called" RESET << std::endl;
}

bool	is_printable(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if ((int)str[i] < 32 || (int)str[i] > 126)
			return 0;
	}
	return 1;
}

static std::string	get_info(std::string q, int type)
{
	std::string choice;

	while (choice.empty())
	{
		std::cout << "What is your " << q << " ?" << std::endl;
		std::cout << ">> ";
		std::getline(std::cin, choice);
		if (std::cin.eof())
			return "";
		if (!is_printable(choice))
		{
			std::cout << ROUGE "Caractere interdit" RESET << std::endl;
			choice = "";
			continue ;
		}
		if (type)
		{
			for (int i = 0; choice[i]; i++)
			{
				if (!std::isdigit(choice[i]))
				{
					std::cout << ROUGE "Phone number takes only digit" RESET << std::endl << std::endl;
					choice.clear();
					break ;
				}
			}
		}
	}
	return choice;
}

int	PhoneBook::add_contact(int id)
{
	Contact tmp;
	std::string info;

	tmp.set_id((id % 8) + 1);

	info = get_info("first name", 0);
	if (info.empty())
		return 1;
	tmp.set_firstname(info);

	info = get_info("last name", 0);
	if (info.empty())
		return 1;
	tmp.set_lastname(info);

	info = get_info("nickname", 0);
	if (info.empty())
		return 1;
	tmp.set_nickname(info);

	info = get_info("phone number", 1);
	if (info.empty())
		return 1;
	tmp.set_number(info);

	info = get_info("darkest secret", 0);
	if (info.empty())
		return 1;
	tmp.set_secret(info);

	this->_contact[id % 8] = tmp;
	return 0;
}

void	PhoneBook::ask_index(int id)
{
	std::string choice;

	std::cout << "What index do you want to display ?" << std::endl;
	std::cout << ">> ";
	std::getline(std::cin, choice);
	if (std::cin.eof())
		return ;
	int i = std::atoi(choice.c_str());
	if (i < 1 || i > 8)
		std::cout << std::endl << RED "Wrong index" RESET << std::endl;
	else
	{
		i--;
		std::cout << std::endl;
		if (i > id - 1)
		{
			if (id == 0)
				std::cout << "The PhoneBook is empty..." << std::endl;
			else if (id % 8 != 1)
				std::cout << "There is only " << (id % 8) << " persons in the PhoneBook" << std::endl;
			else
				std::cout << "There is only " << (id % 8) << " person in the PhoneBook" << std::endl;
		}
		else
		{
			id--;
			std::cout << "First name     : " << this->_contact[i].get_firstname() << std::endl;
			std::cout << "Last name      : " << this->_contact[i].get_lastname() << std::endl;
			std::cout << "Nickname       : " << this->_contact[i].get_nickname() << std::endl;
			std::cout << "Phone number   : " << this->_contact[i].get_number() << std::endl;
			std::cout << "Darkest secret : " << this->_contact[i].get_secret() << std::endl;
		}
	}
}

void	PhoneBook::search_contact(int id)
{
	if (!this->_contact[0].get_id())
	{
		std::cout << std::endl << "The PhoneBook is empty..." << std::endl;
		return ;
	}
	else
	{
		std::cout << std::endl << std::setw(10) << "INDEX" << "|";
		std::cout << std::setw(10) << "FIRSTNAME" << "|";
		std::cout << std::setw(10) << "LASTNAME" << "|";
		std::cout << std::setw(10) << "NICKNAME" << "|" << std::endl;
		std::cout << "--------------------------------------------" << std::endl;
		for (int i = 0; i < 8 && this->_contact[i].get_id(); i++)
		{
			std::cout << std::setw(10) << _contact[i].get_id() << "|";
			if (this->_contact[i].get_firstname().length() <= 10)
				std::cout << std::setw(10) << this->_contact[i].get_firstname() << "|";
			else
				std::cout << this->_contact[i].get_firstname().substr(0, 9) << ".|";
			if (this->_contact[i].get_lastname().length() <= 10)
				std::cout << std::setw(10) << this->_contact[i].get_lastname() << "|";
			else
				std::cout << this->_contact[i].get_lastname().substr(0, 9) << ".|";
			if (this->_contact[i].get_nickname().length() <= 10)
				std::cout << std::setw(10) << this->_contact[i].get_nickname()  << "|" << std::endl;
			else
				std::cout << this->_contact[i].get_nickname().substr(0, 9) << ".|" << std::endl;
		}
		std::cout << std::endl;
		this->ask_index(id);
	}
}
