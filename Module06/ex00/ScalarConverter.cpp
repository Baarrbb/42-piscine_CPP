/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 23:52:21 by marvin            #+#    #+#             */
/*   Updated: 2025/02/16 18:52:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy)
{
	*this = cpy;
}

ScalarConverter::~ScalarConverter(void)
{}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &cpy)
{
	(void)cpy;
	return *this;
}

static int	get_type(std::string const litt)
{
	int		dot = 0;
	size_t	i = 0;
	if (litt.length() == 1 && !isdigit(litt[0]))
		return CHAR;
	if (!litt.compare("-inff") || !litt.compare("+inff"))
		return INFF;
	if (!litt.compare("-inf") || !litt.compare("+inf"))
		return INF;
	if (!litt.compare("nan") || !litt.compare("nanf"))
		return NANN;
	for (; litt[i]; i++)
	{
		if (i == 0 && (litt[i] == '-' || litt[i] == '+'))
			continue;
		if (!std::isdigit(litt[i]))
		{
			if (litt[i] == '.')
				dot++;
			if (dot > 1 || litt[i] != '.')
				break;
		}
	}
	if (i == litt.length() && !dot)
		return INT;
	if (i == litt.length() - 1 && isdigit(litt[i - 1]) && litt[i] == 'f' && dot == 1)
		return FLOAT;
	if (i == litt.length() && dot)
		return DOUBLE;
	return NONE;
}

/*
static int	check_limits(std::string litt)
{
	long int i = atol(litt.c_str());
	if (i > INT_MAX || i < INT_MIN)
		return 0;
	return 1;
}
*/


static void	to_int(std::string const litt, int type)
{
	std::cout << "int : ";
	if ((type == INT || type == DOUBLE || type == FLOAT) /*&& check_limits(litt)*/)
	{
		// int i = atoi(litt.c_str());
		long l = strtol(litt.c_str(), 0, 10);
		if (l < std::numeric_limits<int>::min() || l > std::numeric_limits<int>::max())
			std::cout << "impossible" << std::endl;
		else
		{
			int i = static_cast<int>(l);
			std::cout << i << std::endl;
		}
	}
	else if (type == CHAR)
	{
		int i = static_cast<int>(litt[0]);
		std::cout << i << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
}

static void	to_char(std::string litt, int type)
{
	std::cout << "char : ";
	if ((type == INT || type == DOUBLE || type == FLOAT))
	{
		double d = std::strtod(litt.c_str(), 0);
		if (d > 31 && d < 127)
		{
			unsigned char c = static_cast<unsigned char>(d);
			std::cout << "'" << c << "'" << std::endl;
		}
		else if (d > 127 || d < 0)
			std::cout << "impossible" << std::endl;
		else
			std::cout << "non displayable" << std::endl;
	}
	else if (type == CHAR)
	{
		unsigned char c = static_cast<unsigned char>(litt[0]);
		if (!std::isprint(c))
			std::cout << "non displayable" << std::endl;
		else
			std::cout << "'" << c << "'" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
}

static void	to_float(std::string const litt, int type)
{
	std::cout << "float : ";
	if (type != CHAR && type != NANN)
	{
		double d = std::strtod(litt.c_str(), 0);
		float f = static_cast<float>(d);
		if (f == std::numeric_limits<float>::infinity())
			std::cout << "+";
		if (std::floor(f) != f || f == std::numeric_limits<float>::infinity()
			|| f == -std::numeric_limits<float>::infinity() || f >= 1000000 || f <= -1000000)
			std::cout << f << "f" << std::endl;
		else
			std::cout << f << ".0f" << std::endl;

	}
	else if (type == CHAR)
	{
		float f = static_cast<float>(litt[0]);
		std::cout << f << ".0f" << std::endl;
	}
	else if (type == NANN)
		std::cout << "nanf" << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

static void	to_double(std::string const litt, int type)
{
	std::cout << "double : ";
	if (type != CHAR && type != NANN)
	{
		long double ld = std::strtold(litt.c_str(), 0);
		double d = static_cast<double>(ld);
		if ( d == std::numeric_limits<double>::infinity())
			std::cout << "+";
		std::cout << d;
		if (std::floor(d) == d && d != std::numeric_limits<double>::infinity()
			&& d != -std::numeric_limits<double>::infinity() && d < 1000000 && d > -1000000)
			std::cout << ".0";
		std::cout << std::endl;
	}
	else if (type == CHAR)
	{
		double d = static_cast<double>(litt[0]);
		std::cout << d << ".0" << std::endl;
	}
	else if (type == NANN)
		std::cout << "nan" << std::endl;
	else
		std::cout << "impossible" << std::endl;
}

void	ScalarConverter::convert(std::string const litt)
{
	int	what = get_type(litt);
	if (!what)
	{
		std::cout << "char : impossible" << std::endl;
		std::cout << "int : impossible" << std::endl;
		std::cout << "float : impossible" << std::endl;
		std::cout << "double : impossible" << std::endl;
		return ;
	}
	to_char(litt, what);
	to_int(litt, what);
	to_float(litt, what);
	to_double(litt, what);
}
