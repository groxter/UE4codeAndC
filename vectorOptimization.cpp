// ConsoleApplication6.cpp : Defines the entry point for the console application.
// How to optimizate std::vector data structure using implicit constructors and some vector methods.

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using String = std::string;
#define LOG(x) std::cout << sizeof(x) << std::endl;

class Vector
{
private:
	float x, y, z;

public:
	Vector(float x1, float y1, float z1) : x(x1), y(y1), z(z1) {}
	Vector(const Vector& vertex) : x(vertex.x), y(vertex.y), z(vertex.z) { std::cout << "Copy" << std::endl; }
};

int main()
{
	std::vector<Vector> vect; // with this optimization, we can save in this case to 6 copies of the same Vector class.

	vect.reserve(3);
	vect.emplace_back(1, 2, 3);
	vect.emplace_back(4, 5, 6);
	vect.emplace_back(7, 8, 9);

	std::cin.get();
}