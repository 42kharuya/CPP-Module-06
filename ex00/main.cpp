#include "ScalarConverter.hpp"
#include <cstdlib>

int main(int ac, char *av[]) {
	if (ac != 2) {
		std::cerr << "INPUT ERROR: ./ex00 [string to convert]" << std::endl;
		return EXIT_FAILURE;
	}
	ScalarConverter::convert(std::string(av[1]));
	return EXIT_SUCCESS;
}

// ex01ではエラーメッセージをex01に置き換える。
