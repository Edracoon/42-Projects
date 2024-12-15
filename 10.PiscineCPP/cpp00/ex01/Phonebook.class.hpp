#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP
# include <iostream>
# include "Contact.class.hpp"

class Phonebook
{
	private:
			int		i;
			Contact	tab[8];
	public:
			Phonebook(void);
			~Phonebook(void);
			void 	addcontact();
			void 	search();
			void 	exit();
			void	show_info(int n);
};

#endif