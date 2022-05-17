# include <iostream>
# include <memory>

using namespace std;

class Object
{
public:
	Object() = default; 
	virtual void run() = 0;
};

class ConObject : public Object
{
public:
	ConObject() = default;
	virtual void run() override { cout << "Run method;" << endl; }
};

class ConObject2 : public Object
{
public:
	ConObject2() = default;
	void run() override { cout << str << endl; }
	void setStr(std::string newStr) {
		str = newStr;
	}
private:
	std::string str;
};

class Command
{
public:
	virtual ~Command() = default;
	virtual void execute(shared_ptr<Object>) = 0;
};

class SimpleCommand : public Command
{
	using Action = void(ConObject::*)();
private:

public:
	SimpleCommand() = default;

	virtual void execute(shared_ptr<Object> r) { r->run(); }
};

class SimpleCommand2 : public Command
{
private:
	std::string str;

public:
	SimpleCommand2(std::string str) : str(str) {}

	virtual void execute(shared_ptr<Object> r) { 
		std::cout << "MDA" << endl;
	}

	virtual void execute(shared_ptr<ConObject2> r) { 
		r->setStr(str);
		r->run();
	}
};

int main()
{
	SimpleCommand2 command = SimpleCommand2("tralala");

	shared_ptr<Object> obj = make_shared<ConObject2>();

	command.execute(obj);
}