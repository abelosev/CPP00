#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

Contact::Contact() {
	std::cout << "Contact default constructor called" << std::endl;
}

Contact::~Contact() {
	std::cout << "Contact destructor called" << std::endl;
}

// getters

std::string Contact::getNickName() const{
	return(this->_nickName);
}

std::string Contact::getPhoneNumber() const{
	return(this->_phoneNumber);
}

std::string Contact::getFirstName() const{
	return(this->_firstName);
}

std::string Contact::getLastName() const{
	return(this->_lastName);
}

std::string Contact::getTheSecret() const{
	return(this->_theSecret);
}

// setters

bool Contact::isalpha(std::string str) {
    int i = 0;
    while(i < str.length())
	{
        if(!std::isalpha(str[i]))
            return false;
        i++;
    }
    return true;
}

bool Contact::isdigit(std::string str)
{
	int i = 0;
	while(i < str.length())
	{
		if(!std::isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

void Contact::setNickName() {
	while(1)
	{
		std::cout << "Enter a NickName : " << std::endl;
		std::cin >> _nickName;
		int len = _nickName.length();
		if(len < 2)
		{
			std::cout << std::endl << "More than one character please" << std::endl;
			continue;
		}
		else if(Contact::isalpha(_nickName) == false)
		{
			std::cout << std::endl << "Only letters please" << std::endl;
			continue;
		}
		else
			break ;
	}
}

void Contact::setPhoneNumber() {

	while(1)
	{
		std::cout << "Enter a Phone Number : " << std::endl;
		std::cin >> _phoneNumber;
		int len = _phoneNumber.length();
		if(Contact::isdigit(_phoneNumber) == false)
		{
			std::cout << std::endl << "Only numbers please" << std::endl;
			continue;
		}
		else
			break ;
	}
}

void Contact::setFirstName() {
	while(1)
	{
		std::cout << "Enter a First Name : " << std::endl;
		std::cin >> _firstName;
		int len = _firstName.length();
		if(len < 2)
		{
			std::cout << std::endl << "More than one character please" << std::endl;
			continue;
		}
		else if(Contact::isalpha(_firstName) == false)
		{
			std::cout << std::endl << "Only letters please" << std::endl;
			continue;
		}
		else
			break ;
	}
}

void Contact::setLastName() {
	while(1)
	{
		std::cout << "Enter a Last Name : " << std::endl;
		std::cin >> _lastName;
		int len = _lastName.length();
		if(len < 2)
		{
			std::cout << std::endl << "More than one character please" << std::endl;
			continue;
		}
		else if(Contact::isalpha(_lastName) == false)
		{
			std::cout << std::endl << "Only letters please" << std::endl;
			continue;
		}
		else
			break ;
	}
}

void Contact::setTheSecret() {
    std::cin.ignore();
    std::cout << std::endl << "Now tell me your darkest secret: " << std::endl;
    std::getline(std::cin, _theSecret);
    if (std::cin.eof()) {
        return;
    }
    if (_theSecret.empty()) {
        setTheSecret();
    }
}