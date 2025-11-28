#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() {
	{
		std::cout << "--------------------------- normal ---------------------------" << std::endl;
		Base *test1 = generate();

		identify(test1);
		identify(*test1);
	}
}

// 帰ったらやること：　Base.cpp内の関数を見直す。　テストケースをもっと増やす
