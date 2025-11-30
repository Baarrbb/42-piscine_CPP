/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:57:47 by marvin            #+#    #+#             */
/*   Updated: 2024/10/03 20:21:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

# define RED "\033[31m"
# define RESET "\033[0m"
# define YELLOW "\x1B[33m"
# define BLUE "\x1B[34m"

#include <iostream>
#include <stack>
#include <cstdlib>

class RPN
{
	public:
		RPN(std::string const &exp);
		RPN(const RPN &);
		~RPN(void);

		RPN	&operator=(const RPN &);

		void	calculate(void);

	private:
		RPN(void);

		static int		add(int nb1, int nb2);
		static int		sub(int nb1, int nb2);
		static int		mult(int nb1, int nb2);
		static int		divi(int nb1, int nb2);

		int	(*func[4])(int, int);
		std::string	ope;
		std::stack<int>	numbers;
		std::string	exp;
};

#endif