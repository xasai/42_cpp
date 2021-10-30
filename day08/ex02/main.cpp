#include <iostream>
#include "mutantstack.hpp"

int main() {
	std::cout << "--------------------INT------------------------" << std::endl << std::endl;
	MutantStack<int> mstack;

	mstack.push(111);
	mstack.push(999);

	std::cout << "Size: " << mstack.size() << std::endl;
	std::cout << "Begin: " << *mstack.begin() << std::endl;
	std::cout << "Top: " << mstack.top() << std::endl;
	std::cout << "End: " << *mstack.end() << std::endl; 

	//////////////////////
	//PUSHING
	std::cout << std::endl << "Pushing integers from 1 to 10... " << std::endl;
	for (int i = 0; i <= 10; i++) {
		mstack.push(i);
	}

	std::cout << std::endl << "------Current values" << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl;
	std::cout << "Begin: " << *mstack.begin() << std::endl;
	std::cout << "Top: " << mstack.top() << std::endl;
	std::cout << "End: " << *mstack.end() << std::endl; 


	MutantStack<int>::iterator it = mstack.begin();
	++it;
	--it;

	//ITERATING
	
	std::cout << std::endl << "Iterating:" << std::endl;
	for (it = mstack.begin(); it != mstack.end(); ++it) {
		std::cout << " " <<  *it;
	}


	std::cout << std::endl << "--------------------CHAR------------------------" << std::endl << std::endl;

	MutantStack<char> chmstack;

	chmstack.push('$');
	chmstack.push('!');

	std::cout << "Size: " << chmstack.size() << std::endl;
	std::cout << "Begin: " << *chmstack.begin() << std::endl;
	std::cout << "Top: " << chmstack.top() << std::endl;
	std::cout << "End: " << *chmstack.end() << std::endl;

	//////////////////////
	//PUSHING
	std::cout << std::endl << "Pushing alphabet... " << std::endl;
	for (int i = 0; i < 26; i++) {
		chmstack.push('A' + i);
	}

	std::cout << std::endl << "------Current values" << std::endl;
	std::cout << "Size: " << chmstack.size() << std::endl;
	std::cout << "Begin: " << *chmstack.begin() << std::endl;
	std::cout << "Top: " << chmstack.top() << std::endl;
	std::cout << "End: " << *chmstack.end() << std::endl;

	MutantStack<char>::iterator cit = chmstack.begin();
	++cit;
	--cit;

	//ITERATING
	
	std::cout << std::endl << "Iterating:" << std::endl;
	for (cit = chmstack.begin(); cit != chmstack.end(); ++cit) {
		std::cout << " " <<  *cit;
	}
	std::cout << std::endl;
}
