/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:44:07 by marvin            #+#    #+#             */
/*   Updated: 2024/09/30 19:30:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : 
	AForm("shrubberycreationform", 145, 137), target("none")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
	AForm("shrubberycreationform", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) :
	AForm(cpy), target(cpy.target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &cpy)
{
	if (this != &cpy)
	{
		AForm::operator=(cpy);
		this->target = cpy.target;
	}
	return *this;
}

// Exception

const char* ShrubberyCreationForm::OpenFileException::what() const throw()
{
	return RED "Error opening file" RESET;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();
	else if (!this->getSign())
		throw AForm::NotSigned();
	else
	{
		std::string	fileName = this->target + "_shrubbery";
		std::ofstream ofs(fileName.c_str());

		if (!ofs.is_open())
			throw ShrubberyCreationForm::OpenFileException();
		else
		{
			ofs << "                                                         ." << std::endl;
			ofs << "                                              .         ;" << std::endl;
			ofs << "                 .              .              ;%     ;;" << std::endl;
			ofs << "                   ,           ,                :;%  %;" << std::endl;
			ofs << "                    :         ;                   :;%;'     .," << std::endl;
			ofs << "           ,.        %;     %;            ;        %;'    ,;" << std::endl;
			ofs << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
			ofs << "              %;       %;%;      ,  ;       %;  ;%;   ,%;'" << std::endl;
			ofs << "               ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
			ofs << "                `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
			ofs << "                 `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
			ofs << "                    `:%;.  :;bd%;          %;@%;'" << std::endl;
			ofs << "                      `@%:.  :;%.         ;@@%;'" << std::endl;
			ofs << "                        `@%.  `;@%.      ;@@%;" << std::endl;
			ofs << "                          `@%%. `@%%    ;@@%;" << std::endl;
			ofs << "                            ;@%. :@%%  %@@%;" << std::endl;
			ofs << "                              %@bd%%%bd%%:;" << std::endl;
			ofs << "                                #@%%%%%:;;" << std::endl;
			ofs << "                                %@@%%%::;" << std::endl;
			ofs << "                                %@@@%(o);  . '" << std::endl;
			ofs << "                                %@@@o%;:(.,'" << std::endl;
			ofs << "                            `.. %@@@o%::;" << std::endl;
			ofs << "                               `)@@@o%::;" << std::endl;
			ofs << "                                %@@(o)::;" << std::endl;
			ofs << "                               .%@@@@%::;" << std::endl;
			ofs << "                               ;%@@@@%::;." << std::endl;
			ofs << "                              ;%@@@@%%:;;;." << std::endl;
			ofs << "                          ...;%@@@@@%%:;;;;,.." << std::endl;
		}
	}

}
