/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:28:19 by marvin            #+#    #+#             */
/*   Updated: 2024/09/21 17:57:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm(void) : name("AForm"), sign(false), signGrade(150), execGrade(150)
{
}

AForm::AForm(std::string name, int signGrade, int execGrade) : name(name), sign(false), signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &cpy) : 
	 name(cpy.name), sign(cpy.sign), signGrade(cpy.signGrade), execGrade(cpy.execGrade)
{
}

AForm::~AForm(void)
{
}

AForm &AForm::operator=(const AForm &f)
{
	if (this == &f)
		return *this;
	this->sign = f.sign;
	return *this;
}

// Getters

std::string AForm::getName(void) const
{
	return this->name;
}

bool	AForm::getSign(void) const
{
	return this->sign;
}

int		AForm::getSignGrade(void) const
{
	return this->signGrade;
}

int		AForm::getExecGrade(void) const
{
	return this->execGrade;
}


////////

int AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->signGrade)
		throw AForm::GradeTooLowException();
	else if (this->sign)
		return 0;
	else
		this->sign = true;
	return 1;
}

// Exceptions

const char* AForm::GradeTooHighException::what() const throw()
{
	return RED "Grade too high" RESET;
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return RED "Grade too low" RESET;
}

const char* AForm::NotSigned::what() const throw()
{
	return RED "Form not signed" RESET;
}

///

std::ostream& operator<<(std::ostream& os, const AForm &f)
{
	os << std::left;
	os << "Form informations" << std::endl;
	os << std::setw(20) << "Name " << ": " << f.getName() << std::endl;;
	os << std::setw(20) << "Signed " << ": " <<  f.getSign() << std::endl;
	os << std::setw(20) << "Sign grade " << ": " << f.getSignGrade() << std::endl;
	os << std::setw(20) << "Execution Grade " << ": " << f.getExecGrade() << std::endl;
	return os;
}
