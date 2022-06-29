#include "manager.h"

// Ĭ�Ϲ���
Manager::Manager()
{

}

// �вι���(����Ա����������)
Manager::Manager(string name, string pwd)
{
	this->name = name;
	this->pwd = pwd;

	// ��ʼ������
	this->initVector();
}

// ѡ��˵�
void Manager::operMenu()
{
	cout << "��ӭ����Ա��" << this->name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

// ����˺�  
void Manager::addPerson()
{
	cout << "����������˺ŵ�����" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl;

	string fileName;
	string tip;
	ofstream ofs;

	int select = 0;
	while (cin >> select)
	{
		if (select == 1 || select == 2)
		{
			break;
		}
		else
		{
			cout << "���������������������˺ŵ�����" << endl;
		}
	}

	string errorTip; // �ظ�������ʾ

	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ� ";
		errorTip = "ѧ���ظ�������������";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "������ְ����ţ�";
		errorTip = "ְ�����ظ�������������";
	}

	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;

	while (true)
	{
		cin >> id;

		bool ret = this->checkRepeat(id, select);

		if (ret) // ���ظ�
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}

	cout << "������������ " << endl;
	cin >> name;

	cout << "���������룺 " << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;

	system("pause");
	system("cls");

	ofs.close();

	// ��ʼ������
	this->initVector();
}

// �鿴�˺�
void Manager::showPerson()
{

}

// �鿴������Ϣ
void Manager::showComputer()
{

}

// ���ԤԼ��¼
void Manager::cleanFile()
{

}

// ��ʼ������
void Manager::initVector()
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
	vTea.clear();

	Student s;
	while (ifs >> s.id && ifs >> s.name && ifs >> s.pwd)
	{
		vStu.push_back(s);
	}
	ifs.close();

	// ��ȡ��ʦ�ļ���Ϣ
	ifs.open(TEACHER_FILE, ios::in);

	Teacher t;
	while (ifs >> t.empId && ifs >> t.name && ifs >> t.pwd)
	{
		vTea.push_back(t);
	}

	ifs.close();
}

// ����ظ� ����:(����id����������) ����ֵ��(true �������ظ���false����û���ظ�)
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->empId)
			{
				return true;
			}
		}
	}
	return false;
}