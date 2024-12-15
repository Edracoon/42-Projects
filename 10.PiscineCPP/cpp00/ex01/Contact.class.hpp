#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <iostream>
# include <string>

class Contact
{
	private:
			std::string	firstname;
			std::string	lastname;
			std::string	nickname;
			std::string	phonenumber;
			std::string	darkestsecret;
	public:
			Contact(void);
			~Contact(void);
			void setFirstname(std::string str);
			std::string getFirstname();

			void setLastname(std::string str);
			std::string getLastname();

			void setNickname(std::string str);
			std::string getNickname();

			void setPhonenumber(std::string str);
			std::string getPhonenumber();

			void setDarkestsecret(std::string str);
			std::string getDarkestsecret();
};

#endif