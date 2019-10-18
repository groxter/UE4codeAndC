// MemoryManagement.cpp : Defines the entry point for the console application.

#include <iostream>
#include "stdafx.h"

class Test
{
private:
	int num;
	float *ptr;
public:
	Test()
	{
		std::cout << "Enter total number of Darklings: ";
		std::cin >> num;

		ptr = new float[num];

		std::cout << "Enter stat level of darklings." << std::endl;
		for (int i = 0; i < num; ++i)
		{
			std::cout << "Darkling lvl: " << i + 1 << ": ";
			std::cin >> *(ptr + i);
		}
	}

	~Test() {
		delete[] ptr;
	}
	void Display() {
		std::cout << "\nDisplaying level of darkling." << std::endl;
		for (int i = 0; i < num; ++i) {
			std::cout << "Darkling: " << i + 1 << " :" << *(ptr + i) << std::endl;
		}
	}

};
int main() {
	Test s;
	s.Display();
	std::cin.get();
}

