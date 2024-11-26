#include "PhoneBook.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 1) {
        std::cerr << "No args please" << std::endl;
        return EXIT_FAILURE;
    }

    PhoneBook phonebook;

    while (std::cin) {
        std::string cmd;
        std::cout << "Enter ADD or SEARCH or EXIT (in uppercase): " << std::endl;
        std::cin >> cmd;
        
        if (!std::cin) {
            std::cerr << "Error reading cmd!" << std::endl;
            break;
        }

        if (cmd == "ADD") {
            phonebook.addContact();
        } else if (cmd == "SEARCH") {
            phonebook.searchContact();
        } else if (cmd == "EXIT") {
            return 0;
        }
    }
    if (std::cin) {
        std::cout << "Exiting program." << std::endl;
    } else {
        std::cout << "Error occurred during input. Exiting program." << std::endl;
    }
    return 0;
}
