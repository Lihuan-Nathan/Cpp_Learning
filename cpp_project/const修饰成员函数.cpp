#if 0
#include<iostream>

using namespace std;


class Person
{
public:
	//
	Person(string name,int age) :m_Name(name), m_Age(age){}
	void show()
	{
		this->m_Age = 100;
		cout << "name:" << this->m_Name << "; age:" << this->m_Age << endl;
	}
	void show1()const
	{
		//this = NULL;  //this ָ��ı����ǳ���ָ�룬�����޸�ָ���ָ��
		//this->m_Age = 15;  //const���γ�Ա������ʵ����<=>const Person *const this  �Ȳ����޸�ָ��Ҳ�����޸�ָ�������
		this->m_Name = "����1";    //�����Ա�������Ա��޸�����Ϊ��m_Name�Ǳ�mutable���εģ����ԽӴ�const������

		cout << "name:" << this->m_Name << "; age:" << this->m_Age << endl;
	}
	void changeAge(int agt)
	{

	}
	void changeName(string name)
	{

	}

private:
	mutable string m_Name;
	int m_Age;            //��Ա������const���α����������ڱ䡣
};



int main()
{
	Person p = Person("����",18);
	p.show();

	Person p1 = Person("����",19);
	p1.show1();

	const Person p2 = Person("���ϻ�",20);         //������
	// ������ֻ�ܵ��ó���Ա��������Ϊ�ǳ���Ա�����п��ܻ��޸ĳ�Ա������ֵ
	// ����������������޸���mutable���εĳ�Ա������Ȼ�����޸ĳɹ�
	p2.show1();

}

#endif