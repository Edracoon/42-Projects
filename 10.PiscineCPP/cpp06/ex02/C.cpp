#include "C.hpp"

C::C( void )
{ }

C::C( C const & rhs )
{ *this = rhs; }

C::~C( void )
{ }

C&	C::operator=( C const & rhs )
{ (void)rhs; return (*this); }