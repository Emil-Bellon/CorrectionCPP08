/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 14:56:11 by marvin            #+#    #+#             */
/*   Updated: 2022/04/10 14:56:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <climits>

class Span
{
	private:
		unsigned int		_n;
		std::vector<int>	_vector;

	public:
		Span();
		Span(unsigned int N);
		Span(Span const &src);

		~Span();

		Span	&operator=(Span const &src);

		class SpanFullException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class SpanTooSmallException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		std::vector<int> const &	getVector() const;
		void						addNumber(int nb);
		void						addNumber(std::vector<int> vec);
		int							shortestSpan() const;
		int							longestSpan() const;

};

std::ostream	&operator<<(std::ostream &o, Span &src);