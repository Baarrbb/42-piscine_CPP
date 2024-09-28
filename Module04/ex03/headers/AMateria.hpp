/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:33:48 by marvin            #+#    #+#             */
/*   Updated: 2024/06/25 16:30:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

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

class ICharacter;

class	AMateria
{
	protected:
	std::string	type;

	public:
	AMateria(void);
	AMateria(std::string const & type);
	AMateria(const AMateria &);
	virtual ~AMateria(void);

	AMateria &operator=(const AMateria &);
	
	std::string const & getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};


#endif