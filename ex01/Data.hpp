#ifndef _DATA_H_
#define _DATA_H_

#include <iostream>
#include <string>

class Data
{
	public:
	 Data();
	 Data(const std::string &name);
	 ~Data();
	 Data(const Data &other);
	 Data& operator=(const Data &other);

	private:
	 const std::string _name;
};

#endif // _DATA_H_
