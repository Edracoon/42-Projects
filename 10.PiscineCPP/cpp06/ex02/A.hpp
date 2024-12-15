#ifndef A_HPP
# define A_HPP

#include <iostream>
# include "Base.hpp"

class A : public Base
{
	public:
		A( void );
		A( A const & rhs );
		virtual ~A( void );

		A& operator=( A const & rhs );
};

#endif