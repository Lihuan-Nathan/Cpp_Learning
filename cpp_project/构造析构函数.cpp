#if 0

#include<iostream>

using namespace std;


class Person
{
public:
	Person(); //���캯���ڴ��������ʱ��ϵͳ�Զ�����
	Person(string name); //���캯����������
	// �������캯��


	/*
		���þ���ָ�볣��  ����Person& p <==> Person* const p,��������һ����ʼ��ָ��ĳ����ַ���Ͳ����ڸı��ˡ�
		Ϊʲôǰ�滹Ҫ��const,��Ϊ�������캯����Ŀ�ľ��ǽ�һ��������������Կ���������һ�����������������Բ��䣬
		����const �൱�� const Person& p = const Person* const p ;���ʱ��ָ���ܱ䣬��������Ҳ���ܱ䣻��ʵ�����Ϻ�����ķ�����һ���ġ�
	*/
	Person(const Person& p)     
	{
		this->name = p.name;
		cout << "���÷�ʽ�Ŀ������캯��" << endl;
	}
	Person(const Person* const p)
	{
		this->name = p->name;
		cout << "ָ�뷽ʽ�Ŀ������캯��" << endl;
	}
	
	~Person();//�������������ٶ����ʱ��ϵͳ�Զ�����


	void printObj()
	{
		cout << this->name << endl;
	}
	

private:
	string name;
	
};

Person::Person(string name)
{

	cout << "�в������캯��" << endl;
	this->name = name;
}

Person::Person()
{
	cout << "���캯��" << endl;
}


Person::~Person()
{
	cout << "��������" << endl;
}


void test()
{
	//Person p = Person(); //����һ�������ʱ�����ù��캯��
						 // p��������ջ����test����ִ����ɺ�����p����
}

int main()
{

	test();

	Person p2 = Person("����"); //�вι��캯��
	p2.printObj();
	Person p3 = Person(p2);// ���÷�ʽ�Ŀ������캯��
	p3.printObj();
	Person p4 = Person(&p2);//ָ�뷽ʽ�Ŀ������캯��
	p4.printObj();

}

#endif