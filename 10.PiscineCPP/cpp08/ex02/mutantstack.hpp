#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template< typename T>
class Mutantstack : public std::stack<T>
{
	public:
			Mutantstack( void ) { std::stack<T>(); }
			Mutantstack( Mutantstack const & rhs ) { (std::stack<T>(rhs)); }

			typedef typename std::deque<T>::iterator iterator;

			iterator	begin( void ) { return (this->c.begin() ); }
			iterator	end( void ) { return (this->c.end() ); }

			Mutantstack&	operator=( Mutantstack const & rhs )
			{ this->c = rhs.c; return (*this); }
};

#endif
