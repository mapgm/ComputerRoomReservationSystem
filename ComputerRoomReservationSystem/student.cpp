#include "student.h"

// Ĭ�Ϲ���
Student::Student()
{

}

// �вι���(ѧ�š�����������)
Student::Student(int id, string name, string pwd)
{
	// ��ʼ������
	this->id = id;
	this->name = name;
	this->pwd = pwd;

	// ��ȡ������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.comId && ifs >> c.maxNum)
	{
		vCom.push_back(c);
	}

	ifs.close();
}

// �˵�����
void Student::operMenu()
{
	cout << "��ӭѧ������" << this->name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.����ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.ȡ��ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          5.ע���˺�              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.�˳���¼              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

// ����ԤԼ
void Student::applyOrder()
{
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;
	int date = 0;
	int interval = 0;
	int room = 0;

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "������������������" << endl;
	}


	cout << "����������ԤԼ��ʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "��ѡ�������" << endl;
	cout << "1�Ż���������" << vCom[0].maxNum << endl;
	cout << "2�Ż���������" << vCom[1].maxNum << endl;
	cout << "3�Ż���������" << vCom[2].maxNum << endl;

	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	OrderFile of;
	if (of.size != 0)
	{
		for (int i = 0; i < of.size; i++)
		{
			if (to_string(date) == of.m_orderData[i]["date"] && 
				to_string(interval) == of.m_orderData[i]["interval"] &&
				to_string(room) == of.m_orderData[i]["roomId"] &&
				to_string(2) == of.m_orderData[i]["status"])
			{
				cout << "��ʱ��λ����ѱ�ռ�ã�������ѡ��" << endl;
				system("pause");
				system("cls");
				return;
			}
		}
	}

	cout << "ԤԼ�ɹ��������" << endl;

	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->id << " ";
	ofs << "stuName:" << this->name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();

	system("pause");
	system("cls");
}

// �鿴�ҵ�ԤԼ
void Student::showMyOrder()
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
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->id)
		{
			cout << "ԤԼ���ڣ� ��" << of.m_orderData[i]["date"];
			cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
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
	}

	system("pause");
	system("cls");
}

// �鿴����ԤԼ
void Student::showAllOrder()
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

// ȡ��ԤԼ
void Student::cancelOrder()
{
	OrderFile of;
	if (of.size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;

	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.size; i++)
	{
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->id)
		{
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "�� ";
				cout << "ԤԼ���ڣ� ��" << of.m_orderData[i]["date"];
				cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
				cout << " ������" << of.m_orderData[i]["roomId"];
				string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ  -1 ԤԼʧ��
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				cout << status << endl;

			}
		}
	}

	cout << "������ȡ���ļ�¼,0������" << endl;
	int select = 0;
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
				of.m_orderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "��ȡ��ԤԼ" << endl;
				break;
			}

		}
		cout << "������������������" << endl;
	}

	system("pause");
	system("cls");
}

// ��ʼ������
void Student::initVector()
{
	// ��ȡѧ���ļ�����Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	vStu.clear();

	Student s;
	while (ifs >> s.id && ifs >> s.name && ifs >> s.pwd)
	{
		vStu.push_back(s);
	}

	ifs.close();
}

// ע���˺�
void Student::deletePerson()
{
	cout << "ȷ���Ƿ�ע�����˺ţ�" << endl;
	cout << "1. ȷ��" << endl;
	cout << "2. ȡ��" << endl;

	int select;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs;
		ofs.open(STUDENT_FILE, ios::out);
		for (vector<Student>::iterator iter = vStu.begin(); iter != vStu.end(); iter++)
		{
			if (iter->id == this->id)
			{
				continue;
			}
			else
			{
				ofs << iter->id << " " << iter->name << " " << pwd << endl;
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