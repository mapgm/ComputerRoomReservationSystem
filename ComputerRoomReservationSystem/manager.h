#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Identity.h"
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "computerRoom.h"
using namespace std;

class Manager: public Identity
{
public:
	// Ĭ�Ϲ���
	Manager();

	// �вι���(����Ա����������)
	Manager(string name, string pwd);

	// ѡ��˵�
	virtual void operMenu();

	// ����˺�  
	void addPerson();

	// �鿴�˺�
	void showPerson();

	// �鿴������Ϣ
	void showComputer();

	// ���ԤԼ��¼
	void cleanFile();

	// ��ʼ������
	void initVector();

	// ����ظ� ����:(����id����������) ����ֵ��(true �������ظ���false����û���ظ�)
	bool checkRepeat(int id, int type);

public:
	// ѧ������
	vector<Student> vStu;

	// ��ʦ����
	vector<Teacher> vTea;

	// ��������
	vector<ComputerRoom> vCom;
};