#include "Data.hpp"

Data::Data() : _name("") {
	std::cout << "Data default constructor called." << std::endl;
}

Data::Data(const std::string &name) : _name(name) {
	std::cout << "Data default constructor called." << std::endl;
}

Data::~Data() {
	std::cout << "Data \"" << this->_name << "\" destructor called." << std::endl;
}

Data::Data(const Data &other) : _name(other._name) {
	std::cout << "Data \"" << this->_name << "\" Copy constructor called." << std::endl;
}

Data& Data::operator=(const Data &other) {
	std::cout << "Data Copy assignment operator called." << std::endl;
	static_cast<void>(other);
    return *this;
}
