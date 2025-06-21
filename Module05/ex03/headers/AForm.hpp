/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:28:43 by marvin            #+#    #+#             */
/*   Updated: 2024/09/30 19:24:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class	AForm
{
	public:
		AForm(void);
		AForm(std::string name, int signGrade, int execGrade);
		AForm(const AForm &);
		virtual ~AForm(void);
		AForm &operator=(const AForm &);

		std::string	getName(void) const;
		bool		getSign(void) const;
		int			getSignGrade(void) const;
		int 		getExecGrade(void) const;

		int				beSigned(Bureaucrat &b);
		virtual void	execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NotSigned : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		std::string const	name ;
		bool				sign;
		int const			signGrade;
		int const			execGrade;
};

std::ostream& operator<<(std::ostream& os, const AForm &f);

#endif