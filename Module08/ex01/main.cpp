/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:01:41 by marvin            #+#    #+#             */
/*   Updated: 2025/02/18 17:40:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int main(void)
{
	std::cout << YELLOW "SUBJECT MAIN" << RESET << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << BLUE "shortest" RESET << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << BLUE "longest" RESET << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << YELLOW "TESTS" RESET << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.printElt();
		std::cout << std::endl << "test cpy" << std::endl;
		Span sp1(sp);
		sp1.printElt();
		sp.addNumber(6);
		sp.addNumber(3);
		sp1.addNumber(42);
		sp1.addNumber(42);
		std::cout << "print sp" << std::endl;
		sp.printElt();
		std::cout << "sp1" << std::endl;
		sp1.printElt();
		Span sp2 = Span(2);
		sp2.addNumber(99);
		sp2.addNumber(99);
		std::cout << "print sp2" << std::endl;
		sp2.printElt();
		std::cout << "sp2 apres affectation" << std::endl;
		sp2 = sp1;
		sp2.printElt();
		std::cout << "addNumber" << std::endl;
		sp2.addNumber(99);
		std::cout << "addNumber" << std::endl;
		sp2.addNumber(99);
		std::cout << "print sp2" << std::endl;
		sp2.printElt();
		try
		{
			std::cout << std::endl << BLUE "shortest" RESET << std::endl;
			std::cout << sp2.shortestSpan() << std::endl;
			std::cout << BLUE "longest" RESET << std::endl;
			std::cout << sp2.longestSpan() << std::endl;
		}
		catch(std::runtime_error& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << YELLOW "TEST PB SHORTEST && LONGEST" RESET << std::endl;
	{
		try
		{
			Span sp1 = Span(2);
			sp1.addNumber(0);
			std::cout << "print sp1" << std::endl;
			sp1.printElt();
			std::cout << std::endl << BLUE "shortest" RESET << std::endl;
			std::cout << sp1.shortestSpan() << std::endl;
		}
		catch (std::runtime_error& e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			Span sp3 = Span(2);
			sp3.addNumber(10);
			std::cout << "print sp3" << std::endl;
			sp3.printElt();
			std::cout << BLUE "longest" RESET << std::endl;
			std::cout << sp3.longestSpan() << std::endl;
		}
		catch (std::runtime_error& e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			Span sp2 = Span(5);
			sp2.addNumber(100);
			sp2.addNumber(14);
			sp2.addNumber(1);
			sp2.addNumber(43);
			sp2.addNumber(-20);
			sp2.printElt();
			std::cout << std::endl << BLUE "shortest" RESET << std::endl;
			std::cout << sp2.shortestSpan() << std::endl;
			std::cout << BLUE "longest" RESET << std::endl;
			std::cout << sp2.longestSpan() << std::endl;
		}
		catch (std::runtime_error& e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << YELLOW "TEST addRandom" RESET << std::endl;
	{
		std::cout << YELLOW "TEST addRandom 1" RESET << std::endl;
		{
			try
			{
				Span sp(20);
				sp.addRandomNumber(20);
				sp.printElt();
				std::cout << std::endl << BLUE "shortest" RESET << std::endl;
				std::cout << sp.shortestSpan() << std::endl;
				std::cout << BLUE "longest" RESET << std::endl;
				std::cout << sp.longestSpan() << std::endl;
			}
			catch(std::runtime_error& e)
			{
				std::cerr << e.what() << '\n';
			}
		}

		// create a vector of 10 elements initialize to 42
		std::vector<int> tab(10, 42);

		std::cout << YELLOW "TEST addRandom with a vector in an empty span" RESET << std::endl;
		{
			try
			{
				Span sp(10);
				sp.printElt();

				// add vector to our Span sp
				sp.addRandomNumber(tab.begin(), tab.end());
				sp.printElt();

				std::cout << std::endl << BLUE "shortest" RESET << std::endl;
				std::cout << sp.shortestSpan() << std::endl;
				std::cout << BLUE "longest" RESET << std::endl;
				std::cout << sp.longestSpan() << std::endl;
			}
			catch(std::runtime_error& e)
			{
				std::cerr << e.what() << '\n';
			}
		}

		std::cout << YELLOW "TEST addRandom with vector in a Span already fill with some values" RESET << std::endl;
		{
			try
			{
				Span sp(10);
				sp.addNumber(64);
				sp.addNumber(64);
				sp.printElt();

				// add 5 values
				sp.addRandomNumber(tab.begin() + 5, tab.end());
				sp.printElt();

				std::cout << std::endl << BLUE "shortest" RESET << std::endl;
				std::cout << sp.shortestSpan() << std::endl;
				std::cout << BLUE "longest" RESET << std::endl;
				std::cout << sp.longestSpan() << std::endl;
			}
			catch(std::runtime_error& e)
			{
				std::cerr << e.what() << '\n';
			}
		}

		std::cout << YELLOW "TEST addRandom with vector and too many values" RESET << std::endl;
		{
			try
			{
				Span sp(10);
				sp.addNumber(64);
				sp.addNumber(64);
				sp.printElt();

				// trying to add 10 val
				sp.addRandomNumber(tab.begin(), tab.end());
				sp.printElt();

				std::cout << std::endl << BLUE "shortest" RESET << std::endl;
				std::cout << sp.shortestSpan() << std::endl;
				std::cout << BLUE "longest" RESET << std::endl;
				std::cout << sp.longestSpan() << std::endl;
			}
			catch(std::runtime_error& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
	}

	std::cout << YELLOW "TEST LIMITS" RESET << std::endl;
	{
		Span sp(3);
		sp.addNumber(0);
		sp.addNumber(-2147483648);
		sp.addNumber(2147483647);
		sp.printElt();
		std::cout << std::endl << BLUE "shortest" RESET << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << BLUE "longest" RESET << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	return 0;
}