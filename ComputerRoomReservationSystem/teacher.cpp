#include "teacher.h"

// Ĭ�Ϲ���
Teacher::Teacher()
{

}

// �вι���(ְ����ţ�����������)
Teacher::Teacher(int empId, string name, string pwd)
{
	// ��ʼ������
	this->empId = empId;
	this->name = name;
	this->pwd = pwd;
}

// �˵�����
void Teacher::operMenu()
{
	cout << "��ӭ��ʦ��" << this->name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.���ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          3.ע���˺�              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.�˳���¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

// �鿴����ԤԼ
void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.size; i++)
	{
		cout << i + 1 << "�� ";

		cout << "ԤԼ���ڣ� ��" << of.m_orderData[i]["date"];
		cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
		cout << " ѧ�ţ�" << of.m_orderData[i]["stuId"];
		cout << " ������" << of.m_orderData[i]["stuName"];
		cout << " ������" << of.m_orderData[i]["roomId"];
		string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ -1 ԤԼʧ��
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "���δͨ����ԤԼʧ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}

	system("pause");
	system("cls");
}

// ���ԤԼ
void Teacher::validOrder()
{
	OrderFile of;
	if (of.size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˵�ԤԼ��¼���£�" << endl;

	vector<int> v;
	int index = 0;
	for (int i = 0; i < of.size; i++)
	{
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "�� ";
			cout << "ԤԼ���ڣ� ��" << of.m_orderData[i]["date"];
			cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << " ������" << of.m_orderData[i]["roomId"];
			string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ  -1 ԤԼʧ��
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			cout << status << endl;
		}
	}
	cout << "��������˵�ԤԼ��¼, 0������" << endl;
	int select = 0;
	int ret = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "��������˽��" << endl;
				cout << "1��ͨ��" << endl;
				cout << "2����ͨ��" << endl;
				cin >> ret;

				if (ret == 1)
				{
					of.m_orderData[v[select - 1]]["status"] = "2";
				}
				else
				{
					of.m_orderData[v[select - 1]]["status"] = "-1";
				}
				of.updateOrder();
				cout << "�����ϣ�" << endl;
				break;
			}
		}
		cout << "������������������" << endl;
	}

	system("pause");
	system("cls");
}

// ע���˺�
void Teacher::deletePerson()
{
	cout << "ȷ���Ƿ�ע�����˺ţ�" << endl;
	cout << "1. ȷ��" << endl;
	cout << "2. ȡ��" << endl;

	int select;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs;
		ofs.open(TEACHER_FILE, ios::out);
		for (vector<Teacher>::iterator iter = vTea.begin(); iter != vTea.end(); iter++)
		{
			if (iter->empId == this->empId)
			{
				continue;
			}
			else
			{
				ofs << iter->empId << " " << iter->name << " " << pwd << endl;
			}
		}

		ofs.close();
		this->isExist = true;
		cout << "ע���ɹ���" << endl;

		system("pause");
		system("cls");

		// ��ʼ������
		this->initVector();
	}
	else
	{
		system("pause");
		system("cls");
	}
}

// ��ʼ������
void Teacher::initVector()
{
	// ��ȡ��ʦ�ļ�����Ϣ
	ifstream ifs;
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	vTea.clear();

	Teacher s;
	while (ifs >> s.empId && ifs >> s.name && ifs >> s.pwd)
	{
		vTea.push_back(s);
	}

	ifs.close();
}