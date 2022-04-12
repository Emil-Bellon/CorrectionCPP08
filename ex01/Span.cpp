/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:21:25 by marvin            #+#    #+#             */
/*   Updated: 2022/04/10 15:21:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* Constructors */

Span::Span(): _n(0)
{
	this->_vector.reserve(0);
	return;
}

Span::Span(unsigned int n): _n(n)
{
	this->_vector.reserve(n);
	return;
}

Span::Span(Span const &src)
{
	*this = src;
	return;
}

/* Overload */

Span	&Span::operator=(Span const &src)
{
	this->_n = src._n;
	this->_vector.clear();
	this->_vector.reserve(src._n);
	this->_vector.insert(this->_vector.begin(), src._vector.begin(), src._vector.end());
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Span &src)
{
	int i = 0;
	std::vector<int> srcVec = src.getVector();

	for (std::vector<int>::iterator it = srcVec.begin(); it < srcVec.end(); it++)
	{
		o << "Vector at " << i << " = " << *it;
		if (it != srcVec.end() - 1)
			o << std::endl;
		i++;
	}
	return o;
}

/* Destructors */

Span::~Span()
{
	return;
}

/* Member functions */

std::vector<int> const	&Span::getVector() const
{
	return this->_vector;
}

void	Span::addNumber(int nb)
{
	if (this->_vector.size() >= this->_n)
		throw SpanFullException();
		
	this->_vector.push_back(nb);
}

void	Span::addNumber(std::vector<int> vec)
{
	if (this->_vector.size() + vec.size() > this->_n)
		throw SpanFullException();

	this->_vector.insert(this->_vector.end(), vec.begin(), vec.end());
}

int	Span::shortestSpan() const
{
	if (this->_n <= 1)
		throw SpanTooSmallException();
	
	std::vector<int> tmp = _vector;

	std::sort(tmp.begin(), tmp.end());
	unsigned int min_span = UINT_MAX;

	for (std::vector<int>::iterator it = tmp.begin(); it < tmp.end(); it++)
	{
		if (*(it + 1) && min_span > (unsigned int)(*(it + 1) - *it))
			min_span = (unsigned int)(*(it + 1) - *it);
	}
	
	return min_span;
}

int	Span::longestSpan() const
{
	if (this->_n <= 1)
		throw SpanTooSmallException();
	
	int min = *std::min_element(_vector.begin(), _vector.end());
	int max = *std::max_element(_vector.begin(), _vector.end());

	return max - min;
}

/* Exceptions */

const char* Span::SpanFullException::what() const throw()
{
	return "Span is already full or trying to add more than left capacity.";
}

const char* Span::SpanTooSmallException::what() const throw()
{
	return "Span is empty or contains only one value.";
}