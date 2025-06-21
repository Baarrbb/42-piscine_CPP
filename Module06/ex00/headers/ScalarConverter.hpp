/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 23:49:38 by marvin            #+#    #+#             */
/*   Updated: 2025/02/16 17:29:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <climits>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <iomanip>

# define BOLD "\033[1m"
# define UNDERLINE "\033[4m"
# define RESET "\033[0m"

# define RED "\033[31m"
# define BLACK "\x1B[30m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define BLUE "\x1B[34m"
# define MAGENTA "\x1B[35m"
# define CYAN "\x1B[36m"
# define JAUNE "\033[38;5;228m"
# define ROUGE "\033[38;5;88m"
# define VERT "\033[38;5;29m"

enum	type {
	NONE,
	INT,
	FLOAT,
	DOUBLE,
	CHAR,
	INFF,
	INF,
	NANN
};

class	ScalarConverter
{
	public:
		static void	convert(std::string const litt);

	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &);
		~ScalarConverter(void);
		ScalarConverter &operator=(const ScalarConverter &);
};

#endif