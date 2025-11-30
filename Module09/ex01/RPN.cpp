/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:57:39 by marvin            #+#    #+#             */
/*   Updated: 2025/02/26 17:30:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
	this->ope = "+-*/";
	this->func[0] = add;
	this->func[1] = sub;
	this->func[2] = mult;
	this->func[3] = divi;
}

RPN::RPN(std::string const &exp)
{
	this->ope = "+-*/";
	this->func[0] = add;
	this->func[1] = sub;
	this->func[2] = mult;
	this->func[3] = divi;
	this->exp = exp;
}

RPN::RPN(const RPN &cpy)
{
	this->numbers = cpy.numbers;
	this->ope = cpy.ope;
	this->exp = cpy.exp;
	for (int i = 0; i < 4; i++)
		this->func[i] = cpy.func[i];
}

RPN::~RPN(void)
{
}

RPN	&RPN::operator=(const RPN &cpy)
{
	if (this != &cpy)
	{
		this->numbers = cpy.numbers;
		this->ope = cpy.ope;
		this->exp = cpy.exp;
		for (int i = 0; i < 4; i++)
			this->func[i] = cpy.func[i];
	}
	return *this;
}

int	RPN::mult(int nb1, int nb2)
{
	return nb1 * nb2;
}

int	RPN::add(int nb1, int nb2)
{
	return nb1 + nb2;
}

int	RPN::sub(int nb1, int nb2)
{
	return nb1 - nb2;
}

int	RPN::divi(int nb1, int nb2)
{
	if (nb2 == 0)
		throw std::runtime_error(RED "Error: Can't divide by 0." RESET);
	return nb1 / nb2;
}

std::string	eraseSpace(std::string tmp)
{
	while(!tmp.empty() && isspace(tmp[0]))
		tmp.erase(0, 1);
	return tmp;
}

int	isOp(char c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return 1;
	return 0;
}

void	RPN::calculate(void)
{
	std::string	tmp = this->exp;
	int			res;

	while (!tmp.empty())
	{
		tmp = eraseSpace(tmp);
		if (tmp.empty())
			break ;
		if (isdigit(tmp[0]))
		{
			int nb = static_cast<int>(tmp[0]) - '0';
			this->numbers.push(nb);
			tmp.erase(0, 1);
		}
		else if (isOp(tmp[0]) && this->numbers.size() >= 2)
		{
			int nb2 = this->numbers.top();
			this->numbers.pop();
			int nb1 = this->numbers.top();
			this->numbers.pop();
			size_t pos = this->ope.find(tmp[0]);
			res = this->func[pos](nb1, nb2);
			this->numbers.push(res);
			tmp.erase(0, 1);
		}
		else
			throw std::runtime_error(RED "Error" RESET);
	}
	if (this->numbers.size() != 1)
		throw std::runtime_error(RED "Error: Invalid RPN expression." RESET);
	
	std::cout << this->numbers.top() << std::endl;
}
