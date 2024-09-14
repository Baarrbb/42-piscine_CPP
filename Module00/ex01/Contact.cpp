/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 20:52:27 by marvin            #+#    #+#             */
/*   Updated: 2024/09/14 14:00:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact(void)
{
	this->set_id(0);
	std::cout << VERT "Contact default constructor called" RESET << std::endl;
}

Contact::~Contact(void)
{
	std::cout << ROUGE "Contact destructor called" RESET << std::endl;
}


// Getter

int	Contact::get_id(void) const
{
	return this->_id;
}

std::string	Contact::get_firstname(void) const
{
	return this->_first_name;
}

std::string	Contact::get_lastname(void) const
{
	return this->_last_name;
}

std::string	Contact::get_nickname(void) const
{
	return this->_nickname;
}

std::string	Contact::get_number(void) const
{
	return this->_number;
}

std::string	Contact::get_secret(void) const
{
	return this->_secret;
}

// Setter

void	Contact::set_id(int id)
{
	this->_id = id;
}

void	Contact::set_firstname(std::string name)
{
	this->_first_name = name;
}

void	Contact::set_lastname(std::string name)
{
	this->_last_name = name;
}

void	Contact::set_nickname(std::string name)
{
	this->_nickname = name;
}

void	Contact::set_number(std::string name)
{
	this->_number = name;
}

void	Contact::set_secret(std::string name)
{
	this->_secret = name;
}
