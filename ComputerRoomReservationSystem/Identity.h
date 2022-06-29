#pragma once
#include <iostream>
#include <string>
using namespace std;

// 身份抽象类
class Identity
{
public:
	virtual void operMenu() = 0;

public:
	// 用户名
	string name;

	// 密码
	string pwd;
};