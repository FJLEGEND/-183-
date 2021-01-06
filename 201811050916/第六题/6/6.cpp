//编写一个程序，有一个汽车类vehicle, 它具有一个需传递参数的构造函数，类中的数据成员：车轮个数wheels和车重weight放在保护段中；
//小车类car是它的私有派生类，其中包含载人数passenger_load；
//卡车类truck是vehicle的私有派生类，其中包含载人类passenger_load和载重量payload。
//每个类都有相关数据的输出方法。
//

#include <iostream>
using namespace std;
class vehicle
{
public:
	vehicle(int a,float b)
	{
		//cout << "已构造" << endl;
		wheels = a;
		weight = b;
	}
	 ~vehicle()
	{
		cout << "已析构" << endl;
	}
protected:
	int wheels=0;
	float weight=0;
};

class car:private vehicle
{
public:
	car(int i, float j, int k):vehicle(i,j)
	{
		cout << "car已构造" << endl;
		passenger_load = k;
	}
	~car()
	{
		cout << "car已析构" << endl;
	}
	int show_wheels()
	{
		return wheels;
	}
	float show_weight()
	{
		return weight;
	}
	int show_passenger_load()
	{
		return passenger_load;
	}
private:
	int passenger_load;
};

class truck:private vehicle
{
public:
	truck(int i, float j, int k, float l) :vehicle(i,j)
	{
		cout << "truck已构造" << endl;
		passenger_load = k;
		payload = l;
	}
	~truck() 
	{
		cout << "truck已析构" << endl;
	}
	int show_wheels()
	{
		return wheels;
	}
	float show_weight()
	{
		return weight;
	}
	int show_passenger_load()
	{
		return passenger_load;
	}
	float show_payload()
	{
		return payload;
	}
private:
	int passenger_load;
	float payload;
};

int main()
{
	car car1(4,50,5);
	truck truck1(8, 100, 2, 80);

	cout << "小车信息：" << endl;
	cout << "车轮个数：" <<car1.show_wheels() << endl;
	cout << "车重：" << car1.show_weight() << endl;
	cout << "载人数：" << car1.show_passenger_load() << endl;
	cout << endl;
	cout << "卡车信息：" << endl;
	cout << "车轮个数：" <<truck1.show_wheels() << endl;
	cout << "车重："  << truck1.show_weight()<<endl;
	cout << "载人数：" <<truck1.show_passenger_load()<< endl;
	cout << "载重量："<<truck1.show_weight()  << endl;
	system("pause");
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
