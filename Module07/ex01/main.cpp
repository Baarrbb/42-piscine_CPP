/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:39:38 by marvin            #+#    #+#             */
/*   Updated: 2025/02/18 15:47:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define RESET "\033[0m"
# define YELLOW "\x1B[33m"

#include <iostream>
#include "iter.hpp"

template< typename T >
void printVal(T &x)
{
	std::cout << x << std::endl;
}

template< typename T >
void doubleVal(T& value)
{
	value *= 2;
}

void dupl(std::string &s)
{
	s = s.append(s);
}

int main(void)
{
	std::cout << YELLOW "TEST AVEC TAB INT" RESET << std::endl;
	{
		int tab[] = {1, 2, 3, 4};
		int s = 4;

		// Quand passe fct template en ptr fct compil peut pas deduire type
		// donc on doit preciser
		iter(tab, s, printVal<int>);
		std::cout << "Double values" << std::endl;
		iter(tab, s, doubleVal<int>);
		iter(tab, s, printVal<int>);
	}

	std::cout << YELLOW "TEST AVEC TAB FLOAT" RESET << std::endl;
	{
		float tab[] = {1.5f, 2.2f, 3.3f, 4.6f};
		size_t s = 4;

		iter(tab, s, printVal<float>);
		std::cout << "Double values" << std::endl;
		iter(tab, s, doubleVal<float>);
		iter(tab, s, printVal<float>);
	}

	std::cout << YELLOW "TEST TAB STRING" RESET << std::endl;
	{
		size_t s = 3;
		std::string tab[3] = {"a", "b", "c"};
		iter(tab, s, printVal<std::string>);
		std::cout << std::endl;
		iter(tab, s, dupl);
		iter(tab, s, printVal<std::string>);

		std::cout << std::endl << "OTHER TEST" << std::endl << std::endl;
		std::string tab1[3] = {"bonjour", "fgfg", "4242"};
		iter(tab1, s, printVal<std::string>);
		std::cout << std::endl;
		iter(tab1, s, dupl);
		iter(tab1, s, printVal<std::string>);
	}

	return 0;
}