#ifndef _SCALAR_CONVERTER_H_
#define _SCALAR_CONVERTER_H_

#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <cerrno>
#include <cstdlib>

#define SCALAR_TYPE_CHAR 0
#define SCALAR_TYPE_INT 1
#define SCALAR_TYPE_FLOAT 2
#define SCALAR_TYPE_DOUBLE 3

class ScalarConverter
{
	public:
	 static void convert(const std::string &input);

	private:
	 ScalarConverter();
	 ~ScalarConverter();
	 ScalarConverter(const ScalarConverter &other);
	 ScalarConverter& operator=(const ScalarConverter &other);
};

#endif // _SCALAR_CONVERTER_H_
