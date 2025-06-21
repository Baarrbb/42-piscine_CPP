/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:35:05 by marvin            #+#    #+#             */
/*   Updated: 2025/02/18 18:52:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define RESET "\033[0m"
# define YELLOW "\x1B[33m"

#include <iostream>
#include <algorithm>
#include "Array.hpp"
#define MAX_VAL 750

template < typename T >
void	printTab(Array<T> a, unsigned int size, std::string name)
{
	std::cout << "TAB "<< name << std::endl;
	for (unsigned int i = 0; i < size; i++)
		std::cout << name << "[" << i << "] " << a[i] << std::endl;
}

int main(void)
{
	std::cout << YELLOW "TEST TAB VIDE" RESET << std::endl;
	{
		try
		{
			Array<int> a;
			std::cout << a[0] << std::endl;
		}
		catch (const Array<int>::OutOfBoundsException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << YELLOW "TEST BASIC TAB INT" RESET << std::endl;
	{
		try
		{
			Array<int> a(2);
			
			std::cout << "tab size : " << a.size() << std::endl;
			printTab(a, a.size(), "a");
			std::cout << "a[2] " << a[2] << std::endl;
		}
		catch (const Array<int>::OutOfBoundsException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << YELLOW "TEST CONSTRUCT COPY" RESET << std::endl;
	{
		try
		{
			Array<int> a(2);
			std::cout << "tab size : " << a.size() << std::endl;
			a[0] = 1;
			printTab(a, a.size(), "a");

			Array<int> b(a);
			printTab(b, b.size(), "b");

			std::cout << "MODIF DE B" << std::endl;
			b[0] = 2;
			b[1] = 2;
			printTab(a, a.size(), "a");
			printTab(b, b.size(), "b");
		}
		catch (const Array<int>::OutOfBoundsException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << YELLOW "TEST AFFECT" RESET << std::endl;
	{
		try
		{
			Array<int> a(5);
			Array<int> b(2);

			a[0] = 1;
			b[0] = 2;
			
			printTab(a, a.size(), "a");
			printTab(b, b.size(), "b");

			std::cout << " b = a" << std::endl;
			b = a;
			printTab(a, a.size(), "a");
			printTab(b, b.size(), "b");

			std::cout << "MODIF DE B" << std::endl;
			b[0] = 2;
			b[1] = 2;
			printTab(a, a.size(), "a");
			printTab(b, b.size(), "b");
		}
		catch(const Array<int>::OutOfBoundsException& e)
		{
			std::cerr << e.what() << '\n';
		}
	}


	std::cout << YELLOW << "TEST STRING" RESET << std::endl;
	{
		try
		{
			Array<std::string> a(3);
			printTab(a, a.size(), "a");
			a[0] = "lala";
			a[1] = "42";
			printTab(a, a.size(), "a");
		}
		catch(const Array<std::string>::OutOfBoundsException& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}

	return 0;
}