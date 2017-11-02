#include <iostream>
#include <cstring>

class Foo
{
	char *data;
	friend std::ostream &operator <<(std::ostream &, const Foo &);

public:
	// Default Constructor
	Foo(void);

	// Copy Constructor
	Foo(const Foo &);

	// Move Constructor
	Foo(Foo &&) noexcept;

	// Destructor
	~Foo(void) noexcept;

	// Copy assignment operator
	Foo &operator =(const Foo &);

	// Move assignment operator
	Foo &operator =(Foo &&) noexcept;
};

Foo::Foo(void): data(new char[14])
{
	std::strcpy(data, "Hello World!");
}

Foo::Foo(const Foo &other): data(new char[std::strlen(other.data) + 1])
{
	std::strcpy(data, other.data);
}

Foo::Foo(Foo &&other) noexcept: data(other.data)
{
	other.data = nullptr;
}

Foo::~Foo(void) noexcept
{
	delete[] data;
}

Foo &Foo::operator =(const Foo &other)
{
	Foo tmp(other);
	*this = std::move(tmp);
	return *this;
}

Foo &Foo::operator =(Foo &&other) noexcept
{
	delete[] data;
	data = other.data;
	other.data = nullptr;
	return *this;
}

std::ostream &operator <<(std::ostream &os, const Foo &foo)
{
	os << foo.data;
	return os;
}

int main(void)
{
	const Foo bar;
	std::cout << bar << std::endl;

	return 0;
}
