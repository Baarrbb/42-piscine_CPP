/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:54:51 by marvin            #+#    #+#             */
/*   Updated: 2024/06/23 17:07:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

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

class	Fixed
{
	public:
	Fixed(void);
	Fixed(int const nb);
	Fixed(const float nb);
	Fixed(const Fixed&);
	~Fixed(void);

	Fixed	&operator=(const Fixed &);

	bool	operator>(const Fixed &) const;
	bool	operator<(const Fixed &) const;
	bool	operator>=(const Fixed &) const;
	bool	operator<=(const Fixed &) const;
	bool	operator==(const Fixed &) const;
	bool	operator!=(const Fixed &) const;

	Fixed	operator+(const Fixed &);
	Fixed	operator-(const Fixed &);
	Fixed	operator*(const Fixed &);
	Fixed	operator/(const Fixed &);

	Fixed	operator++(int); // post
	Fixed	&operator++(void); // pre
	Fixed	operator--(int); // post
	Fixed	&operator--(void); // pre

	static const Fixed	&min(const Fixed &, const Fixed &);
	static Fixed		&min(Fixed &, Fixed &);
	static const Fixed	&max(const Fixed &, const Fixed &);
	static Fixed		&max(Fixed &, Fixed &);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	private:
	int					_valueNbFixed;
	static const int	_nbBits = 8;
};

std::ostream	&operator<<(std::ostream& os, const Fixed &f);

#endif