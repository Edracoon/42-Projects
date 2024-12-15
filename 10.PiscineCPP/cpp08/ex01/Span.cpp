#include "Span.hpp"

Span::Span( unsigned int N )
{
	_N = N;
	_index = 0;
}

Span::Span( std::vector<int>::const_iterator it, std::vector<int>::const_iterator ite )
{
	int	i = 0;
	_index = 0;
	_N = 0;
	for ( ; it != ite ; it++)
	{
		_N++;
		addNumber(i++);
	}
}

Span::~Span( void ) { }

int		Span::shortestSpan()
{
	std::vector<int>::const_iterator	it = container.begin();
	std::vector<int>::const_iterator	ite = container.end();

	int	span = INT_MAX;

	std::sort(container.begin(), container.end());

	if (_N == 0 || _N == 1)
		throw SIE();
	if (_index == 0 || _index == 1)
		throw NENSE();

	++it;
	for ( ; it != ite ; it++ )
	{
		if (*it - (*(it - 1)) <= span)
			span = *it - (*(it - 1));
	}
	return (span);
}

int		Span::longestSpan()
{
	std::vector<int>::const_iterator	it = container.begin();
	std::vector<int>::const_iterator	ite = container.end();

	if (_N == 0 || _N == 1)
		throw SIE();
	if (_index == 0 || _index == 1)
		throw NENSE();

	std::sort(container.begin(), container.end());

	return (*(ite - 1) - *it); // end = apres le dernier
}

void Span::addNumber( int numb )
{
	if (_index >= _N)
		throw CFE();
	container.push_back(numb);
	_index++;
}
