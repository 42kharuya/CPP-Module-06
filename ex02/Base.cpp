#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base* generate(void) {
	static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(0));
        seeded = true;
    }
    switch (std::rand() % 3) {
    	case 0:
        	return new A();
    	case 1:
        	return new B();
    	case 2:
        	return new C();
		default:
			std::cout << "rand error" << std::endl;
			return NULL;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "This is 'A'" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "This is 'B'" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "This is 'C'" << std::endl;
    else
        std::cout << "Unknown Type" << std::endl;
}

void identify(Base &p) {
    try {
        A& a = dynamic_cast<A&>(p);
        std::cout << "This is 'A'" << std::endl;
        (void)a;
    } catch (const std::exception &e) {}

    try {
        B& b = dynamic_cast<B&>(p);
        std::cout << "This is 'B'" << std::endl;
        (void)b;
    } catch (const std::exception &e) {}

    try {
        C& c = dynamic_cast<C&>(p);
        std::cout << "This is 'C'" << std::endl;
        (void)c;
    } catch (const std::exception &e) {}
}
