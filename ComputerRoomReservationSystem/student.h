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

// ѧ����
class Student: public Identity
{
public:
	// Ĭ�Ϲ���
	Student();

	// �вι���(ѧ�š�����������)
	Student(int id, string name, string pwd);

	// �˵�����
	virtual void operMenu();

	// ����ԤԼ
	void applyOrder();

	// �鿴�ҵ�ԤԼ
	void showMyOrder();

	// �鿴����ԤԼ
	void showAllOrder();

	// ȡ��ԤԼ
	void cancelOrder();

public:
	// ѧ��ѧ��
	int id;

	// ��������
	vector<ComputerRoom> vCom;
};