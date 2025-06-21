/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:49:11 by marvin            #+#    #+#             */
/*   Updated: 2025/02/18 18:12:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main(void)
{
	std::cout << YELLOW "SUBJECT MAIN" RESET << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "TOP : " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "SIZE : " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << YELLOW "BEGIN cmp MutantStack et vector" RESET << std::endl;
	{
		MutantStack< int, std::vector<int> > m;
		for (int i = 1; i <= 5; i++)
			m.push(i);

		std::cout << "m contains:";
		for (MutantStack<int,  std::vector<int> >::iterator it = m.begin() ; it != m.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;

		std::vector<int> m1;
		for (int i = 1; i <= 5; i++)
			m1.push_back(i);

		std::cout << "m1 contains:";
		for (std::vector<int>::iterator it = m1.begin() ; it != m1.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
	}

	std::cout << YELLOW "CONST BEGIN diff de STL" RESET << std::endl;
	{
		MutantStack< int, std::vector<int> > m;
		for (int i = 1; i <= 5; i++)
			m.push(i);

		std::cout << "m contains:";
		for (MutantStack<int,  std::vector<int> >::const_iterator it = m.begin() ; it != m.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;

		MutantStack< int, std::list<int> > m1;
		for (int i = 1; i <= 5; i++)
			m1.push(i);

		std::cout << "m contains:";
		for (MutantStack<int,  std::list<int> >::const_iterator it = m1.begin() ; it != m1.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
	}

	std::cout << YELLOW "RBEGIN && REND" RESET << std::endl;
	{
		std::vector<int> vec(5);
		MutantStack<int, std::vector<int> > m(vec);

		int i = 0;
		MutantStack<int, std::vector<int> >::reverse_iterator rit = m.rbegin();
		for (; rit != m.rend(); ++rit)
			*rit = ++i;

		std::cout << "m contains:";
		for (MutantStack<int, std::vector<int> >::iterator it = m.begin(); it != m.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << std::endl;
	}

	return 0;
}