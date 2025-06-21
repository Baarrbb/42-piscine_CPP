/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 22:16:36 by marvin            #+#    #+#             */
/*   Updated: 2025/02/16 16:57:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
}

Intern::Intern(const Intern &cpy)
{
	*this = cpy;
}

Intern::~Intern(void)
{
}

Intern	&Intern::operator=(const Intern &cpy)
{
	if (this == &cpy)
		return *this;
	return *this;
}

static std::string	to_lowercase(std::string s)
{
	for(int i = 0; s[i]; i++)
		s[i] = std::tolower(s[i]);
	return s;
}

// Exceptions

const char* Intern::FormNotFound::what() const throw()
{
	return RED "Form not found." RESET;
}

AForm	*newShrub(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm	*newRobot(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm	*newPres(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(std::string form, std::string target)
{
	form = to_lowercase(form);
	std::string formName[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	AForm* (*f[3])(std::string) = {
		&newShrub,
		&newRobot,
		&newPres,
	};

	int i = 0;
	for (; i < 3; i++)
	{
		if (!form.compare(formName[i]))
			return f[i](target);
	}
	throw Intern::FormNotFound();

}
