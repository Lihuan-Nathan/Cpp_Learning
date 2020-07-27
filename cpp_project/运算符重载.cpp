# include <iostream>

using namespace std;

//运算符重载的目的是为了给自定义的数据类型，给予某种功能。
class Person
{
public:
	int age;
	string* ptr_name;
public:
	Person(int age)
	{
		this->age = age;
	}
	Person(int age, string* ptr_name)
	{
		this->age = age;
		this->ptr_name = ptr_name;
	}
	Person()
	{

	}
	//返回Person发生拷贝构造函数，这个时候局部变量p3销毁后，拷贝到的另外一个对象不受影响。
	Person operator+(const Person& p)   //*this+p
	{
		Person p3;
		p3.age = this->age + p.age;
		return p3;
	}


	//左移运算符不能是成员函数 
	//成员函数 实现不了  p << cout 不是我们想要的效果
	//void operator<<(Person& p){
	//}

	//前置++
	Person& operator++()
	{
		++this->age;
		return *this;
	}

	//后置
	Person operator++(int)
	{
		//
		Person temp = *this;        //创建临时对象
		this->age++;
		//返回局部对象，这个时候将返回值的类型设置为Person类型，这个时候会发生拷贝构造函数，此临时对象销毁后不会影响到另外一个对象，如果返回引用类型（引用的是局部变量，这个时候函数执行完成销毁对象，别名就指向野指针了。）
		return temp;                

	}



	void Print(string name)
	{
		cout << name <<":      " <<this->age << endl;
	}

	void operator() (string test)
	{
		cout << test << endl;
	}

	
	//赋值运算符重载
	Person& operator=(const Person& p)
	{
		//如果原来的ptr_name不为空先释放内存
		if (ptr_name != NULL)
		{
			delete ptr_name;
			ptr_name = NULL;
		}
		this->age = p.age;
		//开一个新的内存
		this->ptr_name = new string(*p.ptr_name);

		return *this;

		
	}

	//  ==运算符重载(成员函数，也可以全局函数重载)
	bool operator== (const Person& p)const
	{
		if (*this->ptr_name == *p.ptr_name && this->age == p.age)
		{
			return true;
		}
		return false;
	}
	
	
};

//!=运算符重载（全局函数，也可以成员函数重载）
bool operator!=(const Person& p1,const Person& p2)
{
	if (*p1.ptr_name == *p2.ptr_name && p1.age == p2.age)
	{
		return false;
	}
	return true;
}

//全局函数重载运算符+
Person operator+ (const Person& p1, const Person& p2)
{
	Person p3;
	p3.age = p1.age + p2.age;
	return p3;
}


//函数重载+
Person operator+(const Person& p1,  int d)
{
	Person p3;
	p3.age = p1.age +  d;
	return p3;
}



//左移运算符
//链式编程返回引用
ostream& operator<<(ostream& out, const Person& p)
{
	out << p.age;
	return out;
}



int main()
{
	Person p1 = Person(10);
	Person p2 = Person(20);
	Person p3 = p1 + p2;         //   <=>p1.operator+(p2);  成员函数重载+运算符
	p3.Print("p3");
	Person p4 = operator+(p1,p3);  // <=> p4 = p1+p3 ;全局函数重载+运算符
	p4.Print("p4");
	cout << p4 << endl;;

	cout << "p1:       " << p1.age << endl;
	cout << "p1++:       " << p1++<< endl;
	cout << "++p1:       " << ++p1<< endl;

	string name = "张雨晨";
	Person p5 = Person(18,&name );
	Person p6, p7;
	p6 = p7 = p5;

	cout << (p6 == p7) << endl;
	*p6.ptr_name = "王思雨";        
	cout << (p6 == p7) << endl;
	cout << (p6 != p7) << endl;


	//匿名对象调用仿函数
	Person()("测试仿函数");
}