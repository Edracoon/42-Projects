#include "B.hpp"

B::B( void )
{ }

B::B( B const & rhs )
{ *this = rhs; }

B::~B( void )
{ }

B&	B::operator=( B const & rhs )
{ (void)rhs; return (*this); }