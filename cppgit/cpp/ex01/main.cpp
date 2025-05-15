#include "PhoneBook.hpp"
#include <iostream>
#include <limits>
#include <cctype>


bool getValidatedInput(const std::string& prompt, std::string& field, const std::string& fieldName) {
    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, field)) {
            if (std::cin.eof()) {
                std::cout << "\nInput terminated by user (EOF).\n";
                return false;
            } else {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Input error. Try again.\n";
                continue;
            }
        }

        if (field.empty()) {
            std::cout << "Error: " << fieldName << " cannot be empty.\n";
        } else {
            return true;
        }
    }
}



void handleAdd(PhoneBook& phonebook) {
    std::string first, last, nick, phone, secret;

    if (!getValidatedInput("First Name: ", first, "First Name")) return;
    if (!getValidatedInput("Last Name: ", last, "Last Name")) return;
    if (!getValidatedInput("Nickname: ", nick, "Nickname")) return;

    while (true) {
    if (!getValidatedInput("Phone Number: ", phone, "Phone Number")) return;

    bool is_valid = true;
    for (size_t i = 0; i < phone.length(); ++i) {
        if (!isdigit(phone[i])) {
            is_valid = false;
            break;
        }
    }

    if (!is_valid) {
        std::cout << "Error: Phone number must contain digits only.\n";
    } else {
        break;
    }
}

    if (!getValidatedInput("Darkest Secret: ", secret, "Darkest Secret")) return;

    Contact new_contact;
    new_contact.setContactInfo(first, last, nick, phone, secret);
    phonebook.addContact(new_contact);
}

void handleSearch(const PhoneBook& phonebook) {
    if (phonebook.getTotalContacts() == 0) {
        std::cout << "No contacts stored.\n";
        return;
    }

    phonebook.displayContacts();
    std::cout << "Enter the index of the contact: ";
    std::string input;
    std::getline(std::cin, input);

    if (input.length() != 1 || !isdigit(input[0])) {
        std::cout << "Error: invalid index.\n";
        return;
    }

    int index = input[0] - '0';
    phonebook.displayContactDetails(index);
}

int main() {
    PhoneBook phonebook;
    std::string command;

    while (true) {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, command)) {
            std::cout << "\nEOF detectado. Saliendo del programa.\n";
            break;
        }

        if (command.empty())
            continue;

        if (command == "EXIT") {
            break;
        } else if (command == "ADD") {
            handleAdd(phonebook);
        } else if (command == "SEARCH") {
            handleSearch(phonebook);
        } else {
            std::cout << "Unrecognized command.\n";
        }
    }

    return 0;
}
