#ifndef _BASE_H_
#define _BASE_H_

#include <ctime>
#include <iostream>
#include <cstdlib>

class A;
class B;
class C;

class Base {
    public:
        virtual ~Base();
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif // _BASE_H_
