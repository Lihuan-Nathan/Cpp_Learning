# if 0

#include<iostream>

using namespace std;
class Building;

class  GoodGuyAA
{
public:
	GoodGuyAA();
	void visit3();
	void visit4();

private:
	Building* ptr_build;
};


class Building
{
	friend void GoodGuyAA::visit4();
	
public:
	Building();
	
public:
	string m_livingRoom;
private:
	string m_bedRoom;
};



Building::Building()
{
	m_livingRoom = "����";
	m_bedRoom = "����";
}
GoodGuyAA::GoodGuyAA()
{
	ptr_build = new Building;
}

void GoodGuyAA::visit4()
{
	cout << "GoodGuy1�����Building��" << ptr_build->m_bedRoom << endl;
	cout << "GoodGuy1�����Building��" << ptr_build->m_livingRoom << endl;
}

void GoodGuyAA::visit3()             //û����Ԫ�����ܷ���Building�е�˽�г�Ա��
{
	//cout << "GoodGuy1�����Building��" << ptr_build->m_bedRoom << endl;
	cout << "GoodGuy1�����Building��" << ptr_build->m_livingRoom << endl;
}
int main()
{
	GoodGuyAA g1;
	g1.visit3();
	g1.visit4();
}

#endif