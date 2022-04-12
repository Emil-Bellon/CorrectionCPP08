/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:48:25 by marvin            #+#    #+#             */
/*   Updated: 2022/04/10 15:48:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iterator>
#include <list>
#include <vector>
#include "MutantStack.hpp"

int main()
{
	{
		MutantStack<int> mstack;
		
		mstack.push(5);
		mstack.push(17);
		
		std::cout << "Top value in mutant stack: " << mstack.top() << std::endl;
		std::cout << std::endl;

		mstack.pop();
		std::cout << "Top value popped. New top value: " << mstack.top() << std::endl;
		std::cout << std::endl;
		
		std::cout << "Stack size: " << mstack.size() << std::endl;
		std::cout << std::endl;

		std::cout << "Adding 4 values in mstack..." << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		std::cout << "4 values in mstack added..." << std::endl;
		std::cout << std::endl;
		
		std::cout << "Print mstack:" << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << " - " << *it << std::endl;
			++it;
		}
		
		std::stack<int> s(mstack);
	}
	std::cout << std::endl;
	{
		std::list<int> mstack;
		
		mstack.push_front(5);
		mstack.push_front(17);
		
		std::cout << "Top value in mutant stack: " << mstack.front() << std::endl;
		std::cout << std::endl;

		mstack.pop_front();
		std::cout << "Top value popped. New top value: " << mstack.front() << std::endl;
		std::cout << std::endl;
		
		std::cout << "Stack size: " << mstack.size() << std::endl;
		std::cout << std::endl;

		std::cout << "Adding 4 values in mstack..." << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);
		std::cout << "4 values in mstack added..." << std::endl;
		std::cout << std::endl;
		
		std::cout << "Print mstack:" << std::endl;
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << " - " << *it << std::endl;
			++it;
		}
	}
	std::cout << std::endl;
	{
		MutantStack<int> original;
		original.push(42);
		original.push(43);
		original.push(44);

		std::cout << "original size = " << original.size() << std::endl;
		std::cout << "original begin = " << *original.begin() << std::endl;
		std::cout << "original end = " << *(original.end() - 1) << std::endl;
		std::cout << std::endl;

		std::cout << "Copy tests" << std::endl;
		MutantStack<int> copy = original;
		std::cout << "copy begin = " << *copy.begin() << std::endl;
		*copy.begin() =  10;
		std::cout << "copy begin changed = " << *copy.begin() << std::endl;
		std::cout << "original begin still same = " << *original.begin() << std::endl;
	}
	return 0;
}