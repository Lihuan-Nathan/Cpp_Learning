
# if 0
#include<iostream>

using namespace std;


int* fun()
{
	int* p = new int(10);
	return p;
}

int* arr_fun()
{
	int* arr = new int[10];
	
	return arr;
}


void printArray(int* arr, int len)
{
	for (int i = 1; i < len; i++)
	{
		cout << arr[i] << endl;
	}
}

int main()
{
	int* p = fun();
	cout << *p << endl;

	int* arr = arr_fun();
	

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 100;
	}


	printArray(arr, 10);


	delete []arr;             //s

}

#endif