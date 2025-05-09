#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "PhoneBook.hpp"
#include "Contact.hpp"

#include <iostream>
#include <iomanip>

class PhoneBook {
private:
    Contact contacts[8];
    int total_contacts;
    int next_index;

public:
    PhoneBook();
    void addContact(const Contact& new_contact);
    void displayContacts() const;
    void displayContactDetails(int index) const;
    int getTotalContacts() const;
};

#endif
