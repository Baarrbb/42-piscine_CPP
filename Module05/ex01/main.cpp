/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:32:20 by marvin            #+#    #+#             */
/*   Updated: 2025/02/16 16:24:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
	std::cout << YELLOW "Default form" RESET << std::endl;
	{
		Form f;
		std::cout << f;
	}

	std::cout << YELLOW "TEST ALREADY SIGNED AND BUREAUCRAT TOO LOW" RESET << std::endl;
	{
		try
		{
			Form f("form", 10, 10);
			Bureaucrat b("ppp", 9);
			std::cout << f << std::endl;
			std::cout << b << std::endl;
	
			b.signForm(f);
			std::cout << std::endl;
			std::cout << f << std::endl;
			b.signForm(f);
			std::cout << std::endl;

			Form f1("form1", 10, 10);
			Bureaucrat b1("ttt", 11);
			std::cout << f1 << std::endl;
			std::cout << b1 << std::endl;
			b1.signForm(f1);
			std::cout << f;
		}
		catch(Form::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Form::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << YELLOW "TEST CONSTRUCT" RESET << std::endl;
	{
		try
		{
			Form f("form", 151, 10);
			std::cout << f;
		}
		catch(Form::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Form::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			Form f("form", 0, 10);
			std::cout << f;
		}
		catch(Form::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Form::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			Form f("form", 11, 1454);
			std::cout << f;
		}
		catch(Form::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Form::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}

		try
		{
			Form f("form", 11, 0);
			std::cout << f;
		}
		catch(Form::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Form::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	return 0;
}