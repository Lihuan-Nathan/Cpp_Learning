
# if 0
#include<iostream>

using namespace std;

/// <summary>
/// 引用做函数的参数
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
void  exchange(int& a, int& b)
{

	int temp = a;
	a = b;
	b = a;
}


/// <summary>
/// 引用做函数的返回值
/// </summary>
/// <returns></returns>

int& ret(int& a)
{
	int& p = a;      //声明一个引用，用于保存a的地址 （引用其实就是常量指针）
	p = 100;         //p和a指向一个地址,修改p就是改a
	return p;        //返回引用，因为返回值的类型就是引用.
}

int main()
{
	int a = 2;
	int b = 3;
	int e = 120;

	// 引用要注意
	int& c = a;      //引用必须初始化，并且初始化后不能改变
	exchange(a, b);

	// 引用作为参数
	cout << ret(a) << endl;        // 将引用作为参数传递
	cout << a << endl;             // a已经修改为了100
	ret(a) = e;                    // ret(a)可以作为左值，是因为ret(a)就是a，支持修改
	cout << a << endl;
	
	//指针的本质是指针常量

	//编译器自动转换为指针常量 int * const ref = &b
	//指针常量指向是不可以改的，但是内容是可以修改的
	int ref = b; 

	ref = 10; //内部发现ref是引用的时候，自动转换为*ref

}

#endif