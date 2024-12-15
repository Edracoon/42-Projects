#include "Fixed.hpp"

int	main( void )
{
	Fixed a;
	Fixed b(300);
	Fixed c(42.42f);
	Fixed d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << "======= arithmetic operator ========" << std::endl;
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	std::cout << "b * d = " << b << " * " << d << " = " << (b * d) << std::endl;
	std::cout << "a / b = " << a << " / " << b << " = " << a / b << std::endl;

	std::cout << "======= Diff operators ========" << std::endl;
	std::cout << "a > b = " << (a > b) << std::endl;
	std::cout << "a < b = " << (a < b) << std::endl;
	std::cout << "a >= b = " << (a >= b) << std::endl;
	// a = b;
	std::cout << "a <= b = " << (a <= b) << std::endl;
	std::cout << "a != b = " << (a != b) << std::endl;
	std::cout << "a == b = " << (a == b) << std::endl;

	std::cout << "======= pre/post increment =======" << std::endl;
	Fixed y;
	Fixed const z(Fixed(5.05f) * Fixed(2));

	std::cout << "y \t" << y << std::endl;
	std::cout << "++y \t" << ++y << std::endl;
	std::cout << "y \t" << y << std::endl;
	std::cout << "y++ \t" << y++ << std::endl;
	std::cout << "y \t" << y << std::endl;
	std::cout << "z \t" << z << std::endl;
	std::cout << "max(" << y << ", " << z << ") = " << Fixed::max(y, z) << std::endl;
	std::cout << "min(" << y << ", " << z << ") = " << Fixed::min(y, z) << std::endl;
	
	std::cout << "======= pre/post decrement =======" << std::endl;
	Fixed w;
	Fixed const x(Fixed(5.05f) * Fixed(2));

	std::cout << "w \t" << w << std::endl;
	std::cout << "++w \t" << --w << std::endl;
	std::cout << "w \t" << w << std::endl;
	std::cout << "w++ \t" << w-- << std::endl;
	std::cout << "w \t" << w << std::endl;
	std::cout << "x \t" << x << std::endl;
	std::cout << "max(" << w << ", " << x << ") = " << Fixed::max(w, x) << std::endl;
	std::cout << "min(" << w << ", " << x << ") = " << Fixed::min(w, x) << std::endl;
	return (0);
}
