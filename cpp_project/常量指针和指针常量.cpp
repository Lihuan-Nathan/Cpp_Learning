# if 0
#include<iostream>

using namespace std;

int main()
{
	int a = 10;
	int b = 10;
	int c = 20;

	const int* p = &a;  //����ָ�룬const����*pǰ�棬����*p���ܸ�
	//*p = c;//���������޸�*p

	p = &c;
	cout << *p << endl;

	int* const p1 = &a; //ָ�볣����const����p1ǰ�棬����ָ�벻���޸�


}

#endif