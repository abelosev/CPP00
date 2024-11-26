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
    int			i;
    std::string input;
	PhoneBook::afficheContacts();
    while (true) {
        std::cout << "Enter the index of a contact: ";
        std::getline(std::cin, input);
        if (std::cin.eof()) {
            return;
        }
        std::stringstream ss(input);
        if (ss >> i && ss.eof() && i > 0 && i <= _contactCount) {
        	break ;
        }
		std::cout << "Invalid index. Please try again." << std::endl;
    }
    std::cout << "First name    : " << _contact[i - 1].getFirstName() << std::endl;
    std::cout << "Last name     : " << _contact[i - 1].getLastName() << std::endl;
    std::cout << "Nick name     : " << _contact[i - 1].getNickName() << std::endl;
    std::cout << "Phone number  : " << _contact[i - 1].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << _contact[i - 1].getTheSecret() << std::endl;
}