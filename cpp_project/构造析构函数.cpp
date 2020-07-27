#if 0

#include<iostream>

using namespace std;


class Person
{
public:
	Person(); //构造函数在创建对象的时候系统自动调用
	Person(string name); //构造函数可以重载
	// 拷贝构造函数


	/*
		引用就是指针常量  所以Person& p <==> Person* const p,引用所以一旦初始化指向某个地址，就不能在改变了。
		为什么前面还要加const,因为拷贝构造函数的目的就是将一个对象的所有属性拷贝到另外一个对象，这个对象的属性不变，
		加上const 相当于 const Person& p = const Person* const p ;这个时候指向不能变，而且内容也不能变；其实本质上和下面的方法是一样的。
	*/
	Person(const Person& p)     
	{
		this->name = p.name;
		cout << "引用方式的拷贝构造函数" << endl;
	}
	Person(const Person* const p)
	{
		this->name = p->name;
		cout << "指针方式的拷贝构造函数" << endl;
	}
	
	~Person();//析构函数在销毁对象的时候系统自动调用


	void printObj()
	{
		cout << this->name << endl;
	}
	

private:
	string name;
	
};

Person::Person(string name)
{

	cout << "有参数构造函数" << endl;
	this->name = name;
}

Person::Person()
{
	cout << "构造函数" << endl;
}


Person::~Person()
{
	cout << "析构函数" << endl;
}


void test()
{
	//Person p = Person(); //创建一个对象的时候会调用构造函数
						 // p对象定义在栈区，test函数执行完成后，销毁p对象
}

int main()
{

	test();

	Person p2 = Person("张三"); //有参构造函数
	p2.printObj();
	Person p3 = Person(p2);// 引用方式的拷贝构造函数
	p3.printObj();
	Person p4 = Person(&p2);//指针方式的拷贝构造函数
	p4.printObj();

}

#endif