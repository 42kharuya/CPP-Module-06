#include "ScalarConverter.hpp"

bool	ftIsprint(int c) {
	return (c >= 32 && c <= 126);
}

bool	ftIsInff(const std::string &input) {
	if (input == "-inff" || input == "+inff" || input == "nanf" || input == "inff")
		return true;
	return false;
}

bool	ftIsInf(const std::string &input) {
	if (input == "-inf" || input == "+inf" || input == "nan" || input == "inf")
		return true;
	return false;
}

static bool isChar(const std::string &input) {
	if (input.length() != 1
		|| std::isdigit(input[0]))
		return false;
	return true;
}

static bool isInt(const std::string &input, bool *intOverflowFlag) {
	char *endptr;
    errno = 0;

    long val = std::strtol(input.c_str(), &endptr, 10);
    if (endptr == input.c_str() || *endptr != '\0')
        return false;
    if (errno == ERANGE
		|| static_cast<int>(val) > std::numeric_limits<int>::max()
		|| static_cast<int>(val) < std::numeric_limits<int>::min())
        *intOverflowFlag = true;
    return true;
}

static bool isFloat(const std::string &input, bool *intOverflowFlag) {
    char *endptr;
    errno = 0;

    float val = std::strtof(input.c_str(), &endptr);
    if (endptr == input.c_str() || *endptr != 'f' || *(endptr + 1) != '\0')
        return false;
    if (errno == ERANGE
		|| static_cast<int>(val) > std::numeric_limits<int>::max()
		|| static_cast<int>(val) < std::numeric_limits<int>::min())
    	*intOverflowFlag = true;
    return true;
}

static bool isDouble(const std::string &input, bool *intOverflowFlag) {
	char *endptr;
    errno = 0;

    double val = std::strtod(input.c_str(), &endptr);
    if (endptr == input.c_str() || *endptr != '\0')
        return false;
    if (errno == ERANGE
		|| static_cast<int>(val) > std::numeric_limits<int>::max()
		|| static_cast<int>(val) < std::numeric_limits<int>::min())
        *intOverflowFlag = true;
    return true;
}

static int getType(const std::string &input, bool *intOverflowFlag) {
	if (isChar(input))
		return SCALAR_TYPE_CHAR;
	else if (isInt(input, intOverflowFlag))
		return SCALAR_TYPE_INT;
	else if (isFloat(input, intOverflowFlag))
		return SCALAR_TYPE_FLOAT;
	else if (isDouble(input, intOverflowFlag))
		return SCALAR_TYPE_DOUBLE;
	else
		return -1;
}

static void outputChar(const char c)
{
	if (ftIsprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void outputInt(const std::string &input, bool intOverflowFlag)
{
	int number = static_cast<int>(std::strtol(input.c_str(), NULL, 10));
	if (intOverflowFlag) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	} else {
		if (!ftIsprint(number))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;
		std::cout << "int: " << number << std::endl;
	}
	if (number >= 1000000 || number <= -1000000) {
		std::cout << "float: " << static_cast<float>(number) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(number) <<std::endl;
	} else {
		std::cout << "float: " << static_cast<float>(number) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(number) << ".0" <<std::endl;
	}
}

static void	outputinff(const std::string &str){
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << str << std::endl;
	std::cout << "double: ";
	for (unsigned int i = 0; i < str.length() - 1; i++) {
		std::cout << str.at(i);
	}
	std::cout << std::endl;
}

static bool isDecimalPartZero(double d) {
	float integral_part;
    double fractional_part = std::modf(d, &integral_part);

    const double EPSILON = 0.00001f;
    if (fractional_part >= EPSILON)
      return false;
    else
      return true;
}

static void outputFloat(const std::string &input, bool intOverflowFlag)
{
	float fnum = std::strtof(input.c_str(), NULL);

	if (ftIsInff(input))
		return outputinff(input);
	if (intOverflowFlag) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "Int: impossible" << std::endl;
	} else {
		int int_num = static_cast<int>(fnum);
		if (!ftIsprint(int_num))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(int_num) << "'" << std::endl;
		std::cout << "Int: " << int_num << std::endl;
	}

	if (fnum >= 1000000.0f || fnum <= -1000000.0f || !isDecimalPartZero(static_cast<double>(fnum))) {
			std::cout << "float: " << fnum << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(fnum) << std::endl;
	} else {
		std::cout << "float: " << fnum << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(fnum) << ".0" << std::endl;
	}
}

static void	outputinf(const std::string &str) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << str << "f" << std::endl;
	std::cout << "double: " << str << std::endl;
}

static void outputDouble(const std::string &input, bool intOverflowFlag)
{
	double dnum = std::strtod(input.c_str(), NULL);

	if (ftIsInf(input))
		return outputinf(input);
	if (intOverflowFlag) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	} else {
		int int_num = static_cast<int>(dnum);
		if (!ftIsprint(int_num))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(int_num) << "'" << std::endl;
		std::cout << "int: " << int_num << std::endl;
	}

	if (dnum >= 1000000.0 || dnum <= -1000000.0 || !isDecimalPartZero(dnum)) {
			std::cout << "float: " << static_cast<float>(dnum) << "f" << std::endl;
			std::cout << "double: " << dnum << std::endl;
	} else {
		std::cout << "float: " << static_cast<float>(dnum) << ".0f" << std::endl;
		std::cout << "double: " << dnum << ".0" << std::endl;
	}
}



void ScalarConverter::convert(const std::string &input) {
	bool intOverflowFlag = false;
	switch (getType(input, &intOverflowFlag))
	{
		case SCALAR_TYPE_CHAR:
			outputChar(input[0]);
			break;
		case SCALAR_TYPE_INT:
			outputInt(input, intOverflowFlag);
			break;
		case SCALAR_TYPE_FLOAT:
			outputFloat(input, intOverflowFlag);
			break;
		case SCALAR_TYPE_DOUBLE:
			outputDouble(input, intOverflowFlag);
			break;
		default:
			std::cerr << "Argument " << input << " is Unknown Type" << std::endl;
			break ;
	}
}

// ------------------------ Orthdox Canonical ------------------------
ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) { static_cast<void>(other); }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other) {
	static_cast<void>(other);
    return *this;
}

