#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

bool _validArgs(int ac, char **av){
	if (ac != 4) {
		std::cout << "USAGE: " << av[0] << " filename str1 str2" << std::endl;
		return EXIT_FAILURE;
	}
	return  EXIT_SUCCESS;
}

void replaceAll(std::string &line, std::string s1, std::string s2) {

	std::string::size_type currpos = 0;
	std::string::size_type fpos = line.find(s1, currpos);

	for (;fpos != std::string::npos; fpos = line.find(s1, currpos)) {
		line.erase(fpos, s1.length());
		line.insert(fpos, s2);
		currpos = fpos + s2.length();
	}
}

int main(int ac, char **av) {

	if (_validArgs(ac, av))
		return EXIT_FAILURE;
	
	const char *outFilenameSuffix = ".replace";

	char *inFilename = av[1];

	std::ifstream in(inFilename);
	if (!in.is_open()) {
		std::cout << "error openening " << av[1] << std::endl;
		return EXIT_FAILURE;
	}

	char *outFilename = new char[std::strlen(av[1]) + std::strlen(outFilenameSuffix) + 1];
	std::strcpy(outFilename, av[1]);
	std::strcat(outFilename, outFilenameSuffix);

	std::ofstream  out(outFilename);
	if (!out.is_open()) {
		std::cout << "error openening " << outFilename << std::endl;
		return EXIT_FAILURE;
	}

	delete []outFilename;

	std::string line;
	while (std::getline(in, line)) {
		replaceAll(line, std::string(av[2]), std::string(av[3]));
		out << line  << std::endl;
		std::cout << line  << std::endl;
	}

	std::cout << "Successfully done" << std::endl;
	return EXIT_SUCCESS;
}
