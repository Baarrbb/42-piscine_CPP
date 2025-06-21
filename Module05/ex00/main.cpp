/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:32:20 by marvin            #+#    #+#             */
/*   Updated: 2025/02/16 16:07:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << YELLOW "Testing : Construct too low (151)" RESET << std::endl;
	{
		try
		{
			Bureaucrat b("test", 151);
			std::cout << b;
			b.decrGrade();
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << YELLOW "Testing : Construct too high (0)" RESET << std::endl;
	{
		try
		{
			Bureaucrat b("test", 0);
			std::cout << b;
			b.incrGrade();
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	
	std::cout << YELLOW "Testing : TEST from 150 + 1" RESET << std::endl;
	{
		try
		{
			Bureaucrat b;
			std::cout << b;
			b.decrGrade();
			std::cout << b;
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << YELLOW "Testing : TEST from 1 - 1" RESET << std::endl;
	{
		try
		{
			Bureaucrat b("lala", 1);
			std::cout << b;
			b.incrGrade();
			std::cout << b;
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << YELLOW "Testing : TEST no error" RESET << std::endl;
	{
		try
		{
			Bureaucrat b("n2", 2);
			Bureaucrat c("n149", 149);
			std::cout << b;
			std::cout << c;
			std::cout << std::endl;
			b.incrGrade();
			c.decrGrade();
			std::cout << b;
			std::cout << c;
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cerr << e.what() << std::endl;
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	return 0;
}