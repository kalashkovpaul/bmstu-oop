# include <iostream>
# include <memory>

using namespace std;

class A {
public:
	explicit A() = default;
	explicit A(int id): id(id) { std::cout << "here\n"; }
private:
	int id;
};

class B: public A {
	using A::A;
};

int main()
{
	B object = B(1);
	return 0;
}