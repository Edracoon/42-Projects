#include "A.hpp"

A::A( void )
{ }

A::A( A const & rhs )
{ *this = rhs; }

A::~A( void )
{ }

A&	A::operator=( A const & rhs )
{ (void)rhs; return (*this); }