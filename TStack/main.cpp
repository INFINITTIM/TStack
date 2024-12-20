#include <iostream>

#include "TStack.h"

int main()
{
	TStack<int> a(10);

	std::cout << a << std::endl;
	a.Push(4);
	std::cout << a << std::endl;
	a.Push(5);
	std::cout << a << std::endl;
	std::cout << a.Top() << std::endl;
	a.Push(6);
	std::cout << a << std::endl;
	a.Pop();
	std::cout << a << std::endl;
	a.Clear();
	std::cout << a << std::endl;
	a.Push(34);
	std::cout << a << std::endl;
}
