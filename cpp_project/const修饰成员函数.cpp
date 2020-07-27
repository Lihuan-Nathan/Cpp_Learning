#if 0
#include<iostream>

using namespace std;


class Person
{
public:
	//
	Person(string name,int age) :m_Name(name), m_Age(age){}
	void show()
	{
		this->m_Age = 100;
		cout << "name:" << this->m_Name << "; age:" << this->m_Age << endl;
	}
	void show1()const
	{
		//this = NULL;  //this 指针的本质是常量指针，不可修改指针的指向
		//this->m_Age = 15;  //const修饰成员函数，实际上<=>const Person *const this  既不能修改指向也不能修改指向的内容
		this->m_Name = "李四1";    //这个成员变量可以被修改是因为，m_Name是被mutable修饰的，可以接触const的限制

		cout << "name:" << this->m_Name << "; age:" << this->m_Age << endl;
	}
	void changeAge(int agt)
	{

	}
	void changeName(string name)
	{

	}

private:
	mutable string m_Name;
	int m_Age;            //成员变量用const修饰表明，不可在变。
};



int main()
{
	Person p = Person("张三",18);
	p.show();

	Person p1 = Person("李四",19);
	p1.show1();

	const Person p2 = Person("王老虎",20);         //常对象
	// 常对象只能调用常成员函数，因为非常成员函数中可能会修改成员变量的值
	// 但是如果常函数中修改了mutable修饰的成员变量仍然可以修改成功
	p2.show1();

}

#endif