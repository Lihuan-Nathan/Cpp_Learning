#if 0

#include<iostream>

using namespace std;


//选择排序，是每次选择一个小的或者最大的放在第一个位置

void choice_sort(int* a,int len)
{
	for (int i = 0; i < len-1; i++)
	{
		int max_index = i; //最大值的下标
		for (int j = i+1; j < len; j++)
		{
			if (a[j] > a[max_index])
			{
				max_index = j;
			}
		}

		//交换
		int temp;
		temp = a[i];
		a[i] = a[max_index];
		a[max_index] = temp;
	}
}

/// <summary>
/// 快速排序，按照基准点，将数组分为两个部分，然后两个部分在继续排序
/// </summary>
/// <param name="a"></param>
/// <param name="len"></param>
void quick_sort(int* a, int i,int j)
{
	int refer_value = a[i];
	
	int head = i;
	int end = j;
	while (head>=end)
	{
		if (a[head] > refer_value)
		{
			if (a[end] <= refer_value)
			{
				//直接交换
				int temp = a[head];
				a[head] = a[end];
				a[end] = temp;
			}
			else
			{
				//end--
				end--;
			}
		}
		// a[head]<refer_value
		else
		{
			head++;
		}
	}
	quick_sort(a, i,head-1);
	quick_sort(a, end+1,j );
}

void printArr(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << endl;
	}
}

int main()
{
	int a[] = { 1, 2, 3, 9, 6, 8, 7, 4, 5 };
	int len = sizeof(a) / sizeof(int);
	printArr(a, len);
	//choice_sort(a, len);
	cout << "-----------" << endl;
	

	quick_sort(a, 0, len - 1);

	printArr(a, len);
}

#endif