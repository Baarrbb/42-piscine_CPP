/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:52:52 by marvin            #+#    #+#             */
/*   Updated: 2025/02/16 19:15:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	srand(time(0));
	int r = rand() % 3;
	switch (r)
	{
		case 0:
		{
			// std::cout << "CLASS a" << std::endl;
			return new A();
		}
		case 1:
		{
			// std::cout << "CLASS b" << std::endl;
			return new B();
		}
		case 2:
		{
			// std::cout << "CLASS c" << std::endl;
			return new C();
		}
		default:
			return 0;
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Class A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Class B" << std::endl;
	else if (dynamic_cast<C *>(p))	
		std::cout << "Class C" << std::endl;
	else
		std::cout << "Class unknown" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A& a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "Class A" << std::endl;
		return ;
	}
	catch(...)
	{
	}
	try
	{
		B& b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "Class B" << std::endl;
		return ;
	}
	catch(...)
	{
	}
	try
	{
		C& c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "Class C" << std::endl;
		return ;
	}
	catch(...)
	{
	}
	std::cout << "Class unknown" << std::endl;
}

int main(void)
{
	{
		Base *b = generate();
		identify(b);
		identify(*b);
		delete b;
	}

	{
		Base *b = new Base();
		identify(b);
		identify(*b);
		delete b;
	}

	return 0;
}