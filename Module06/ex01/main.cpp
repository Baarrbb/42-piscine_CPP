/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 23:53:09 by marvin            #+#    #+#             */
/*   Updated: 2025/02/16 19:11:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data d;
	d.data = 42;

	std::cout << d.data << std::endl;

	std::cout << YELLOW "SERIALIZE" RESET << std::endl;
	uintptr_t res = Serializer::serialize(&d);
	std::cout << res << std::endl;

	std::cout << YELLOW "DESERIALIZE" RESET << std::endl;
	Data *g = Serializer::deserialize(res);
	std::cout << g->data << std::endl;

	return 0;
}
