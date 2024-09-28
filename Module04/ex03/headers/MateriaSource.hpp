/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:21:28 by marvin            #+#    #+#             */
/*   Updated: 2024/07/08 07:23:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
	MateriaSource(void);
	MateriaSource(const MateriaSource&);
	~MateriaSource(void);
	
	MateriaSource &operator=(const MateriaSource &);
	
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);

	private:
	AMateria	*m[4];
};

#endif