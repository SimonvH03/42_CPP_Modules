#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>

class	Contact
{
	public:
		Contact();
		~Contact();

		struct	Content
		{
			std::string	firstName;
			std::string	lastName;
			std::string	nickname;
			std::string	phoneNumber;
			std::string	darkestSecret;

			Content();
			~Content();
			Content &operator=(Content const &other);
		};
	
		void			setContent(Content const &content);
		Content	const 	&getContent() const;

	private:
		Content	_content;
};

#endif
