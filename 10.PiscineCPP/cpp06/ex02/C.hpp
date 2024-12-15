#ifndef C_HPP
# define C_HPP

#include <iostream>
# include "Base.hpp"

class C : public Base
{
	public:
		C( void );
		C( C const & rhs );
		virtual ~C( void );

		C& operator=( C const & rhs );
};

#endif