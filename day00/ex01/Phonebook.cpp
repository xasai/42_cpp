#include "Phonebook.hpp"
#include <string>
#include <limits>
#include <stdlib.h>


///////////////////////////////////////////
// Phonebook
///////////////////////////////////////////
Phonebook::Phonebook() {
	ContactIdx = 0;
}
Phonebook::~Phonebook() {
}

void Phonebook::Add() {
	Records[ContactIdx].Read();
	ContactIdx++;
	if (ContactIdx == 8)
		ContactIdx = 0;
}

void Phonebook::Search() {
	std::cout << "+-----------------------------------------------------------------+" << std::endl;
	std::cout << "|     Index| Firstanme|  Lastname|  Nickname|Phone num.|    Secret|" << std::endl;
	for (int i = 0; i < 8; i++) {
		if (this->Records[i].IsActive == false)
			break;
		std::cout << "|-----------------------------------------------------------------|" << std::endl;
		this->Records[i].PrintRow(i);
	}
	std::cout << "+-----------------------------------------------------------------+" << std::endl;

	int id;
	std::cout << std::endl << "Choose id: "; 
	std::cin >> id;
	while (id < 1 || id > 8) {
		std::cin.clear();
		std::cout << "id may be only from 1 to 8!" << std::endl;
		std::cout << "Choose id: "; 
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> id;
	}
	if (this->Records[id - 1].IsActive)
		this->Records[id - 1].Print();
	else 
		std::cout << "There is no contact with such id" << std::endl;
}

///////////////////////////////////////////
// Contact 
///////////////////////////////////////////
Contact::Contact() {
	IsActive = false;
}

Contact::~Contact() {

}

static bool is_digits(const std::string &str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}

void Contact::Read() {
	std::cout << "Enter firstname: ";
	std::cin >> this->Firstname;
	std::cout << "Enter lastname: " ;
	std::cin >> this->Lastname;
	std::cout << "Enter nickname: " ;
	std::cin >> this->Nickname;
	std::cout << "Enter phone number: ";
	std::cin >> this->PhoneNumber;	
	while (!is_digits(this->PhoneNumber)) {
		std::cout << "Phone number may contain only positive number: ";
		std::cin >> this->PhoneNumber;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Enter the darkest secret: ";
	std::getline(std::cin, this->Secret);
	std::cout << "Contact successfully created!" << std::endl;
	this->IsActive = true;
}

static std::string _fmt(std::string s)
{
	if (s.size() > 10) {
		s = s.insert(9, ".");
		s = s.substr(0, 10);
	}
	else
		while (s.length() < 10)
			s = s.insert(0, " ");
	return s;
}

void Contact::PrintRow(int id) {
	std::cout << "|         " << id + 1;
	std::cout << "|" << _fmt(this->Firstname) << "|" << _fmt(this->Lastname);
	std::cout << "|" << _fmt(this->Nickname) << "|" << _fmt(this->PhoneNumber);
	std::cout << "|" << _fmt(this->Secret) << "|" << std::endl;
}


void Contact::Print() {
	std::cout << "Firstname: " << this->Firstname << std::endl;
	std::cout << "Lastname: " << this->Lastname << std::endl;
	std::cout << "Nickname: " << this->Nickname << std::endl;
	std::cout << "Phone: " << this->PhoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->Secret << std::endl;
	std::cout << std::endl;
}
