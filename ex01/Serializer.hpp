#ifndef _SERIALIZER_H_
#define _SERIALIZER_H_

#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	public:
	 Serializer();
	 ~Serializer();
	 Serializer(const Serializer &other);
	 Serializer& operator=(const Serializer &other);

	 static uintptr_t serialize(Data* ptr);
	 static Data* deserialize(uintptr_t raw);

	private:
};

#endif // _SERIALIZER_H_
