// ConstructorAndRValueTest.cpp : Defines the entry point for the application.
//

#include "ConstructorAndRValueTest.h"
#include <iostream>
#include <memory>
using namespace std;

class ObjectUnderTest
{
public:
	ObjectUnderTest()
	{
		std::cout << "Default constructor\n";
	}

	ObjectUnderTest(const ObjectUnderTest &other)
	{
		std::cout << "Copy constructor\n";
	}

	ObjectUnderTest(ObjectUnderTest &&other) noexcept
	{
		std::cout << "Move constructor\n";
	}

	ObjectUnderTest &operator=(const ObjectUnderTest &other)
	{
		std::cout << "Copy assignment operator\n";
		return *this;
	}

	ObjectUnderTest &operator=(ObjectUnderTest &&other) noexcept
	{
		std::cout << "Copy assignment operator\n";
		return *this;
	}
	~ObjectUnderTest()
	{
		std::cout << "Destructor\n";
	}
};

ostream &operator<<(ostream &os, const ObjectUnderTest &obj)
{
	return os << "Obj\n";
}


ObjectUnderTest SomeFunction()
{	
	std::cout << "Some function call 0\n";
	auto obj = ObjectUnderTest();
	return obj;
}

std::unique_ptr<ObjectUnderTest> SomeFunction1()
{
	std::cout << "Some function call 1\n";
	auto obj = make_unique<ObjectUnderTest>();
	return obj;
}

void PrintOut(const ObjectUnderTest &obj)
{
	std::cout << "Print out call\n";
	std::cout << obj;
}

int main()
{
	PrintOut(SomeFunction());
	std::cout << "\n\n";
	PrintOut(*SomeFunction1());
	return 0;
}
