#include "swap.h"


/// <summary>
/// cpp�ļ���дʵ��
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}