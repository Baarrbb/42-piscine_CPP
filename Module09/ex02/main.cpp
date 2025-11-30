/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:47:38 by marvin            #+#    #+#             */
/*   Updated: 2024/10/06 19:29:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	try {
		if (ac < 2)
			throw std::runtime_error(RED "Error: Need more arguments" RESET );
		PmergeMe m(av);
		m.sort();
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
