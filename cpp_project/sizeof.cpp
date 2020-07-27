
# if 0
#include<iostream>
using namespace std;

int main()
{
	int a[5];
	int* p = a;
	cout << sizeof(a) << endl;  //通过数组名，可以计算整个数组的内存大小
	cout << sizeof(p) << endl;  //这个时候虽然p和a的值是一样的，但是编译器只把这个当作指针，所以就是指针的大小。
}

#endif