/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:08:48 by marvin            #+#    #+#             */
/*   Updated: 2024/09/14 13:59:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

std::string	to_upcase(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (std::islower(str[i]))
			str[i] = std::toupper(str[i]);
	}
	return str;
}

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	std::string	str;
	for (int i = 1 ; i < ac; i++)
	{
		str = to_upcase(av[i]);
		std::cout << str;
	}
	std::cout << std::endl;
	return 0;
}
