/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:48:15 by marvin            #+#    #+#             */
/*   Updated: 2024/06/22 20:10:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#define RESET "\033[0m"
#define JAUNE "\033[38;5;228m"
#define ROUGE "\033[38;5;88m"
#define VERT "\033[38;5;29m"
#define RED "\033[31m"

static std::string	replace_in_file(std::ifstream &ifs, std::string s1, std::string s2)
{
	std::string	line;
	std::string	text;

	while (getline(ifs, line))
	{
		size_t	i = 0;
		while ((i = line.find(s1, i)) != std::string::npos)
		{
			line.erase(i, std::string(s1).length());
			line.insert(i, s2);
			i += std::string(s2).length();
		}
		text += line;
		text += "\n";
	}
	return text;
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << JAUNE "USAGE :" RESET << std::endl;
		std::cout << "./replace  <filename>  <s1>  <s2>" << std::endl;
		return 0;
	}

	std::ifstream	ifs(av[1]);
	if (!ifs)
	{
		std::cerr << RED "[Error]" RESET << std::endl;
		std::cout << "Unable to open : " << av[1] << std::endl;
		return 0;
	}

	// std::string	newF = av[1] + std::string(".replace");
	std::string		newF = std::string(av[1]).append(".replace");
	std::ofstream	ofs(newF.c_str());
	if (!ofs)
	{
		std::cerr << RED "[Error]" RESET << std::endl;
		std::cout << "Unable to create : " << newF << std::endl;
		ifs.close();
		return 0;
	}

	ofs << replace_in_file(ifs, av[2], av[3]);

	ifs.close();
	ofs.close();
	return 0;
}
