#if 0
#include<iostream>

using namespace std;

void printArr(int* arr, int len);


//Ԫ�����ã�ǰ��ָ�뷨��������
void reverse(int* arr,int len)
{
	/// <summary>
	/// ����Ҫע����ǣ�������Ϊ�������ݽ���
	///���ʾ���һ��ָ�룬��������鳤�ȵ�ʱ��
	///���ʱ�������������һ��ָ������Ǵ����������飬
	///sizeof(������)��ʵ�������һ��ָ��ĵ��ڴ��С��
	///��������������ڴ��С���������ʱ��ʹ��sizeof(������)/sizeof(arr[0]) �㲻������ĳ��ȡ�
	/// 
	/// </summary>
	/// <param name="arr"></param>
	/// <param name="len"></param>
	int head = 0;
	int trail = len - 1;
	int temp; 
	while (head<trail)
	{
		//����
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

//ð��
void bubbleSort(int* arr, int len)
{
	//1���Ƚ����ڵ�Ԫ�ء������һ���ȵڶ����󣬾ͽ���
	//2���Ա�û��
	//3������-1


	// ��������
	for (int i = 0; i < len-1; i++)
	{
		//���ڶԱ�
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