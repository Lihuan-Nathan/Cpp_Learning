
# if 0
#include<iostream>

using namespace std;

/// <summary>
/// �����������Ĳ���
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
void  exchange(int& a, int& b)
{

	int temp = a;
	a = b;
	b = a;
}


/// <summary>
/// �����������ķ���ֵ
/// </summary>
/// <returns></returns>

int& ret(int& a)
{
	int& p = a;      //����һ�����ã����ڱ���a�ĵ�ַ ��������ʵ���ǳ���ָ�룩
	p = 100;         //p��aָ��һ����ַ,�޸�p���Ǹ�a
	return p;        //�������ã���Ϊ����ֵ�����;�������.
}

int main()
{
	int a = 2;
	int b = 3;
	int e = 120;

	// ����Ҫע��
	int& c = a;      //���ñ����ʼ�������ҳ�ʼ�����ܸı�
	exchange(a, b);

	// ������Ϊ����
	cout << ret(a) << endl;        // ��������Ϊ��������
	cout << a << endl;             // a�Ѿ��޸�Ϊ��100
	ret(a) = e;                    // ret(a)������Ϊ��ֵ������Ϊret(a)����a��֧���޸�
	cout << a << endl;
	
	//ָ��ı�����ָ�볣��

	//�������Զ�ת��Ϊָ�볣�� int * const ref = &b
	//ָ�볣��ָ���ǲ����Ըĵģ����������ǿ����޸ĵ�
	int ref = b; 

	ref = 10; //�ڲ�����ref�����õ�ʱ���Զ�ת��Ϊ*ref

}

#endif