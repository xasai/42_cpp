#include <string>
#include <iostream>
#include <stdint.h>

typedef struct s_data {
	std::string str;
} Data;

uintptr_t serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}

int main(void) {

	Data d;
	d.str = "yo yo yo";

	uintptr_t uintptr = serialize(&d);
	Data *dataptr = deserialize(uintptr);

	std::cout << "uintptr == dataptr : " << ((Data *)uintptr == dataptr ? "true":"false") << std::endl;
	std::cout << "str: \"" << dataptr->str << "\""<< std::endl;

	return 0;
}
