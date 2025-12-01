#include "Serializer.hpp"

int main()
{
	{
		std::cout << "---------------------------- normal ----------------------------" << std::endl;
		Data *data1 = new Data("data1");

		std::cout << std::endl;
		uintptr_t data1_ptr = Serializer::serialize(data1);
		std::cout << "uintptr_t: " << data1_ptr << std::endl;

		std::cout << std::endl;
		Data *data1_return = Serializer::deserialize(data1_ptr);

		if (data1_return == data1)
			std::cout << "Same ptr." << std::endl;
		else
			std::cout << "Different ptr." << std::endl;

		delete data1;
	}
}
