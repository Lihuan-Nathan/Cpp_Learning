#if 0

#include<iostream>

using namespace std;


//ѡ��������ÿ��ѡ��һ��С�Ļ������ķ��ڵ�һ��λ��

void choice_sort(int* a,int len)
{
	for (int i = 0; i < len-1; i++)
	{
		int max_index = i; //���ֵ���±�
		for (int j = i+1; j < len; j++)
		{
			if (a[j] > a[max_index])
			{
				max_index = j;
			}
		}

		//����
		int temp;
		temp = a[i];
		a[i] = a[max_index];
		a[max_index] = temp;
	}
}

/// <summary>
/// �������򣬰��ջ�׼�㣬�������Ϊ�������֣�Ȼ�����������ڼ�������
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
				//ֱ�ӽ���
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