/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:44:07 by marvin            #+#    #+#             */
/*   Updated: 2024/09/30 19:31:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : 
	AForm("RobotomyRequestForm", 72, 45), target("none")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
	AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) :
	AForm(cpy), target(cpy.target)
{
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &cpy)
{
	if (this != &cpy)
	{
		AForm::operator=(cpy);
		this->target = cpy.target;
	}
	return *this;
}

// Exception

const char* RobotomyRequestForm::RobotomyFailedException::what() const throw()
{
	return RED "Robotomy failed." RESET;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	else if (!this->getSign())
		throw AForm::NotSigned();
	else
	{
		srand(time(0));
		int r = rand() % 2;
		std::cout << "Some drilling noises ..." << std::endl;
		if (r)
			std::cout << this->target << " has been robotomized." << std::endl;
		else
			throw RobotomyRequestForm::RobotomyFailedException();
	}
}
