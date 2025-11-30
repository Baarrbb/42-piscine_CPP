/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 00:19:46 by marvin            #+#    #+#             */
/*   Updated: 2025/02/18 18:53:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac != 2)
			throw std::runtime_error(YELLOW "Usage: ./btc file" RESET);

		BitcoinExchange btc;
		btc.convWallet(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}