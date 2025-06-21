/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 21:56:33 by marvin            #+#    #+#             */
/*   Updated: 2024/09/30 19:30:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : 
	AForm("PresidentialPardonForm", 25, 5), target("none")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : 
	AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy) :
	AForm(cpy), target(cpy.target)
{
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &cpy)
{
	if (this != &cpy)
	{
		AForm::operator=(cpy);
		this->target = cpy.target;
	}
	return *this;
}



void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	else if (!this->getSign())
		throw AForm::NotSigned();
	else
		std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
