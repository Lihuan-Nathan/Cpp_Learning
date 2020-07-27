
# if 0
#include<iostream>

using namespace std;


class Clothes
{
	
public:
	Clothes(string name)
	{
		this->name = name;
	}
public:
	string name;

};

class Person
{
private:
	int age;
	string name;
	Clothes* ptr_clothes;
public:
	Person(int age,string name,string clo_name)
	{
		this->age = age;
		this->name = name;
		ptr_clothes = new Clothes(clo_name);
	}
	//深拷贝
	Person(const Person& p)
	{
		this->age = p.age;
		this->name = p.name;

		this->ptr_clothes = new Clothes((p.ptr_clothes)->name);   //

	}

	~Person()
	{
		if (ptr_clothes != NULL)
		{
			delete ptr_clothes;
			ptr_clothes = NULL;
		}
	}
};


int main()
{
	Person p1 = Person(10, "张三","李宁男装");
	Person p2 = p1;

}

#endif