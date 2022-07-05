#pragma once
#define _CRT_SECURE_NO_WARNINGS // 忽视警告
#include <iostream>
#include <vector>
#include "Identity.h"
#include "orderFile.h"
using namespace std;

class Teacher: public Identity
{
public:
	// 默认构造
	Teacher();

	// 有参构造(职工编号，姓名，密码)
	Teacher(int empId, string name, string pwd);

	// 菜单界面
	virtual void operMenu();

	// 查看所有预约
	void showAllOrder();

	// 审核预约
	void validOrder();

	// 注销账号
	void deletePerson();

	// 初始化容器
	void initVector();

public:
	// 教师编号
	int empId; 

	// 教师容器
	vector<Teacher> vTea;

	// 账号是否被注销
	bool isExist;
};