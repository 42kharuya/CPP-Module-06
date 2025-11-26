// #include "ScalarConverter.hpp"

// static bool isChar(std::string &input) {
// 	if (input.length() != 1
// 		|| std::isdigit(input[0]))
// 		return false;
// 	return true;
// }

// static bool isInt(std::string &input, bool *intOverflowFlag) {
// 	unsigned long res = 0;
// 	if (input == "-2147483648")
// 		return true;
// 	for (size_t i = (input[0] == '-' ? 1 : 0); i < input.length(); i++) {
// 		if (!isdigit(input[i]))
// 			return false;
// 		res = res * 10 + input[i] - '0';
// 		if (res > std::numeric_limits<int>::max())
// 			*intOverflowFlag = true;
// 	}
// 	return true;
// }

// static bool isFloat(std::string &input) {
// 	bool	dot = false;

// 	if (ft_isinff(input))
// 		return true;
// 	if (input[input.length() - 1] != 'f' || input[input.length() - 2] == '.')
// 		return false;
// 	for (size_t i = (input[0] == '-' ? 1 : 0); i < input.length() - 1; i++) {
// 		if (input[i] == '.' && dot)
// 			return false;
// 		else if (input[i] == '.') {
// 			dot = true;
// 			continue ;
// 		}
// 		if (!isdigit(input[i]))
// 			return false;
// 	}
// 	return true;
// }

// static bool isDouble(std::string &input) {
// 	bool	dot = false;

// 	if (ft_isinf(input))
// 		return true;
// 	if (input[input.length() - 1] == '.')
// 		return false;
// 	for (size_t i = (input[0] == '-' ? 1 : 0); i < input.length(); i++) {
// 		if (input[i] == '.' && dot)
// 			return false;
// 		else if (input[i] == '.') {
// 			dot = true;
// 			continue ;
// 		}
// 		if (!isdigit(input[i]))
// 			return false;
// 	}
// 	return true;
// }

// static int getType(std::string &input, bool *intOverflowFlag) {
// 	if (isChar(input))
// 		return SCALAR_TYPE_CHAR;
// 	else if (isInt(input, intOverflowFlag))
// 		return SCALAR_TYPE_INT;
// 	else if (isFloat(input))
// 		return SCALAR_TYPE_FLOAT;
// 	else if (isDouble(input))
// 		return SCALAR_TYPE_DOUBLE;
// 	else
// 		return -1;
// }

// static void outputChar(char c)
// {
// 	if (ftIsprint(c))
// 		std::cout << "char: '" << c << "'" << std::endl;
// 	else
// 		std::cout << "char: Non displayable" << std::endl;
// 	std::cout << "int: " << static_cast<int>(c) << std::endl;
// 	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
// 	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
// }

// static void outputInt(std::string &input, bool intOverflowFlag)
// {
// 	int number = stoi(input);
// 	if (overflowflag) {
// 		std::cout << "char: impossible" << std::endl;
// 		std::cout << "int: impossible" << std::endl;
// 	} else {
// 		if (!isprint(static_cast<char>(number)))
// 			std::cout << "char: Non displayable" << std::endl;
// 		else
// 			std::cout << "char: '" << static_cast<char>(number) << "'" << std::endl;
// 		std::cout << "int: " << num << std::endl;
// 	}
// 	float	fnum = stof(num);
// 	double	dnum = stod(num);
// 	std::cout << "float: " << fnum << "f" << std::endl;
// 	std::cout << "double: " << dnum <<std::endl;
// }

// static void outputFloat(std::string &input)
// {

// }

// static void outputDouble(std::string &input)
// {

// }


// void ScalarConverter::convert(std::string &input) {
// 	bool intOverflowFlag = false;
// 	switch (getType(input, &intOverflowFlag))
// 	{
// 		case SCALAR_TYPE_CHAR:
// 			outputChar(input[0]);
// 			break;
// 		case SCALAR_TYPE_INT;
// 			outputInt(input, intOverflowFlag);
// 			break;
// 		case SCALAR_TYPE_FLOAT;
// 			outputFloat(input, intOverflowFlag);
// 			break;
// 		case SCALAR_TYPE_DOUBLE;
// 			outputDouble(input, intOverflowFlag);
// 			break;
// 		default:
// 			std::cerr << "Argument " << input << " is Unknown Type" << std::endl;
// 			break ;
// 	}
// }

// // ------------------------ Orthdox Canonical ------------------------
// ScalarConverter::ScalarConverter() {}

// ScalarConverter::~ScalarConverter() {}

// ScalarConverter::ScalarConverter(const ScalarConverter &other) { static_cast<void>(other); }

// ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other) {
// 	static_cast<void>(other);
//     return *this;
// }


#include "ScalarConverter.hpp"

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
    if (endptr == input.c_str() || (*endptr != 'f' && *(endptr + 1) != '\0'))
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

bool	ftIsprint(char c) {
	return (c >= 32 && c <= 126);
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

bool	ft_isinff(const std::string &input) {
	if (input == "-inff" || input == "+inff" || input == "nanf" || input == "inff")
		return true;
	return false;
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

static void outputFloat(const std::string &input, bool intOverflowFlag)
{
	if (ft_isinff(input))
		return outputinff(input);
	if (intOverflowFlag) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "Int: impossible" << std::endl;
	} else {
		int int_num = static_cast<int>(std::strtol(input.c_str(), NULL, 10));
		if (!ftIsprint(int_num))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(int_num) << "'" << std::endl;
		std::cout << "Int: " << int_num << std::endl;
	}
	float fnum = std::strtof(input.c_str(), NULL);
	double dnum = std::strtod(input.c_str(), NULL);
	if (fnum >= 1000000.0f || fnum <= -1000000.0f)
			std::cout << "float: " << fnum << "f" << std::endl;
	else
		std::cout << "float: " << fnum << ".0f" << std::endl;
	if (dnum >= 1000000.0 || dnum <= -1000000.0)
			std::cout << "float: " << dnum << std::endl;
	else
		std::cout << "float: " << dnum << ".0" << std::endl;
}


bool	ft_isinf(const std::string &input) {
	if (input == "-inf" || input == "+inf" || input == "nan" || input == "inf")
		return true;
	return false;
}

static void	outputinf(const std::string &str) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << str << "f" << std::endl;
	std::cout << "double: " << str << std::endl;
}

static void outputDouble(const std::string &input, bool intOverflowFlag)
{
	if (ft_isinf(input))
		return outputinf(input);
	if (intOverflowFlag) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	} else {
		int int_num = static_cast<int>(std::strtol(input.c_str(), NULL, 10));
		if (!ftIsprint(int_num))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(int_num) << "'" << std::endl;
		std::cout << "int: " << int_num << std::endl;
	}
	float fnum = std::strtof(input.c_str(), NULL);
	double dnum = std::strtod(input.c_str(), NULL);
	if (fnum >= 1000000.0f || fnum <= -1000000.0f)
			std::cout << "float: " << fnum << "f" << std::endl;
	else
		std::cout << "float: " << fnum << ".0f" << std::endl;
	if (dnum >= 1000000.0 || dnum <= -1000000.0)
			std::cout << "float: " << dnum << std::endl;
	else
		std::cout << "float: " << dnum << ".0" << std::endl;
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

// outputDouble()とoutputFloat()にて10000.1や10000.1fのときと10000.0、10000.0fのときで,0の場合は.0が省略されてしまうので、これを修正する。(Gemini参照)
