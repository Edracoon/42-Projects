#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <limits>
# include <vector>

class Span
{
	private:
			std::vector<int>		container;
			unsigned int		_N;
			unsigned int		_index;
			
	public:
			Span( void ) { _N = 0; _index = 0; }		// default
			Span( unsigned int N );						// param
			Span( Span const & rhs ) { *this = rhs; };	// copy
			Span( std::vector<int>::const_iterator it, std::vector<int>::const_iterator ite);
			~Span( void );

			class CFE : public std::exception
			{
				public:
						virtual const char* what() const throw ()
						{ return ("Exception: Container Full"); }
			};

			class NENSE : public std::exception
			{
				public:
						virtual const char* what() const throw ()
						{ return ("Exception: Span: Not Enough Number Stored"); }
			};

			class SIE : public std::exception
			{
				public:
						virtual const char* what() const throw ()
						{ return ("Exception: Span: Size Invalid"); }
			};

			void	addNumber( int numb );
			int		shortestSpan( void );
			int		longestSpan( void );

			Span&	operator=(Span const & rhs)
			{
				this->container = rhs.container;
				this->_index = rhs._index;
				this->_N = rhs._N;
				return (*this);
			}
};

#endif