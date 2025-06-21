/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:28:43 by marvin            #+#    #+#             */
/*   Updated: 2024/09/30 18:56:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class	Form
{
	public:
		Form(void);
		Form(std::string name, int signGrade, int execGrade);
		Form(const Form &);
		~Form(void);
		Form &operator=(const Form &);

		std::string	getName(void) const;
		bool		getSign(void) const;
		int			getSignGrade(void) const;
		int 		getExecGrade(void) const;

		int			beSigned(Bureaucrat &b);

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

	private:
		std::string const	name;
		bool				sign;
		int const			signGrade;
		int const			execGrade;
};

std::ostream& operator<<(std::ostream& os, const Form &f);

#endif