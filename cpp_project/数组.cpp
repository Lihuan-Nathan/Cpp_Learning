#if 0
#include<iostream>

using namespace std;

void printArr(int* arr, int len);


//元素逆置，前后指针法，互换。
void reverse(int* arr,int len)
{
	/// <summary>
	/// 这里要注意的是，数组作为参数传递进来
	///本质就是一个指针，如果算数组长度的时候，
	///这个时候的数组名就是一个指针而不是代表整个数组，
	///sizeof(函数名)其实就是算出一个指针的的内存大小，
	///不是整个数组的内存大小，所以这个时候使用sizeof(函数名)/sizeof(arr[0]) 算不是数组的长度。
	/// 
	/// </summary>
	/// <param name="arr"></param>
	/// <param name="len"></param>
	int head = 0;
	int trail = len - 1;
	int temp; 
	while (head<trail)
	{
		//交换
		temp = arr[head];
		arr[head] = arr[trail];
		arr[trail] = temp;
		head += 1;
		trail -= 1;
	}

	printArr(arr, len);
}


void printArr(int* arr,int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << endl;
	}
}

//冒泡
void bubbleSort(int* arr, int len)
{
	//1、比较相邻的元素、如果第一个比第二个大，就交换
	//2、对比没组
	//3、次数-1


	// 排序轮数
	for (int i = 0; i < len-1; i++)
	{
		//相邻对比
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	printArr(arr, len);
}




int main()
{
	int arr[] = {0,1,2,3,4};
	int len = sizeof(arr) / sizeof(arr[0]);
	printArr(arr, len);
	cout << "-----------" << endl;
	reverse(arr,len);
	cout << "-----------" << endl;
	bubbleSort(arr, len);
}
#endif