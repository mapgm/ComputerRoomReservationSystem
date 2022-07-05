#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Identity.h"
#include "computerRoom.h"
#include "globalFile.h"
#include "orderFile.h"
using namespace std;

// 学生类
class Student: public Identity
{
public:
	// 默认构造
	Student();

	// 有参构造(学号、姓名、密码)
	Student(int id, string name, string pwd);

	// 菜单界面
	virtual void operMenu();

	// 申请预约
	void applyOrder();

	// 查看我的预约
	void showMyOrder();

	// 查看所有预约
	void showAllOrder();

	// 取消预约
	void cancelOrder();

	// 注销账号
	void deletePerson();

	// 初始化容器
	void initVector();

public:
	// 学生学号
	int id;

	// 机房容器
	vector<ComputerRoom> vCom;

	// 学生容器
	vector<Student> vStu;

	// 账号是否被注销
	bool isExist;
};