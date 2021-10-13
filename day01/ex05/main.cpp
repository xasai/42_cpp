#include <cstdlib>
#include "Karen.hpp"

int main() {

	Karen k = Karen();

	k.complain("INFO");
	k.complain("DEBUG");
	k.complain("WARNING");
	k.complain("ERROR");

	return EXIT_SUCCESS;
}
