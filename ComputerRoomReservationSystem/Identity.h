#pragma once
#include <iostream>
#include <string>
using namespace std;

// ��ݳ�����
class Identity
{
public:
	virtual void operMenu() = 0;

public:
	// �û���
	string name;

	// ����
	string pwd;
};