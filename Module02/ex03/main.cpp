/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:24:19 by marvin            #+#    #+#             */
/*   Updated: 2024/09/14 14:06:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
	Point a(2.0, 1.0);
	Point b(4.0, 9.0);
	Point c(6.0, 1.0);

	std::cout << YELLOW "POINT INSIDE" RESET << std::endl;
	{
		Point point(4.0, 3.0);

		if (bsp(a, b, c, point))
			std::cout << "Inside" << std::endl;
		else
			std::cout << "Outside" << std::endl;
	}
	std::cout << YELLOW "POINT INSIDE" RESET << std::endl;
	{
		Point point(5.0, 4.0);

		if (bsp(a, b, c, point))
			std::cout << "Inside" << std::endl;
		else
			std::cout << "Outside" << std::endl;
	}
	std::cout << YELLOW "POINT INSIDE" RESET << std::endl;
	{
		Point point(2.5, 2.0);

		if (bsp(a, b, c, point))
			std::cout << "Inside" << std::endl;
		else
			std::cout << "Outside" << std::endl;
	}
	
	std::cout << YELLOW "POINT ON EDGE AB" RESET << std::endl;
	{
		Point point(3.0, 5.0);

		if (bsp(a, b, c, point))
			std::cout << "Inside" << std::endl;
		else
			std::cout << "Outside" << std::endl;
	}
	std::cout << YELLOW "POINT ON EDGE AC" RESET << std::endl;
	{
		Point point(4.0, 1.0);

		if (bsp(a, b, c, point))
			std::cout << "Inside" << std::endl;
		else
			std::cout << "Outside" << std::endl;
	}
	std::cout << YELLOW "POINT ON EDGE BC" RESET << std::endl;
	{
		Point point(5.0, 5.0);

		if (bsp(a, b, c, point))
			std::cout << "Inside" << std::endl;
		else
			std::cout << "Outside" << std::endl;
	}

	std::cout << YELLOW "POINT ON VERTEX A" RESET << std::endl;
	{
		Point point(2.0, 1.0);

		if (bsp(a, b, c, point))
			std::cout << "Inside" << std::endl;
		else
			std::cout << "Outside" << std::endl;
	}
	std::cout << YELLOW "POINT ON VERTEX B" RESET << std::endl;
	{
		Point point(4.0, 9.0);

		if (bsp(a, b, c, point))
			std::cout << "Inside" << std::endl;
		else
			std::cout << "Outside" << std::endl;
	}
	std::cout << YELLOW "POINT ON VERTEX C" RESET << std::endl;
	{
		Point point(6.0, 1.0);

		if (bsp(a, b, c, point))
			std::cout << "Inside" << std::endl;
		else
			std::cout << "Outside" << std::endl;
	}

	std::cout << YELLOW "POINT OUTSIDE" RESET << std::endl;
	{
		Point point(7.0, 7.0);

		if (bsp(a, b, c, point))
			std::cout << "Inside" << std::endl;
		else
			std::cout << "Outside" << std::endl;
	}
}