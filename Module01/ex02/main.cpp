/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:11:24 by marvin            #+#    #+#             */
/*   Updated: 2024/06/22 19:33:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
# define RESET "\033[0m"
# define YELLOW "\x1B[33m"
# define VERT "\033[38;5;29m"

int main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "Address str       : ";
	std::cout << YELLOW << &str << RESET<< std::endl;
	
	std::cout << "Address stringPTR : ";
	std::cout << YELLOW << stringPTR << RESET << std::endl;
	
	std::cout << "Address stringREF : ";
	std::cout << YELLOW << &stringREF << RESET << std::endl;

	std::cout << std::endl;

	std::cout << "Value str         : ";
	std::cout << VERT << str << RESET << std::endl;

	std::cout << "Value stringPTR   : ";
	std::cout << VERT << *stringPTR << RESET << std::endl;
	
	std::cout << "Value stringREF   : ";
	std::cout << VERT << stringREF << RESET << std::endl;
	

	return 0;
}