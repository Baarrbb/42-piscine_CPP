/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:32:20 by marvin            #+#    #+#             */
/*   Updated: 2025/02/16 17:22:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	std::cout << YELLOW "FORM DONT EXISTS" RESET << std::endl;
	{
		Intern randomIntern;
		AForm *rrf;
		try
		{
			Bureaucrat b("lala", 1);
			rrf = randomIntern.makeForm("LALA", "bender");
			b.signForm(*rrf);
			b.executeForm(*rrf);
			delete rrf;
		}
		catch (Intern::FormNotFound& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << YELLOW "FORM SHRUBBERY" RESET << std::endl;
	{
		Intern randomIntern;
		AForm *rrf;
		try
		{
			Bureaucrat b("lala", 10);
			rrf = randomIntern.makeForm("shrubbery creation", "bender");
			b.signForm(*rrf);
			b.executeForm(*rrf);
			delete rrf;
			
		}
		catch (Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::GradeTooHighException& e)
		{
			delete rrf;
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::GradeTooLowException& e)
		{
			delete rrf;
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::NotSigned& e)
		{
			delete rrf;
			std::cerr << e.what() << std::endl;
		}
		catch (ShrubberyCreationForm::OpenFileException& e)
		{
			delete rrf;
			std::cerr << e.what() << std::endl;
		}
		catch (Intern::FormNotFound& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << YELLOW "FORM ROBOTOMY" RESET << std::endl;
	{
		Intern randomIntern;
		AForm *rrf;
		try
		{
			Bureaucrat b("lala", 1);
			rrf = randomIntern.makeForm("robotomy request", "bender");
			b.signForm(*rrf);
			b.executeForm(*rrf);
			delete rrf;
		}
		catch (Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::GradeTooHighException& e)
		{
			delete rrf;
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::GradeTooLowException& e)
		{
			delete rrf;
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::NotSigned& e)
		{
			delete rrf;
			std::cerr << e.what() << std::endl;
		}
		catch (RobotomyRequestForm::RobotomyFailedException& e)
		{
			delete rrf;
			std::cerr << e.what() << std::endl;
		}
		catch (Intern::FormNotFound& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << YELLOW "FORM PRESIDENTIAL" RESET << std::endl;
	{
		Intern randomIntern;
		AForm *rrf;
		try
		{
			Bureaucrat b("lala", 1);
			rrf = randomIntern.makeForm("presidential pardon", "bender");
			b.signForm(*rrf);
			b.executeForm(*rrf);
			delete rrf;
		}
		catch (Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::GradeTooHighException& e)
		{
			delete rrf;
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::GradeTooLowException& e)
		{
			delete rrf;
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::NotSigned& e)
		{
			delete rrf;
			std::cerr << e.what() << std::endl;
		}
		catch (Intern::FormNotFound& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	return 0;
}
