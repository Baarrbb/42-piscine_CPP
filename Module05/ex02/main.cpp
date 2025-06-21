/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:32:20 by marvin            #+#    #+#             */
/*   Updated: 2025/02/16 16:52:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void	shrubbery_tests(void)
{
	std::cout << YELLOW "TEST ShrubberyCreationForm OK" RESET << std::endl;
	{
		try
		{
			ShrubberyCreationForm s("home");
			Bureaucrat b("b", 10);
			std::cout << s;
			std::cout << b;
			b.signForm(s);
			b.executeForm(s);
		}
		catch(ShrubberyCreationForm::OpenFileException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::NotSigned& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << YELLOW "TEST ShrubberyCreationForm NOT SIGNED" RESET << std::endl;
	{
		try
		{
			ShrubberyCreationForm s("home1");
			Bureaucrat b("b", 10);
			std::cout << s;
			std::cout << b;
			b.executeForm(s);
			std::cout << s;
		}
		catch (ShrubberyCreationForm::OpenFileException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::NotSigned& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << YELLOW "TEST ShrubberyCreationForm SIGNED TWICE" RESET << std::endl;
	{
		try
		{
			ShrubberyCreationForm s("home2");
			Bureaucrat b("b", 10);
			std::cout << s;
			std::cout << b;
			b.signForm(s);
			b.signForm(s);
			b.executeForm(s);
		}
		catch (ShrubberyCreationForm::OpenFileException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::NotSigned& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << YELLOW "TEST ShrubberyCreationForm GRADE TOO LOW TO EXEC" RESET << std::endl;
	{
		try
		{
			ShrubberyCreationForm s("home3");
			Bureaucrat b("b", 138);
			std::cout << s;
			std::cout << b;
			b.signForm(s);
			b.executeForm(s);
		}
		catch (ShrubberyCreationForm::OpenFileException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::NotSigned& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << YELLOW "TEST ShrubberyCreationForm GRADE TOO LOW TO SIGN" RESET << std::endl;
	{
		try
		{
			ShrubberyCreationForm s("home4");
			Bureaucrat b("b", 146);
			std::cout << s;
			std::cout << b;
			b.signForm(s);
			b.executeForm(s);
		}
		catch (ShrubberyCreationForm::OpenFileException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::NotSigned& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}

static void	robotomy_tests(void)
{
	std::cout << YELLOW "TEST RobotomyRequestForm OK" RESET << std::endl;
	{
		try
		{
			RobotomyRequestForm s("home");
			Bureaucrat b("b", 10);
			std::cout << s;
			std::cout << b;
			b.signForm(s);
			b.executeForm(s);
		}
		catch (RobotomyRequestForm::RobotomyFailedException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::NotSigned& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << YELLOW "TEST RobotomyRequestForm NOT SIGNED" RESET << std::endl;
	{
		try
		{
			RobotomyRequestForm s("home");
			Bureaucrat b("b", 10);
			std::cout << s;
			std::cout << b;
			b.executeForm(s);
		}
		catch (RobotomyRequestForm::RobotomyFailedException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::NotSigned& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << YELLOW "TEST RobotomyRequestForm SIGNED TWICE" RESET << std::endl;
	{
		try
		{
			RobotomyRequestForm s("home");
			Bureaucrat b("b", 10);
			std::cout << s;
			std::cout << b;
			b.signForm(s);
			b.signForm(s);
			b.executeForm(s);
		}
		catch (RobotomyRequestForm::RobotomyFailedException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::NotSigned& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << YELLOW "TEST RobotomyRequestForm GRADE TOO LOW TO EXEC" RESET << std::endl;
	{
		try
		{
			RobotomyRequestForm s("home");
			Bureaucrat b("b", 62);
			std::cout << s;
			std::cout << b;
			b.signForm(s);
			b.executeForm(s);
		}
		catch (RobotomyRequestForm::RobotomyFailedException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::NotSigned& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << YELLOW "TEST RobotomyRequestForm GRADE TOO LOW TO SIGN" RESET << std::endl;
	{
		try
		{
			RobotomyRequestForm s("home");
			Bureaucrat b("b", 84);
			std::cout << s;
			std::cout << b;
			b.signForm(s);
			b.executeForm(s);
		}
		catch (RobotomyRequestForm::RobotomyFailedException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::NotSigned& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}

static void	presidential_tests(void)
{
	std::cout << YELLOW "TEST PresidentialPardonForm OK" RESET << std::endl;
	{
		try
		{
			PresidentialPardonForm s("home");
			Bureaucrat b("b", 1);
			std::cout << s;
			std::cout << b;
			b.signForm(s);
			b.executeForm(s);
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::NotSigned& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

		std::cout << YELLOW "TEST PresidentialPardonForm NOT SIGNED" RESET << std::endl;
	{
		try
		{
			PresidentialPardonForm s("home");
			Bureaucrat b("b", 1);
			std::cout << s;
			std::cout << b;
			b.executeForm(s);
			std::cout << s;
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::NotSigned& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << YELLOW "TEST PresidentialPardonForm SIGNED TWICE" RESET << std::endl;
	{
		try
		{
			PresidentialPardonForm s("home");
			Bureaucrat b("b", 1);
			std::cout << s;
			std::cout << b;
			b.signForm(s);
			b.signForm(s);
			b.executeForm(s);
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::NotSigned& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << YELLOW "TEST PresidentialPardonForm GRADE TOO LOW TO EXEC" RESET << std::endl;
	{
		try
		{
			PresidentialPardonForm s("home");
			Bureaucrat b("b", 10);
			std::cout << s;
			std::cout << b;
			b.signForm(s);
			b.executeForm(s);
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::NotSigned& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << YELLOW "TEST PresidentialPardonForm GRADE TOO LOW TO SIGN" RESET << std::endl;
	{
		try
		{
			PresidentialPardonForm s("home");
			Bureaucrat b("b", 42);
			std::cout << s;
			std::cout << b;
			b.signForm(s);
			b.executeForm(s);
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::NotSigned& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}

static void	others_tests(void)
{
	std::cout << YELLOW "TEST Bureaucrat too low" RESET << std::endl;
	{
		try
		{
			PresidentialPardonForm s("home");
			Bureaucrat b("b", 152);
			std::cout << s;
			std::cout << b;
			b.signForm(s);
			b.executeForm(s);
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::NotSigned& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << YELLOW "TEST Bureaucrat too high" RESET << std::endl;
	{
		try
		{
			PresidentialPardonForm s("home");
			Bureaucrat b("b", 0);
			std::cout << s;
			std::cout << b;
			b.signForm(s);
			b.executeForm(s);
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::NotSigned& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(AForm::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}

int main()
{
	shrubbery_tests();
	std::cout << std::endl;
	robotomy_tests();
	std::cout << std::endl;
	presidential_tests();
	std::cout << std::endl;
	others_tests();

	return 0;
}