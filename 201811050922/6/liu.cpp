#include<iostream> 
using namespace std;

class vehicle//汽车类vehicle
{
protected://保护成员
	int wheels;
	int weight;
public://公有成员
	vehicle(int w1, int w2)
	{
		wheels = w1;
		weight = w2;
	}
	void disp()
	{
		cout << "wheels=" << wheels << ",weight=" << weight << endl;
	}

};
class car :private vehicle//汽车类vehicle的私有派生小车类car
{
	int passenger_load;
public:
	car(int w1, int w2, int pa) :vehicle(w1, w2)
	{
		passenger_load = pa;
	}
	void disp()
	{
		vehicle::disp();
		cout << "passenger_load=" << passenger_load << endl;
	}


};
class truck :private vehicle//汽车类vehicle的私有派生卡车类truck
{
	int passenger_load;
	int payload;
public:
	truck(int w1, int w2, int pa, int pay) :vehicle(w1, w2)
	{
		passenger_load = pa;
		payload = pay;
	}
	void disp()
	{
		vehicle::disp();
		cout << "passenger_load=" << passenger_load << endl;
		cout<< "payload=" << payload << endl;
	}

};

void main()
{
	vehicle v(400, 360);
	v.disp();

	car c(200, 160, 120);
	c.disp();

	truck t(100, 70, 60, 30
		);
	t.disp();
	system("pause");
}
