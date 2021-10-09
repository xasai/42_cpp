#ifndef _PHONEBOOK_HPP_
# define _PHONEBOOK_HPP_

#include <string>
#include <iomanip>
#include <iostream>


class Contact {
	public:
		bool		IsActive;
		void		Read();
		void		Print();
		void		PrintRow(int id);
					Contact();
					~Contact();
	private:
		std::string Firstname;	
		std::string Lastname;	
		std::string Nickname;	
		std::string PhoneNumber;
		std::string Secret;	
};

class Phonebook {
	public:
		void	Add();
		void	Search();
	
		Phonebook();
		~Phonebook();

	private:
		Contact Records[8];
		int		ContactIdx;
};

#endif 
