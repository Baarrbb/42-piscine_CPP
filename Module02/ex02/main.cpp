/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:54:54 by marvin            #+#    #+#             */
/*   Updated: 2024/09/14 14:06:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	std::cout << YELLOW "MAIN EXO" RESET << std::endl;
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;

		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	std::cout << YELLOW "FIN MAIN EXO" RESET << std::endl;

	std::cout << YELLOW "TEST COMPARISON OPERATORS" RESET << std::endl;
	{
		Fixed a(5);
		Fixed b(3);
		Fixed c(5);

		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "c = " << c << std::endl << std::endl;
		std::cout << "a > b: " << (a > b ? "true" : "false") << std::endl;
		std::cout << "a < b: " << (a < b ? "true" : "false") << std::endl;
		std::cout << "a >= b: " << (a >= b ? "true" : "false") << std::endl;
		std::cout << "a <= b: " << (a <= b ? "true" : "false") << std::endl;
		std::cout << "a <= c: " << (a <= c ? "true" : "false") << std::endl;
		std::cout << "a >= c: " << (a >= c ? "true" : "false") << std::endl;
		std::cout << "a == c: " << (a == c ? "true" : "false") << std::endl;
		std::cout << "a != b: " << (a != b ? "true" : "false") << std::endl;
		std::cout << "a != c: " << (a != c ? "true" : "false") << std::endl;
	}
	std::cout << YELLOW "FIN TEST COMPARISON OPERATORS" RESET << std::endl;

	std::cout << YELLOW "TEST FLOAT COMPARISON OPERATORS" RESET << std::endl;
	{
		Fixed a(5.2f);
		Fixed b(5.1f);
		Fixed c(5.2f);

		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "c = " << c << std::endl << std::endl;
		std::cout << "a > b: " << (a > b ? "true" : "false") << std::endl;
		std::cout << "a < b: " << (a < b ? "true" : "false") << std::endl;
		std::cout << "a >= b: " << (a >= b ? "true" : "false") << std::endl;
		std::cout << "a <= b: " << (a <= b ? "true" : "false") << std::endl;
		std::cout << "a <= c: " << (a <= c ? "true" : "false") << std::endl;
		std::cout << "a >= c: " << (a >= c ? "true" : "false") << std::endl;
		std::cout << "a == c: " << (a == c ? "true" : "false") << std::endl;
		std::cout << "a != b: " << (a != b ? "true" : "false") << std::endl;
		std::cout << "a != c: " << (a != c ? "true" : "false") << std::endl;

		
	}
	std::cout << YELLOW "FIN TEST FLOAT COMPARISON OPERATORS" RESET << std::endl;

	std::cout << YELLOW "TEST INT ARITHMETICS OPERATORS" RESET << std::endl;
	{
		Fixed a(10);
		Fixed b(2);
		
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl << std::endl;
		std::cout << "a + b: " << a + b << std::endl;
		std::cout << "a - b: " << a - b << std::endl;
		std::cout << "a * b: " << a * b << std::endl;
		std::cout << "a / b: " << a / b << std::endl;
	}
	std::cout << YELLOW "FIN TEST INT ARITHMETICS OPERATORS" RESET << std::endl;

	std::cout << YELLOW "TEST FLOAT ARITHMETICS OPERATORS" RESET << std::endl;
	{
		Fixed a(10.5f);
		Fixed b(2.25f);
		
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl << std::endl;
		std::cout << "a + b: " << a + b << std::endl;
		std::cout << "a - b: " << a - b << std::endl;
		std::cout << "a * b: " << a * b << std::endl;
		std::cout << "a / b: " << a / b << std::endl;
	}
	std::cout << YELLOW "FIN TEST FLOAT ARITHMETICS OPERATORS" RESET << std::endl;

	std::cout << YELLOW "TEST INCREMENTATION AND DECREMENTATION" RESET << std::endl;
	{
		Fixed a(5);
		std::cout << "a: " << a << std::endl;

		Fixed postInc = a++; // postinc prend la valeur de a puis a augmente
		std::cout << "Post incrementation : " << a << " : " << postInc << std::endl;

		a = Fixed(5);
		Fixed preInc = ++a; // a augmente puis preinc prend la valeur de a
		std::cout << "Pre incrementation  : " << a << " : " << preInc << std::endl;

		a = Fixed(5);
		Fixed postDec = a--;
		std::cout << "Post decrementation : " << a << " : " << postDec << std::endl;

		a = Fixed(5);
		Fixed preDec = --a;
		std::cout << "Pre decrementation  : " << a << " : " << preDec << std::endl;

	}
	std::cout << YELLOW "FIN TEST INCREMENTATION AND DECREMENTATION" RESET << std::endl;

	std::cout << YELLOW "TEST MIN AND MAX" RESET << std::endl;
	{
		Fixed a(5);
		Fixed b(10);

		std::cout << "Min of " << a << " and " << b << " is " << Fixed::min(a, b) << std::endl;
		std::cout << "Max of " << a << " and " << b << " is " << Fixed::max(a, b) << std::endl;
		Fixed c(10);
		std::cout << "Min of " << b << " and " << c << " (equal values) is " << Fixed::min(b, c) << std::endl;
		std::cout << "Max of " << b << " and " << c << " (equal values) is " << Fixed::max(b, c) << std::endl;
	}
	std::cout << YELLOW "FIN TEST MIN AND MAX" RESET << std::endl;

	std::cout << YELLOW "COMPLEMENTARY TEST" RESET << std::endl;
	{
		Fixed a(10);
		Fixed b(-2);
		
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl << std::endl;
		std::cout << "a + b: " << a + b << std::endl;
		std::cout << "a - b: " << a - b << std::endl;
		std::cout << "a * b: " << a * b << std::endl;
		std::cout << "a / b: " << a / b << std::endl;
	}
	std::cout << YELLOW "FIN COMPLEMENTARY TEST" RESET << std::endl;
	
	return 0;
}