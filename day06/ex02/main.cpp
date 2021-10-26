#include <cmath>
#include <ctime>
#include <typeinfo>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void)
{
	Base *ptr;
	srand((unsigned int)time(NULL));
	switch (rand() % 3)
	{
		case 0:
			ptr = new A();
			std::cout << "new A" << std::endl;
			break;
		case 1:
			ptr = new B();
			std::cout << "new B" << std::endl;
			break;
		case 2:
			ptr = new C();
			std::cout << "new C" << std::endl;
			break;
	}
	return ptr;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "pointer to A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "pointer to B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "pointer to C" << std::endl;
}

void identify(Base& p)
{

	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "reference to A" << std::endl;
		return;
	} catch (std::bad_cast &e) { }

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "reference to C" << std::endl;
		return;
	} catch (std::bad_cast &e) { }

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "reference to B" << std::endl;
		return;
	} catch (std::bad_cast &e) {}

	std::cout << "unknown reference type" << std::endl;
}

int main(void)
{
	Base *ptr = generate();

	identify(ptr);
	identify(*ptr);

	delete ptr;
}
