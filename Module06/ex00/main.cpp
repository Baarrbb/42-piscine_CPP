/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 23:53:09 by marvin            #+#    #+#             */
/*   Updated: 2025/02/16 17:51:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Wrong number of argument." << std::endl;
		return 1;
	}

	ScalarConverter::convert(av[1]);

	{
		// Preuve non instanciable
		// ScalarConverter s;
	}

	return 0;
}