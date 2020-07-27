#include "swap.h"


/// <summary>
/// cpp文件中写实现
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}