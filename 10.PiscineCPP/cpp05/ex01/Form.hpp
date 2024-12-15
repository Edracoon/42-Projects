#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Bureaucrat;

class Form
{
	private:
			const std::string	_name;
			bool				_signed;
			const int			_gradeSign;
			const int			_gradeExec;
	public:
			Form( void );
			Form( std::string name, const int gradeSign, const int gradeExec);
			Form( Form const & rhs );
			~Form( void );
			Form&	operator=( Form const & rhs );

			std::string	getName() const;
			bool		getSigned() const;
			int			getGradeSign() const;
			int			getGradeExec() const;

			void		beSigned(Bureaucrat & rhs);

			class GradeTooHighException : public std::exception
			{
				public:
						virtual const char* what() const throw ()
						{
							return ("Form: Grade too High");
						}
			};
			class GradeTooLowException : public std::exception
			{
				public:
						virtual const char* what() const throw ()
						{
							return ("Forn: Grade too Low");
						}
			};
};

std::ostream&	operator<<(std::ostream& ofs, Form const & rhs);

#endif

