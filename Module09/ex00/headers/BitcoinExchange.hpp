/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 00:18:48 by marvin            #+#    #+#             */
/*   Updated: 2025/02/24 21:03:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# define RED "\033[31m"
# define RESET "\033[0m"
# define YELLOW "\x1B[33m"
# define BLUE "\x1B[34m"

#include <iostream>
#include <map>
#include <ctime>
#include <fstream>
#include <climits>
#include <string>
#include <cstdlib>
#include <algorithm>


class BitcoinExchange
{
	public:
		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &);
		~BitcoinExchange(void);

		BitcoinExchange &operator=(const BitcoinExchange &);

		void	convWallet(const std::string&);

	private:
		std::map<std::string, double> db;

		void	setDB(void);
		void	parsingWallet(std::ifstream &);
		void	parsingDB(std::ifstream &);
		double	findDate(std::string &);
		void	printMap(std::map<std::string, double> mp);
};

#endif