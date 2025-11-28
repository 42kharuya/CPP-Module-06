#ifndef _SERIALIZER_H_
#define _SERIALIZER_H_

#include <iostream>
#include <string>

class Serializer
{
	public:
	 static uintptr_t serialize(Data* ptr);

	private:
	 Serializer();
	 ~Serializer();
	 Serializer(const Serializer &other);
	 Serializer& operator=(const Serializer &other);
};

#endif // _SERIALIZER_H_
