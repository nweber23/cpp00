#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void	add_contact();
		void	search_contact();
	private:
		Contact	contacts[8];
		int		size;
		int		index;
};

#endif