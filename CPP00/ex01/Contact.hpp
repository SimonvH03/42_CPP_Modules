#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>

class	Contact
{
	public:
		Contact();
		~Contact();
		void		display_contact(void);
		void		setFirstName(std::string _firstName);
		void		setLastName(std::string _lastName);
		void		setNickname(std::string nickname);
		void		setPhoneNumber(std::string phone_number);
		void		setDarkestSecret(std::string darkest_secret);
		std::string	getFirstName(void);
		std::string	getLastName(void);
		std::string	getNickName(void);
		std::string	getPhoneNumber(void);
		std::string	getDarkestSecret(void);
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
};

#endif