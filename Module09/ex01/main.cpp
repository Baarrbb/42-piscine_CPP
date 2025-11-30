/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:57:21 by marvin            #+#    #+#             */
/*   Updated: 2024/10/03 20:45:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			throw std::runtime_error(RED "Error : need one expression." RESET);
		RPN rpn(av[1]);
		rpn.calculate();
	}
	catch(const std::runtime_error& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}
