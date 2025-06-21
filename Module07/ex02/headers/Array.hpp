/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:34:50 by marvin            #+#    #+#             */
/*   Updated: 2025/02/18 16:10:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template < typename T >
class Array
{
	private:
		T *tab;
		unsigned int n;

	public:
		Array(void) : n(0) { this->tab = new T[0]; }
		Array(unsigned int n) : n(n) { this->tab = new T[n](); }
		Array(const Array &cpy) : n(cpy.n)
		{
			this->tab = new T[cpy.n];
			for (unsigned int i = 0; i < cpy.n; i++)
				tab[i] = cpy.tab[i];
		}
		~Array(void) { delete [] this->tab; }

		Array &operator=(const Array &cpy)
		{
			if (this != &cpy)
			{
				delete [] this->tab;
				this->n = cpy.n;
				this->tab = new T[cpy.n];
				for (unsigned int i = 0; i < cpy.n; i++)
					tab[i] = cpy.tab[i];
			}
			return *this;
		}

		unsigned int	size(void) { return this->n; }

		T &operator[](unsigned int i)
		{
			if (i >= size() || i < 0)
				throw OutOfBoundsException();
			return this->tab[i];
		}

	class OutOfBoundsException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return "Index out of bounds";
			}
	};
};



#endif