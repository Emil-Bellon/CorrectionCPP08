/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 14:41:47 by marvin            #+#    #+#             */
/*   Updated: 2022/04/10 14:41:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>
#include "easyfind.hpp"

int main(void)
{
	{
		std::vector<int>	tab;
		int					needle;

		for(size_t i = 0; i < 10; i++)
			tab.push_back(i);
		needle = 4;		
		try {
			std::cout << easyfind(tab, needle) << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << " " << needle << std::endl;
		}
		needle = 10;		
		try {
			std::cout << easyfind(tab, needle) << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << " " << needle << std::endl;
		}
	}
	{
		std::list<char>		tab;
		char				needle;

		for(size_t i = 'a'; i < 'h'; i++)
			tab.push_back(i);
		needle = 'f';		
		try {
			std::cout << static_cast<char>(easyfind(tab, needle)) << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << " " << needle << std::endl;
		}
		needle = 'x';		
		try {
			std::cout << easyfind(tab, needle) << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << " " << needle << std::endl;
		}
	}
	{
		std::list<char>		tab;
		char				needle;

		needle = 'f';		
		try {
			std::cout << static_cast<char>(easyfind(tab, needle)) << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}