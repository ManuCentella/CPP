#include "Contact.hpp"

Contact::Contact()
:first_name(""), last_name(""), nickname("") , phone_number(""), darkest_secret(""){}

void Contact::setContactInfo(const std::string &first, const std::string &last,
                             const std::string &nick, const std::string &phone, 
                             const std::string &secret) {

    first_name = first;
    last_name = last;
    nickname = nick;
    phone_number = phone;
    darkest_secret = secret;
}
    
std::string Contact::getFirstName() const {
    return first_name;
}

std::string Contact::getLastName() const {
    return last_name;
}

std::string Contact::getNickname() const {
    return nickname;
}

std::string Contact::getPhoneNumber() const {
    return phone_number;
}

std::string Contact::getDarkestSecret() const {
    return darkest_secret;
}
