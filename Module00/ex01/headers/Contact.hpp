/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:05:18 by marvin            #+#    #+#             */
/*   Updated: 2024/09/14 14:00:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class	Contact
{
	public:
	Contact(void);
	~Contact(void);

	int			get_id(void) const;
	std::string	get_firstname(void) const;
	std::string	get_lastname(void) const;
	std::string	get_nickname(void) const;
	std::string	get_number(void) const;
	std::string	get_secret(void) const;
	
	void		set_id(int id);
	void		set_firstname(std::string name);
	void		set_lastname(std::string name);
	void		set_nickname(std::string name);
	void		set_number(std::string name);
	void		set_secret(std::string name);

	private:
	int			_id;
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_number;
	std::string	_secret;
};

#endif