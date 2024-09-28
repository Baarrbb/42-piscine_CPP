/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:53:16 by marvin            #+#    #+#             */
/*   Updated: 2024/06/25 15:55:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

# define BOLD "\033[1m"
# define UNDERLINE "\033[4m"
# define RESET "\033[0m"

# define RED "\033[31m"
# define BLACK "\x1B[30m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define BLUE "\x1B[34m"
# define MAGENTA "\x1B[35m"
# define CYAN "\x1B[36m"
# define JAUNE "\033[38;5;228m"
# define ROUGE "\033[38;5;88m"
# define VERT "\033[38;5;29m"

class	AAnimal
{
	public:
	AAnimal(void);
	AAnimal(const AAnimal &);
	virtual ~AAnimal(void);
	AAnimal&	operator=(const AAnimal &);

	std::string	getType(void) const;
	virtual void	makeSound(void) const = 0;

	protected:
	std::string	type;
};


#endif