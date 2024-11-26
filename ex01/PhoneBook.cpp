#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook() {
    std::cout << "Phonebook default constructor called" << std::endl;
	this->_contactCount = 0;
}

PhoneBook::~PhoneBook() {
    std::cout << "Phonebook destructor called" << std::endl;
}

void PhoneBook::addContact() {
    Contact newContact;

    newContact.setFirstName();
    newContact.setLastName();
    newContact.setNickName();
    newContact.setPhoneNumber();
    newContact.setTheSecret();
    _contact[_contactCount % nbContactMax] = newContact;
    _contactCount++;
    if (_contactCount >= nbContactMax) {
        _contactCount = nbContactMax;
        std::cout << "Replacing the oldest contact with the new one." << std::endl;
    } else {
        std::cout << "Contact added successfully!" << std::endl;
    }
}

std::string cutLine(std::string str, unsigned int max) {
    if (str.length() > max) {
        str = str.substr(0, max - 1);
        str += '.';
    }
    return str;
}

void PhoneBook::afficheContacts() const {
    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
    
    for (int i = 0; i < _contactCount; i++) {
        std::cout << "|" << std::setw(10) << i + 1;
        std::cout << "|" << std::setw(10) << cutLine(this->_contact[i].getFirstName(), lenColonne);
        std::cout << "|" << std::setw(10) << cutLine(this->_contact[i].getLastName(), lenColonne);
        std::cout << "|" << std::setw(10) << cutLine(this->_contact[i].getNickName(), lenColonne);
        std::cout << "|" << std::endl;
    }
}

void PhoneBook::searchContact() const {
  	std::string input;
	int index;
	PhoneBook::afficheContacts();
    while (true) {
        std::cout << "Enter the index of a contact: ";
        std::cin >> input;
		if (std::cin.eof()) {
            return;
        }
		if (input.length() == 1 && std::isdigit(input[0]))
		{
			index = input[0] - '0';
			if (index >= 0 && index <= _contactCount) {
				break;
			}
			else
				std::cout << "Invalid index. Please enter a number between 0 and " << _contactCount << "." << std::endl;
		}
	}
    std::cout << "First name    : " << _contact[index - 1].getFirstName() << std::endl;
    std::cout << "Last name     : " << _contact[index - 1].getLastName() << std::endl;
    std::cout << "Nick name     : " << _contact[index - 1].getNickName() << std::endl;
    std::cout << "Phone number  : " << _contact[index - 1].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << _contact[index - 1].getTheSecret() << std::endl;
}