/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:01:56 by marvin            #+#    #+#             */
/*   Updated: 2025/02/18 17:19:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

Span::Span(void) : N(0)
{
}

Span::Span(unsigned int N) : N(N)
{
}

Span::Span(const Span &cpy) : N(cpy.N)
{
	// std::vector<int>::const_iterator	it = cpy.tab.begin();
	// std::vector<int>::const_iterator	ite = cpy.tab.end();
	// this->tab.insert(this->tab.begin(), it, ite);

	this->tab.insert(this->tab.begin(), cpy.tab.begin(), cpy.tab.end());
}

Span::~Span(void)
{
}

Span &Span::operator=(const Span &cpy)
{
	if (this == &cpy)
		return *this;
	std::vector<int>::const_iterator	it = cpy.tab.begin();
	std::vector<int>::const_iterator	ite = cpy.tab.end();
	this->tab.clear();
	this->N = cpy.N;
	this->tab.insert(this->tab.begin(), it, ite);
	return *this;
}

void	Span::addNumber(int num)
{
	try
	{
		if (this->tab.size() >= N)
			throw std::runtime_error(RED "Span already full" RESET);
		this->tab.push_back(num);
	}
	catch (std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	Span::addRandomNumber(int quantityToAdd)
{
	if (quantityToAdd < 0)
		throw std::runtime_error(RED "Wrong quantity. It has to be positive number." RESET);
	if (static_cast<unsigned int>(quantityToAdd) > N - this->tab.size())
		throw std::runtime_error(RED "Trying to add too many numbers." RESET);
	srand(time(0));
	for (int i = 0; i < quantityToAdd; i++)
	{
		int rd = rand() % 2000000;
		rd -= 1000000;
		this->addNumber(rd);
	}
}

void	Span::addRandomNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
	if (begin > end)
		throw std::runtime_error(RED "Wrong parameters." RESET);
	if (this->tab.size() + std::distance(begin, end) > N)
		throw std::runtime_error(RED "Trying to add to many values." RESET);
	this->tab.insert(this->tab.end(), begin, end);
}

unsigned int	Span::shortestSpan(void)
{
	if (this->tab.size() < 2)
		throw std::runtime_error(RED "Not enough values." RESET);

	unsigned int	min = UINT_MAX;
	std::vector<int> tmp = this->tab;
	sort(tmp.begin(), tmp.end());

	for (size_t i = 1; i < tmp.size(); i++)
	{
		if (min > static_cast<unsigned int>(tmp[i] - tmp[i - 1]))
			min = tmp[i] - tmp[i - 1];
	}
	return min;
}

unsigned int	Span::longestSpan(void)
{
	if (this->tab.size() < 2)
		throw std::runtime_error(RED "Not enough values." RESET);

	std::vector<int> tmp = this->tab;
	sort(tmp.begin(), tmp.end());

	return tmp[tmp.size() - 1] - tmp[0];
}




void	Span::printElt(void)
{
	std::vector<int>::const_iterator	it;
	std::vector<int>::const_iterator	ite = this->tab.end();

	std::cout << BLUE "PRINT" RESET<< std::endl;
	for(it = this->tab.begin(); it != ite; ++it)
		std::cout << *it << std::endl;
}
