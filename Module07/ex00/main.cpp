/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:06:03 by marvin            #+#    #+#             */
/*   Updated: 2025/02/16 19:42:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# define RESET "\033[0m"
# define YELLOW "\x1B[33m"

#include <iostream>
#include "whatever.hpp"

int main(void)
{
	std::cout << YELLOW "TEST INT" RESET << std::endl;
	{
		int x = 42;
		int y = 0;

		std::cout << "x : " << x << " y : " << y << std::endl;
		swap(x, y);
		std::cout << "x : " << x << " y : " << y << std::endl;

		int mn = min(x, y);
		std::cout << "min : " << mn << std::endl;

		int mx = max(x, y);
		std::cout << "max : " << mx << std::endl;
	}

	std::cout << YELLOW "TEST FLOAT" RESET << std::endl;
	{
		float x = 42.042f;
		float y = -33.33f;

		std::cout << "x : " << x << " y : " << y << std::endl;
		swap(x, y);
		std::cout << "x : " << x << " y : " << y << std::endl;

		float mn = min(x, y);
		std::cout << "min : " << mn << std::endl;

		float mx = max(x, y);
		std::cout << "max : " << mx << std::endl;
	}

	std::cout << YELLOW "SUBJECT MAIN()" RESET << std::endl;
	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}

	return 0;
}