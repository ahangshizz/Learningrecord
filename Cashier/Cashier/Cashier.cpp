// Cashier.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <WinSock2.h>
#include <mysql.h>
#include "MySQL.h"

int main()
{
	MySQL mysql;
	mysql.ConnectionMySql("127.0.0.1", "root", "", "scott");
	string str = "select * from dept;";
	vector<vector<string>> v= mysql.Select(str);
	for (auto e : v) {
		for (auto it : e) {
			cout << it << "  ";
		}
		cout << endl;
	}
}

