/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:47:34 by marvin            #+#    #+#             */
/*   Updated: 2025/02/26 18:20:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <climits>
#include <iostream>
#include <sys/time.h>

PmergeMe::PmergeMe(void)
{}

PmergeMe::PmergeMe(char **av)
{
	for (int i = 1; av[i]; i++)
	{
		for (int j = 0; av[i][j]; j++)
		{
			if (!isdigit(av[i][j]))
				throw std::runtime_error(RED "Error: Only positive integer." RESET);
		}
		long n = strtol(av[i], 0, 10);
		if (n > INT_MAX)
			throw std::runtime_error(RED "Error: Only positive integer." RESET);
		if (n < 0)
			throw std::runtime_error(RED "Error: Only positive integer." RESET);
		this->vec.push_back(static_cast<int>(n));
		this->deq.push_back(static_cast<int>(n));
	}
}

PmergeMe::PmergeMe(const PmergeMe &cpy) {
	this->vec = cpy.vec;
	this->deq = cpy.deq;
}

PmergeMe::~PmergeMe(void)
{}

PmergeMe &PmergeMe::operator=(const PmergeMe &cpy)
{
	if (this == &cpy)
		return *this;
	this->vec.clear();
	this->deq.clear();
	this->vec = cpy.vec;
	this->deq = cpy.deq;
	return *this;
}



void	PmergeMe::printTime(double timeVec, double timeDeq)
{
	std::cout << std::fixed << std::setprecision(3);
	std::cout << "time to process a range of " << this->vec.size();
	std::cout << " elements with std::vector : " << timeVec << " µs" << std::endl;

	std::cout << "time to process a range of " << this->deq.size();
	std::cout << " elements with std::deque : " << timeDeq << " µs" << std::endl;
}

std::vector<int> jacobsthalNumber( size_t n )
{
	std::vector<int> jacob;
	if (n == 0)
		return jacob;
	jacob.push_back(0);
	if (n == 1)
		return jacob;
	jacob.push_back(1);
	while (true) {
		size_t next = jacob[jacob.size() - 2] * 2 + jacob[jacob.size() - 1];
		if (next > n)
			break ;
		jacob.push_back(jacob[jacob.size() - 2] * 2 + jacob[jacob.size() - 1]);
	}
	return jacob;
}


void PmergeMe::sortVec(std::vector<int> &vecToSort) {

	if (vecToSort.size() < 2)
		return ;

	bool	is_odd = vecToSort.size() % 2;
	int		odd_nb;
	std::vector<int>::iterator	it;
	std::vector<int>	big;
	std::vector<int>	small;

	for (it = vecToSort.begin(); it != vecToSort.end(); it += 2)
	{
		if (it + 1 == vecToSort.end()) {
			odd_nb = *it;
			break ;
		}
		if (*it < *(it + 1)) {
			small.push_back(*it);
			big.push_back(*(it + 1));
		}
		else {
			big.push_back(*it);
			small.push_back(*(it + 1));
		}
	}

	sortVec(big);
	std::vector<int> jacobNb = jacobsthalNumber(small.size());
	std::vector<bool> alreadyInsert(small.size(), false);

	for (size_t i = 0; i < jacobNb.size(); ++i) {
		int idx = jacobNb[i];
		if (idx >= static_cast<int>(jacobNb.size()) || alreadyInsert[idx])
			continue ;

		std::vector<int>::iterator it = std::lower_bound(big.begin(), big.end(), small[idx]);
		big.insert(it, small[idx]);
		alreadyInsert[idx] = true;
	}

	for (size_t i = 0; i < small.size(); i++) {
		if (!alreadyInsert[i]) {
			std::vector<int>::iterator it = std::lower_bound(big.begin(), big.end(), small[i]);
			big.insert(it, small[i]);
		}
	}

	if (is_odd) {
		std::vector<int>::iterator it = std::lower_bound(big.begin(), big.end(), odd_nb);
		big.insert(it, odd_nb);
	}
	vecToSort = big;
}


void PmergeMe::sortDeque(std::deque<int> &deqToSort) {

	if (deqToSort.size() < 2)
		return ;

	bool	is_odd = deqToSort.size() % 2;
	int		odd_nb;
	std::deque<int>::iterator	it;
	std::deque<int>	big;
	std::deque<int>	small;

	for (it = deqToSort.begin(); it != deqToSort.end(); it += 2)
	{
		if (it + 1 == deqToSort.end()) {
			odd_nb = *it;
			break ;
		}
		if (*it < *(it + 1)) {
			small.push_back(*it);
			big.push_back(*(it + 1));
		}
		else {
			big.push_back(*it);
			small.push_back(*(it + 1));
		}
	}
	sortDeque(big);
	std::vector<int> jacobNb = jacobsthalNumber(small.size());
	std::vector<bool> alreadyInsert(small.size(), false);

	for (size_t i = 0; i < jacobNb.size(); ++i) {
		int idx = jacobNb[i];
		if (idx >= static_cast<int>(jacobNb.size()) || alreadyInsert[idx])
			continue ;

		std::deque<int>::iterator it = std::lower_bound(big.begin(), big.end(), small[idx]);
		big.insert(it, small[idx]);
		alreadyInsert[idx] = true;
	}

	for (size_t i = 0; i < small.size(); i++) {
		if (!alreadyInsert[i]) {
			std::deque<int>::iterator it = std::lower_bound(big.begin(), big.end(), small[i]);
			big.insert(it, small[i]);
		}
	}

	if (is_odd) {
		std::deque<int>::iterator it = std::lower_bound(big.begin(), big.end(), odd_nb);
		big.insert(it, odd_nb);
	}
	deqToSort = big;
}


void PmergeMe::sort(void)
{
	std::cout << "Before: ";
	printContainer(this->vec);

	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);
	double startVec = start.tv_sec * 1000000.0 + start.tv_nsec / 1000.0;

	sortVec(this->vec);

	clock_gettime(CLOCK_MONOTONIC, &end);
	double endVec = end.tv_sec * 1000000.0 + end.tv_nsec / 1000.0;
	double timeVec = endVec - startVec;


	clock_gettime(CLOCK_MONOTONIC, &start);
	double startDeq = start.tv_sec * 1000000.0 + start.tv_nsec / 1000.0;

	sortDeque(this->deq);

	clock_gettime(CLOCK_MONOTONIC, &end);
	double endDeq = end.tv_sec * 1000000.0 + end.tv_nsec / 1000.0;
	double timeDeq = endDeq - startDeq;

	std::cout << "After: ";
	printContainer(this->vec);
	printTime(timeVec, timeDeq);
}
