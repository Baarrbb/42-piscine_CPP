/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 00:19:33 by marvin            #+#    #+#             */
/*   Updated: 2025/02/26 17:21:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <sstream>
#include <iomanip>


BitcoinExchange::BitcoinExchange(void)
{
	this->setDB();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy)
{
	this->db = cpy.db;
}

BitcoinExchange::~BitcoinExchange(void)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &cpy)
{
	if (this == &cpy)
		return *this;
	this->db = cpy.db;
	return *this;
}


static void	checkDate(std::string const &date)
{
	std::string	tmp = date;
	size_t		pos;
	std::string	dateFmt[3];
	int			daysMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (std::count(tmp.begin(), tmp.end(), '-') != 2)
		throw std::runtime_error(RED "Error: Invalid date format => \"" + date + "\" (YYYY-MM-DD expected)" RESET);
	for(int i = 0; i < 3; i++)
	{
		pos = tmp.find("-");
		dateFmt[i] = tmp.substr(0, pos);
		if (dateFmt[i].find_first_not_of("0123456789") != std::string::npos)
			throw std::runtime_error(RED "Error: Invalid date format => \"" + date + "\" (YYYY-MM-DD expected)" RESET);
		tmp.erase(0, pos + 1);
	}
	if (dateFmt[0].length() != 4 || dateFmt[1].length() != 2 || dateFmt[2].length() != 2)
		throw std::runtime_error(RED "Error: Invalid date format => \"" + date + "\" (YYYY-MM-DD expected)" RESET);
	
	struct tm	dateSt = {};
	if (!strptime(date.c_str(), "%Y-%m-%d", &dateSt))
		throw std::runtime_error(RED "Error: value out of bounds" RESET);
	if ((dateSt.tm_year + 1900) % 4 == 0)
		daysMonth[1] = 29;
	if (atoi(dateFmt[2].c_str()) > daysMonth[dateSt.tm_mon])
		throw std::runtime_error(RED "Error: Invalid date (day doesn't exist in this month) => " + date + RESET);
	if (std::time(0) < mktime(&dateSt))
		throw std::runtime_error(RED "Error: Can't be in the future => " + date + RESET);
}

double	BitcoinExchange::findDate(std::string &date)
{
	std::map<std::string, double>::iterator it;

	checkDate(date);

	it = this->db.find(date);
	if (it != this->db.end())
		return it->second;
	std::map<std::string, double>::iterator	itlow;
	itlow = this->db.lower_bound(date);
	if (itlow != this->db.begin())
	{
		itlow--;
		return itlow->second;
	}
	else
		return itlow->second;

	return -1;
}

void	BitcoinExchange::parsingWallet(std::ifstream &file)
{
	std::string	line;
	std::string	date;
	double		val;
	double		rate;
	size_t		pos;

	while(getline(file, line))
	{
		if (!line.empty() && line.compare("date | value"))
		{
			try
			{
				pos = line.find("|");
				if (pos == std::string::npos || pos == 0 || pos + 1 == line.length())
					throw std::runtime_error(RED "Error: bad input => \"" + line + "\"" RESET);

				if (line[pos - 1] != ' ' || line[pos + 1] != ' ')
					throw std::runtime_error(RED "Error: bad input => \"" + line + "\"" RESET);
				date = line.substr(0, pos - 1);

				if (!isdigit(line[pos + 2]) && line[pos + 2] != '+' && line[pos + 2] != '-')
					throw std::runtime_error(RED "Error: bad input => \"" + line + "\"" RESET);

				char *endptr = NULL;
				val = std::strtod(line.substr(pos + 2, line.length()).c_str(), &endptr);
				if (*endptr != '\0')
					throw std::runtime_error(RED "Error: bad input => \"" + line + "\"" RESET);
				
				if (val > 1000)
					throw std::runtime_error(RED "Error: too large a number => \"" + line.substr(pos + 2, line.length()) + "\"" RESET);
				if (val < 0)
					throw std::runtime_error(RED "Error: not a positive number => \"" + line.substr(pos + 2, line.length()) + "\"" RESET);

				rate = this->findDate(date);
				std::cout << date << " => " << val << " = " << rate * val << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
	}
}

void	BitcoinExchange::convWallet(const std::string& file)
{
	std::ifstream	ifs(file.c_str());

	if (!ifs.is_open())
		throw std::runtime_error(RED "Error: could not open file." RESET);
	
	this->parsingWallet(ifs);

	ifs.close();
}

void	BitcoinExchange::parsingDB(std::ifstream &file)
{
	std::string	line;
	std::string	date;
	size_t		pos;
	double		rate;

	while(getline(file, line))
	{
		if (!line.empty() && line.compare("date,exchange_rate"))
		{
			pos = line.find(",");
			date = line.substr(0, pos);
			rate = std::strtod(line.substr(pos + 1, line.length()).c_str(), 0);
			this->db[date] = rate;
		}
	}
}

void	BitcoinExchange::setDB(void)
{
	std::ifstream	ifs("./cpp_09/data.csv");

	if (!ifs.is_open())
		throw std::runtime_error(RED "Open database error." RESET);
	
	this->parsingDB(ifs);
	ifs.close();
}


void	BitcoinExchange::printMap(std::map<std::string, double> mp)
{
	for(std::map<std::string, double>::iterator it = mp.begin(); it != mp.end(); ++it)
		std::cout << "Cle : " << it->first << " val : " << it->second << std::endl;
}
