/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:20:53 by marvin            #+#    #+#             */
/*   Updated: 2025/02/18 16:24:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define RESET "\033[0m"
# define YELLOW "\x1B[33m"

#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

int main(void)
{
	std::cout << YELLOW "TEST AVEC LIST" RESET << std::endl;
	{
		std::list<int> lst;
		lst.push_back(1);
		lst.push_back(2);
		lst.push_back(3);
		lst.push_back(42);

		try
		{
			easyfind(lst, 2);
			easyfind(lst, 3);
			easyfind(lst, 42);
			easyfind(lst, 12);
		}
		catch (const std::runtime_error& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << YELLOW "TEST AVEC VECTOR" RESET << std::endl;
	{
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(42);
	
		try
		{
			easyfind(vec, 2);
			easyfind(vec, 3);
			easyfind(vec, 42);
			easyfind(vec, 12);
		}
		catch (const std::runtime_error& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	return 0;
}