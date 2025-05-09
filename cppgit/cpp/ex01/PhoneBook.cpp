#include "PhoneBook.hpp"


PhoneBook::PhoneBook() : total_contacts(0), next_index(0) {}

void PhoneBook::addContact(const Contact& new_contact) {
    contacts[next_index] = new_contact;
    next_index = (next_index + 1) % 8;
    if (total_contacts < 8)
        total_contacts++;
}

void PhoneBook::displayContacts() const {
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < total_contacts; i++) {
        std::string first = contacts[i].getFirstName();
        std::string last = contacts[i].getLastName();
        std::string nick = contacts[i].getNickname();

        if (first.length() > 10)
            first = first.substr(0, 9) + ".";
        if (last.length() > 10)
            last = last.substr(0, 9) + ".";
        if (nick.length() > 10)
            nick = nick.substr(0, 9) + ".";

        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << first << "|"
                  << std::setw(10) << last << "|"
                  << std::setw(10) << nick << std::endl;
    }
}

void PhoneBook::displayContactDetails(int index) const {
    if (index < 0 || index >= total_contacts) {
        std::cout << "Índice inválido." << std::endl;
        return;
    }

    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}

int PhoneBook::getTotalContacts() const {
    return total_contacts;
}
