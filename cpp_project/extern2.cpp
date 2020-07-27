
# if 0
#include<iostream>
using namespace std;


extern int a;
int b = 20;
extern void printnum(int a);
static int a = 100;
int main()
{
	cout << a << endl;
	printnum(b);
}

#endif