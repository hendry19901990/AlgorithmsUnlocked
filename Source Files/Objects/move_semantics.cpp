#include <iostream>
#include <stdio.h>
using namespace std;
class loader
{
	int* bigarray;
public:
	/* Simple Constructor */
	loader(size_t size, int item) : bigarray(new int[size])
	{
		cout << "Default Constructor Called" << endl;
		for (size_t i = 0; i < size; i++)
		{
			bigarray[i] = item;
		}
	}
	loader(size_t size) : bigarray(new int[size])
	{
		cout << "Default Constructor Called" << endl;
		for (size_t i = 0; i < size; i++)
		{
			bigarray[i] = 0;
		}
	}
	loader(const loader& a)
	{
		cout << "Copy Constructor Called" << endl;
	}
	/* Copy Assignment Operator*/
	loader& operator=(const loader& a)
	{
		cout << "Copy Assignment Operator Called " << endl;
		this->bigarray = a.bigarray;
		return *this;
	}
	/*Move Constructor*/
	loader(loader&& a)
	{
		cout << "Move Constructor Called" << endl;
		this->bigarray = a.bigarray;
		a.bigarray = nullptr;
	}
	/* Move Assignment Operator*/
	loader& operator=(loader&& a)
	{
		cout << "Move Assignment Operator Called " << endl;
		this->bigarray = a.bigarray;
		a.bigarray = nullptr;
		return *this;
	}
	~loader()
	{
		cout << "Destructor Called" << endl;
	}
};
/* Code Here */
void takeobject(loader item)
{
	cout << "Object Taken" << endl;
}
loader returnref(loader item)
{
	cout << "Object returned as ref" << endl;
	return item;
}

int main(void)
{
	loader load(700000, 89000);
	loader item(7000000);
	loader poad = std::move(item);
	poad = std::move(load);
	load = std::move(item);
	takeobject(std::move(load));
	item = returnref(std::move(poad));
	return 0;

}

/*
Default Constructor Called
Default Constructor Called
Move Constructor Called
Move Assignment Operator Called 
Move Assignment Operator Called 
Move Constructor Called
Object Taken
Destructor Called
Move Constructor Called
Object returned as ref
Move Constructor Called
Move Assignment Operator Called 
Destructor Called
Destructor Called
Destructor Called
Destructor Called
Destructor Called
*/