#include <iostream>
#include <stdio.h>
using namespace std;
int fun(int a, int b)
{
	int  c;
	c = (a % 10) * 1000 + (b % 10) * 100 + (a / 10) * 10 + b / 10;
	return c;
}
int main()
{
	int a,b ;
	cin >> a >> b;
	cout << fun(a, b) << endl;
	return 0;

}