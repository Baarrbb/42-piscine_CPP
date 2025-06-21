/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:28:19 by marvin            #+#    #+#             */
/*   Updated: 2024/09/30 18:46:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(void) : name("form"), sign(false), signGrade(150), execGrade(150)
{
}

Form::Form(std::string name, int signGrade, int execGrade) : name(name), sign(false), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &cpy) : 
	 name(cpy.name), sign(cpy.sign), signGrade(cpy.signGrade), execGrade(cpy.execGrade)
{
}

Form::~Form(void)
{
}

Form &Form::operator=(const Form &f)
{
	if (this == &f)
		return *this;
	this->sign = f.sign;
	return *this;
}

// Getters

std::string Form::getName(void) const
{
	return this->name;
}

bool	Form::getSign(void) const
{
	return this->sign;
}

int		Form::getSignGrade(void) const
{
	return this->signGrade;
}

int		Form::getExecGrade(void) const
{
	return this->execGrade;
}


////////

int Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->signGrade)
		throw Form::GradeTooLowException();
	else if (this->sign)
		return 0;
	else
		this->sign = true;
	return 1;
}

// Exceptions

const char* Form::GradeTooHighException::what() const throw()
{
	return RED "Grade too high" RESET;
}

const char* Form::GradeTooLowException::what() const throw()
{
	return RED "Grade too low" RESET;
}

///

std::ostream& operator<<(std::ostream& os, const Form &f)
{
	os << std::left;
	os << "Form informations" << std::endl;
	os << std::setw(20) << "Name " << ": " << f.getName() << std::endl;;
	os << std::setw(20) << "Signed " << ": " <<  f.getSign() << std::endl;
	os << std::setw(20) << "Sign grade " << ": " << f.getSignGrade() << std::endl;
	os << std::setw(20) << "Execution Grade " << ": " << f.getExecGrade() << std::endl;
	return os;
}
