#include <stdio.h>
#include "mysql.h"
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <mysql.h>
using namespace std;

#pragma comment(lib,"libmysql.lib")

int main(int argc, char** argv)
{
	MYSQL mysql, * sock;    // 定义数据库连接的句柄，它被用于几乎所有的 MySQL 函数
	MYSQL_RES* res;       // 查询结果集，结构类型
	MYSQL_FIELD* fd;     // 包含字段信息的结构
	MYSQL_ROW row;       // 存放一行查询结果的字符串数组
	//char  qbuf[256];      // 存放查询 sql 语句字符串

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

	mysql_query(&mysql, "use teacher");
	mysql_query(&mysql, "select * from information");
	//获取结果集
	res = mysql_store_result(&mysql);
	//显示数据
	//给ROW赋值，判断ROW是否为空，不为空就打印数据。
	while (row = mysql_fetch_row(res))
	{
		//printf("%s ", row[0]);//打印id
		//printf("%s ", row[1]);//打印id
		cout << row[1];
		cout << endl;
	}

	mysql_free_result(res);
	mysql_close(sock);
	exit(0);

	return 0;
}

/*
命令行运行：

C:/Documents and Settings/l/ 桌面 / 新建文件夹 (2)/Debug>mysql 200301

number of fields returned: 1

Ther userid #200301 's sex is: m

query ok !




查询数据库信息

C:/Documents and Settings/l>mysql -u root -p

Enter password: *******

Welcome to the MySQL monitor.  Commands end with ; or /g.

Your MySQL connection id is 1

Server version: 5.1.34-community MySQL Community Server (GPL)



Type 'help;' or '/h' for help. Type '/c' to clear the current input statement.

mysql> show databases;

+--------------------+

| Database           |

+--------------------+

| information_schema |

| base1              |

| mydb               |

| mysql              |

| proj               |

| test               |

+--------------------+

6 rows in set (0.08 sec)



mysql> use mydb;

Database changed

mysql> show tables;

+----------------+

| Tables_in_mydb |

+----------------+

| employee       |

| products       |

| test1          |

+----------------+

3 rows in set (0.03 sec)



mysql> describe employee;

+-------------+---------+------+-----+---------+-------+

| Field       | Type    | Null | Key | Default | Extra |

+-------------+---------+------+-----+---------+-------+

| employee_id | char(6) | NO   | PRI | NULL    |       |

| name        | char(8) | YES  | MUL | NULL    |       |

| sex         | char(2) | YES  |     | NULL    |       |

| birthday    | date    | YES  |     | NULL    |       |

+-------------+---------+------+-----+---------+-------+

4 rows in set (0.01 sec)



mysql> select *from employee;

+-------------+----------+------+------------+

| employee_id | name     | sex  | birthday   |

+-------------+----------+------+------------+

| 200301      | zhangsan | m    | 1978-05-08 |

| 200302      | lisi     | f    | 1973-03-20 |

| 200303      | wangwu   | f    | 1970-10-09 |

| 200304      | zhaoliu  | m    | 1975-01-18 |

+-------------+----------+------+------------+

4 rows in set (0.00 sec)



mysql>
*/
