/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:54:56 by marvin            #+#    #+#             */
/*   Updated: 2024/06/23 18:04:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	std::cout << YELLOW "MAIN EXO" RESET << std::endl;
	{
		Fixed a;
		Fixed b( a );
		Fixed c;
		c = b;
		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
	}

	std::cout << YELLOW "COMPLEMENTARY TESTS" RESET << std::endl;
	{
		Fixed a;
		std::cout << a.getRawBits() << std::endl;
		a.setRawBits(5);
		std::cout << a.getRawBits() << std::endl;

		Fixed b(a);
		std::cout << b.getRawBits() << std::endl;
		b.setRawBits(2);
		std::cout << b.getRawBits() << std::endl;
		std::cout << a.getRawBits() << std::endl;

		Fixed c;
		c.setRawBits(1);
		std::cout << c.getRawBits() << std::endl;
		c = b;
		std::cout << c.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		c.setRawBits(1);
		std::cout << c.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
	}
	
	return 0;
}
