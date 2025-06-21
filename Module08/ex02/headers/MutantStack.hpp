/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:48:52 by marvin            #+#    #+#             */
/*   Updated: 2025/02/18 18:07:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

# define RED "\033[31m"
# define RESET "\033[0m"
# define YELLOW "\x1B[33m"
# define BLUE "\x1B[34m"

#include <iostream>
#include <stack>
#include <deque>
#include <vector>
#include <list>

template< typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack< T, Container >
{
	public:
		MutantStack(void) : std::stack<T, Container>() {}
		MutantStack(const Container& cont) : std::stack<T, Container>(cont) {}
		MutantStack(const MutantStack &cpy) : std::stack<T, Container>(cpy) {}
		~MutantStack(void) {}

		MutantStack& operator=(const MutantStack &cpy)
		{
			if (this != &cpy)
				std::stack<T, Container>::operator=(cpy);
			return *this;
		}

		typedef typename Container::iterator				iterator;
		typedef typename Container::const_iterator			const_iterator;
		typedef typename Container::reverse_iterator		reverse_iterator;
		typedef typename Container::const_reverse_iterator	const_reverse_iterator;

		iterator	begin()
		{
			return	this->c.begin();
		}
		const_iterator	begin() const
		{
			return	this->c.begin();
		}

		iterator	end()
		{
			return	this->c.end();
		}
		const_iterator	end() const
		{
			return	this->c.end();
		}

		reverse_iterator	rbegin()
		{
			return this->c.rbegin();
		}
		const_reverse_iterator	rbegin() const
		{
			return this->c.rbegin();
		}
		reverse_iterator	rend()
		{
			return this->c.rend();
		}
		const_reverse_iterator	rend() const
		{
			return this->c.rend();
		}

};



#endif