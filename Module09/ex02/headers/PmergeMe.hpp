/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:47:16 by marvin            #+#    #+#             */
/*   Updated: 2024/10/06 19:56:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# define RED "\033[31m"
# define RESET "\033[0m"
# define YELLOW "\x1B[33m"
# define BLUE "\x1B[34m"

#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>
#include <ctime>
#include <iomanip>

class PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(char **av);
		PmergeMe(const PmergeMe&);
		~PmergeMe(void);

		PmergeMe& operator=(const PmergeMe&);

		void	sort(void);

	private:
		void	sortVec(std::vector<int> &vecToSort);
		void	sortDeque(std::deque<int> &deqToSort);
		void	printTime(double timeVec, double timeDeq);

		std::deque<int>		deq;
		std::vector<int>	vec;
		
		template< typename T >
		void	printContainer(T container) {
			typename T::iterator	it;
			for (it = container.begin(); it != container.end(); it++)
				std::cout << *it << " ";
			std::cout << std::endl;
		}
};


#endif