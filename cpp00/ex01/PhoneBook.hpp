#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include"Contact.hpp"

class PhoneBook
{
	public:

	PhoneBook();
	~PhoneBook();
	void		AddContact();
	void		Search();
	void		DisplayC();
	
	private:

		Contact	book[8];
		int	index;
};

#endif