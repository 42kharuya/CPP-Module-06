#ifndef _SCALAR_CONVERTER_H_
#define _SCALAR_CONVERTER_H_

class ScalarConverter
{
	public:

	private:
	 ScalarConverter();
	 ~ScalarConverter();
	 ScalarConverter(const ScalarConverter &other);
	 ScalarConverter& operator=(const ScalarConverter &other);
};

std::ostream &operator<<(std::ostream &os, ScalarConverter const &f);

#endif // _SCALAR_CONVERTER_H_