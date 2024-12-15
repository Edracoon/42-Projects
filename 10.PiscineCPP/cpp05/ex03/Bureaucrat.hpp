#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class	Bureaucrat
{
	private:
			const std::string	_name;
			int					_note;
	public:
			Bureaucrat( void );
			Bureaucrat( const std::string name, int note );
			Bureaucrat( Bureaucrat const & rhs );
			~Bureaucrat( void );

			const std::string	getName( void ) const;
			int					getNote( void ) const;

			void				increaseGrade();
			void				decreaseGrade();

			void				signForm(Form const & rhs, bool success);

			// "Nested Class : Exception for grade too High"
			class GradeTooHighException : public std::exception // J'herite de la class std::exception
			{
				public: // Je redefinie la methode what() selon ce que je veux moi renvoyer dans mon exception
					virtual const char* what() const throw( /* In peut throw quelque chose de specifique mais ici rien */ )	
					{
						return ("Bureaucrat: Grade too High");
					}
			};

			// "Nested Class : Exception for grade too Low"
			class GradeTooLowException : public std::exception
			{
				public:
					virtual const char* what() const throw()	
					{											
						return ("Bureaucrat: Grade too Low");
					}
			};
			Bureaucrat&	operator=(Bureaucrat const & rhs);
};

std::ostream&	operator<<(std::ostream& ofs, Bureaucrat const & rhs);

#endif