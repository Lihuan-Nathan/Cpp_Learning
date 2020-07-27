# if 0
#include<iostream>

using namespace std;

int main()
{
	int a = 10;
	int b = 10;
	int c = 20;

	const int* p = &a;  //常量指针，const加在*p前面，所以*p不能改
	//*p = c;//报错，不可修改*p

	p = &c;
	cout << *p << endl;

	int* const p1 = &a; //指针常量，const加在p1前面，所以指针不能修改


}

#endif