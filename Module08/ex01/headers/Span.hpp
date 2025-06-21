/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:01:27 by marvin            #+#    #+#             */
/*   Updated: 2025/02/18 17:39:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

# define RED "\033[31m"
# define RESET "\033[0m"
# define YELLOW "\x1B[33m"
# define BLUE "\x1B[34m"

#include <vector>
#include <iostream>
#include <algorithm>


class Span
{
	public:
		Span(void);
		Span(unsigned int N);
		Span(const Span &);
		~Span(void);

		Span &operator=(const Span &);

		void	addNumber(int);
		unsigned int		shortestSpan(void);
		unsigned int		longestSpan(void);

		void		addRandomNumber(int);
		void		addRandomNumber(std::vector<int>::const_iterator from, std::vector<int>::const_iterator to);
		void	printElt(void);

	private:
		unsigned int		N;
		std::vector<int>	tab;
};

#endif