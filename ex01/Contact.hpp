#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {

	public:
		Contact();
		~Contact();

		std::string getNickName() const;
		std::string getPhoneNumber() const;
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getTheSecret() const;

		void setNickName();
		void setPhoneNumber();
		void setFirstName();
		void setLastName();
		void setTheSecret();

		bool isalpha(std::string str);
		bool isdigit(std::string str);

	private:
		int _id;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _firstName;
		std::string _lastName;
		std::string _theSecret;
};

#endif