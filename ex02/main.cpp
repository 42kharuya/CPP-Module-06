#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() {

	{
		std::cout << "\n//////////////////////// Normal ////////////////////////" << std::endl;
		Base *baseList[10];

		for (int i = 0; i < 10; ++i)
		{
			baseList[i] = generate();
		}

		for (int i = 0; i < 10; ++i)
		{
			std::cout << "index: " << i << std::endl;
			identify(baseList[i]);
		}

		for (int i = 0; i < 10; ++i)
		{
			std::cout << "-------------------------" << std::endl;
			std::cout << "index: " << i << std::endl;

			std::cout << "pointer: ";
			identify(baseList[i]);

			std::cout << "reference: ";
			identify(*baseList[i]);
		}

		for (int i = 0; i < 10; ++i)
			delete baseList[i];
	}

	{
		std::cout << "\n//////////////////////// Unknown Type ////////////////////////" << std::endl;
		Base base;

		std::cout << "pointer: ";
		identify(&base);

		std::cout << "reference: ";
		identify(base);
	}
}
