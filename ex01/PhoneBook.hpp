#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iomanip>
# include <sstream>
#include "Contact.hpp"

#define nbContactMax 8
#define lenColonne 10

class PhoneBook {
	
	public:
		PhoneBook();
		~PhoneBook();
		
		void addContact();
		void searchContact() const;
		void afficheContacts() const;
		
	private:
		int _contactCount;
		Contact	_contact[nbContactMax];
};

#endif
