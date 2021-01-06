#include <stdio.h>
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <mysql.h>
#include <string.h>
using namespace std;

#pragma comment(lib,"libmysql.lib")
int main(int argc, char** argv)
{
	MYSQL mysql, * sock;    // 定义数据库连接的句柄，它被用于几乎所有的 MySQL 函数
	MYSQL_RES* res;       // 查询结果集，结构类型
	//MYSQL_FIELD* fd;     // 包含字段信息的结构
	MYSQL_ROW row;       // 存放一行查询结果的字符串数组
	char  qbuf[256];      // 存放查询 sql 语句字符串
	char fun;
	char num[10], name[10], sex[10], school[10], home[10], phone[15];
	int minmum_salary, extra_salary, live_salary, phone_bill, water_ele_bill, house_bill, get_in_bill, sanitary_fee, public_money, should_salary, all_bill, real_salary;
	//char table_name[20];
	//	if (argc != 2) {  // 检查输入参数
	//		fprintf(stderr,"usage : mysql_select <userid>/n/n");
	//		exit(1);
	//	}
	mysql_init(&mysql);
	if (!(sock = mysql_real_connect(&mysql, "localhost", "root", "123456", "teacher", 0, NULL, 0)))//中间分别是主机，用户名，密码，数据库名，端口号（可以写默认0或者3306等）
	{
		fprintf(stderr, "Couldn't connect to engine!/n%s/n/n", mysql_error(&mysql));
		perror("");
		exit(1);
	}
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "utf8mb4");
	system("cls");
	while (1)
	{
		cout << "欢迎来到教师工资管理系统！" << endl << endl;
		cout << "请选择功能：（使用回车确认每一项）" << endl << endl;
		cout << "||A.输入教师信息" << "||B.插入（修改）教师信息" << "||C.删除教师信息" << "||D.浏览教师信息" << "||Q.退出" << endl << endl;
		cout << "||1.输入教师数据" << "||2.教师实发工资、应发工资、合计扣款计算" << "||3.教师数据管理" << "||4.教师数据查询" << "||5.教师综合信息输出" << endl << endl;
		cin >> fun;
		if (fun == 'A'|| fun == 'a')
		{
			cout << "请输入教师号、姓名、性别、单位名称、家庭住址、联系电话： "<<endl;
			cin >> num>>name>> sex>> school>> home>> phone;
			sprintf_s(qbuf ,"insert into information (num, name, sex, school, home, phone) values ('%s','%s','%s','%s','%s','%s');" , num, name, sex, school, home, phone);
			mysql_query(&mysql,qbuf);
			//此处输入报错代码
			mysql_query(&mysql, "select * from information");
			res = mysql_store_result(&mysql);
			cout << "||" << "教师号" << "||" << "姓名" << "||" << "性别" << "||" << "单位名称" << "||" << "家庭住址" << "||" << "联系电话" << "||" << endl;
			while (row = mysql_fetch_row(res))//查询表1
			{
				cout << "||" << row[0] << "||" << row[1] << "||" << row[2] << "||" << row[3] << "||" << row[4] << "||" << row[5] << "||" << endl;
			}
			cout << "_______________________________________________";
			cout << endl;
			system("pause");
		}
		else if (fun == 'B' || fun == 'b')
		{
			cout << "请输入要改变的项目(num, name, sex, school, home, phone)、数值及对应教师号：" << endl;
			cin >> name>>phone>>num;
			sprintf_s(qbuf, "UPDATE information SET %s='%s' WHERE num='%s';",name,phone,num);
			mysql_query(&mysql, qbuf);
			//此处输入报错代码
			mysql_query(&mysql, "select * from information");
			res = mysql_store_result(&mysql);
			cout << "||" << "教师号" << "||" << "姓名" << "||" << "性别" << "||" << "单位名称" << "||" << "家庭住址" << "||" << "联系电话" << "||" << endl;
			while (row = mysql_fetch_row(res))//查询表1
			{
				cout << "||" << row[0] << "||" << row[1] << "||" << row[2] << "||" << row[3] << "||" << row[4] << "||" << row[5] << "||" << endl;
			}
			cout << "_______________________________________________";
			cout << endl;
			system("pause");
		}
		else if (fun == 'C' || fun == 'c')
		{
			cout << "请输入要删除的教师信息的教师号：" << endl;
			cin >> num;
			sprintf_s(qbuf, "DELETE FROM information WHERE num='%s';", num);
			mysql_query(&mysql, qbuf);
			//此处输入报错代码
			mysql_query(&mysql, "select * from information");
			res = mysql_store_result(&mysql);
			cout << "||" << "教师号" << "||" << "姓名" << "||" << "性别" << "||" << "单位名称" << "||" << "家庭住址" << "||" << "联系电话" << "||" << endl;
			while (row = mysql_fetch_row(res))//查询表1
			{
				cout << "||" << row[0] << "||" << row[1] << "||" << row[2] << "||" << row[3] << "||" << row[4] << "||" << row[5] << "||" << endl;
			}
			cout << "_______________________________________________";
			cout << endl;
			system("pause");
		}
		else if (fun == 'D' || fun == 'd')
		{
			mysql_query(&mysql, "select * from information");
			res = mysql_store_result(&mysql);
			cout << "||" << "教师号" << "||" << "姓名" << "||" << "性别" << "||" << "单位名称" << "||" << "家庭住址" << "||" << "联系电话" << "||" << endl;
			while (row = mysql_fetch_row(res))//查询表1
			{
				cout << "||" << row[0] << "||" << row[1] << "||" << row[2] << "||" << row[3] << "||" << row[4] << "||" << row[5] << "||" << endl;
			}
			cout << "_______________________________________________";
			cout << endl;
			system("pause");
		}
		else if (fun == 'Q' || fun == 'q')
		{
			cout << "Bye."<<endl;
			system("pause");
			exit(1);
		}
		else if (fun == '1')//||1.输入教师数据" << "||2.教师实发工资、应发工资、合计扣款计算" << |3.教师数据管理" << "||4.教师数据查询" << "||5.教师综合信息输出 13教师号、基本工资、津贴、生活补贴、电话费、水电费、房租、所得税、卫生费、公积金、应发工资、实际扣款、实发工资" 
		{
			cout << "请输入教师号、基本工资、津贴、生活补贴、电话费、水电费、房租、所得税、卫生费、公积金：（10） " << endl;
			cin >> num >> minmum_salary >> extra_salary >> live_salary >> phone_bill >> water_ele_bill >> house_bill >> get_in_bill >> sanitary_fee >> public_money ;
			sprintf_s(qbuf, "insert into money (num,minimum_salary,extra_salary,live_salary,phone_bill,water_ele_bill,house_bill,get_in_bill,sanitary_fee,public_money) values ('%s','%d','%d','%d','%d','%d','%d','%d','%d','%d');", num, minmum_salary, extra_salary, live_salary, phone_bill, water_ele_bill, house_bill, get_in_bill, sanitary_fee, public_money);
			mysql_query(&mysql, qbuf);
			//此处输入报错代码
			mysql_query(&mysql, "select * from money");
			res = mysql_store_result(&mysql);
			cout << "||教师号" << "||基本工资" << "||津贴" << "||生活补贴" << "||电话费" << "||水电费" << "||房租" << "||所得税" << "||卫生费" << "||公积金" << endl;
			while (row = mysql_fetch_row(res))//查询表1
			{
				cout << "||" << row[0] << "||" << row[1] << "||" << row[2] << "||" << row[3] << "||" << row[4] << "||" << row[5] << "||" << row[6] << "||" << row[7] << "||" << row[8] << "||" << row[9] << "||" << endl;
			}
			cout << "_______________________________________________";
			cout << endl;
			system("pause");
		}
		else if (fun == '2')
		{
			cout << "请输入教师号： " << endl;
			cin >> num;
			sprintf_s(qbuf, "select * from money where num='%s';", num);//num,minimum_salary,extra_salary,live_salary,phone_bill,water_ele_bill,house_bill,get_in_bill,sanitary_fee,public_money
			mysql_query(&mysql,qbuf );
			res = mysql_store_result(&mysql);
				cout << "||教师号" << "||基本工资" << "||津贴" << "||生活补贴" << "||电话费" << "||水电费" << "||房租" << "||所得税" << "||卫生费" << "||公积金" << endl;
			row = mysql_fetch_row(res);
			cout << "||" << row[0] << "||" << row[1] << "||" << row[2] << "||" << row[3] << "||" << row[4] << "||" << row[5] << "||" << row[6] << "||" << row[7] << "||" << row[8] << "||" << row[9] << "||" << endl;
			should_salary = atoi(row[1])+ atoi(row[2]) + atoi(row[3]) ;
			all_bill=  atoi(row[4]) + atoi(row[5]) + atoi(row[6]) + atoi(row[7]) + atoi(row[8]) + atoi(row[9]);
			real_salary=should_salary - all_bill;
			cout << "应发工资:" << should_salary << endl << "合计扣款:" << all_bill << endl << "实发工资:" << real_salary << endl;
			sprintf_s(qbuf, "update money set should_salary='%d',all_bill='%d',real_salary='%d'where num='%s';", should_salary, all_bill, real_salary, num);//num,minimum_salary,extra_salary,live_salary,phone_bill,water_ele_bill,house_bill,get_in_bill,sanitary_fee,public_money
			mysql_query(&mysql, qbuf);
			system("pause");
		}
		else if (fun == '3')
		{
		cout << "请输入要改变的项目(minimum_salary,extra_salary,live_salary,phone_bill,water_ele_bill,house_bill,get_in_bill,sanitary_fee,public_money)、数值及对应教师数据的教师号：" << endl;
		cin >> name>>phone >>num;
		sprintf_s(qbuf, "UPDATE money SET %s='%s' WHERE num='%s';", name, phone,num);
		mysql_query(&mysql, qbuf);
		//此处输入报错代码
		mysql_query(&mysql, "select * from money");
		res = mysql_store_result(&mysql);
		cout << "||教师号" << "||基本工资" << "||津贴" << "||生活补贴" << "||电话费" << "||水电费" << "||房租" << "||所得税" << "||卫生费" << "||公积金" << endl;
		while (row = mysql_fetch_row(res))//查询表1
		{
			cout << "||" << row[0] << "||" << row[1] << "||" << row[2] << "||" << row[3] << "||" << row[4] << "||" << row[5] << "||" << row[6] << "||" << row[7] << "||" << row[8] << "||" << row[9] << "||" << endl;
		}
		cout << "_______________________________________________";
		cout << endl;
		system("pause");
		}
		else if (fun == '4')
		{
		cout << "请输入要查询的教师数据的教师号：";
		cout << endl;
		cin >> num;
		sprintf_s(qbuf, "select * from money where num='%s';", num);
		mysql_query(&mysql,qbuf);
		res = mysql_store_result(&mysql);
		//cout.setf(ios::internal);
		cout << "||" << "教师号" << "||基本工资" << "||津贴" << "||生活补贴" << "||电话费" << "||水电费" << "||房租" << "||所得税" << "||卫生费" << "||公积金" << "||应发工资" << "||合计扣款" << "||实发工资" << endl;
		while (row = mysql_fetch_row(res))//查询表1
		{
			cout << "||" << row[0] << "||" << row[1] << "||" << row[2] << "||" << row[3] << "||" << row[4] << "||" << row[5] << "||" << row[6] << "||" << row[7] << "||" << row[8] << "||" << row[9] << "||" << row[10] << "||" << row[11] << "||" << row[12] << "||" << endl;
		}
		cout << "_______________________________________________";
		cout << endl;
		system("pause");
		}
		else if (fun == '5')
		{
			//获取结果集
			mysql_query(&mysql, "select * from information");
			//显示数据
			res = mysql_store_result(&mysql);
			//cout.setf(ios::internal);
			cout << "||" << "教师号" << "||" << "姓名" << "||" << "性别" << "||" << "单位名称" << "||" << "家庭住址" << "||" << "联系电话" << "||" << endl;
			while (row = mysql_fetch_row(res))//查询表1
			{
				cout << "||" << row[0] << "||" << row[1] << "||" << row[2] << "||" << row[3] << "||" << row[4] << "||" << row[5] << "||" << endl;
			}
			cout << "_______________________________________________";
			cout << endl;
			//查询表2
			mysql_query(&mysql, "select * from money");
			res = mysql_store_result(&mysql);
			cout << "||基本工资" << "||津贴" << "||生活补贴" << "||电话费" << "||水电费" << "||房租" << "||所得税" << "||卫生费" << "||公积金" << "||应发工资" << "||合计扣款" << "||实发工资" << endl;
			while (row = mysql_fetch_row(res))
			{
				cout << "||" << row[0] << "||" << row[1] << "||" << row[2] << "||" << row[3] << "||" << row[4] << "||" << row[5] << "||" << row[6] << "||" << row[7] << "||" << row[8] << "||" << row[9] << "||" << row[10] << "||" << row[11] << "||" << row[12] << "||" << endl;
			}
			cout << "_______________________________________________";
			cout << endl;
			system("pause");
		}

		else
		{
			cout << "请输入正确选项！" << endl;
			system("pause");
		}
		//mysql_free_result(res);
		//mysql_close(sock);
		system("cls");
	}
	return 0;
}
