#include "manager.h"

// 打印学生信息
void printStudent(Student& s)
{
	cout << "学号： " << s.id << " 姓名： " << s.name << " 密码：" << s.pwd << endl;
}

// 打印老师信息
void printTeacher(Teacher& t)
{
	cout << "职工号： " << t.empId << " 姓名： " << t.name << " 密码：" << t.pwd << endl;
}

// 默认构造
Manager::Manager()
{

}

// 有参构造(管理员姓名，密码)
Manager::Manager(string name, string pwd)
{
	this->name = name;
	this->pwd = pwd;

	// 初始化容器
	this->initVector();

	// 获取机房信息
	ifstream ifs;

	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.comId && ifs >> c.maxNum)
	{
		vCom.push_back(c);
	}

	ifs.close();
}

// 选择菜单
void Manager::operMenu()
{
	cout << "欢迎管理员：" << this->name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.删除账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          5.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

// 添加账号  
void Manager::addPerson()
{
	cout << "请输入添加账号的类型" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加老师" << endl;

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
			cout << "输入错误，请重新输入添加账号的类型" << endl;
		}
	}

	string errorTip; // 重复错误提示

	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "请输入学号： ";
		errorTip = "学号重复，请重新输入";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "请输入职工编号：";
		errorTip = "职工号重复，请重新输入";
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

		if (ret) // 有重复
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}

	cout << "请输入姓名： " << endl;
	cin >> name;

	cout << "请输入密码： " << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;

	system("pause");
	system("cls");

	ofs.close();

	// 初始化容器
	this->initVector();
}

// 查看账号
void Manager::showPerson()
{
	cout << "请选择查看内容：" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "2、查看所有老师" << endl;

	int select = 0;

	cin >> select;

	if (select == 1)
	{
		cout << "所有学生信息如下： " << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		cout << "所有老师信息如下： " << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

// 查看机房信息
void Manager::showComputer()
{
	cout << "机房信息如下： " << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "机房编号： " << it->comId << " 机房最大容量： " << it->maxNum << endl;
	}
	system("pause");
	system("cls");
}

// 清空预约记录
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}

// 初始化容器
void Manager::initVector()
{
	// 读取学生文件中信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
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

	// 读取老师文件信息
	ifs.open(TEACHER_FILE, ios::in);

	Teacher t;
	while (ifs >> t.empId && ifs >> t.name && ifs >> t.pwd)
	{
		vTea.push_back(t);
	}

	ifs.close();
}

// 检测重复 参数:(传入id，传入类型) 返回值：(true 代表有重复，false代表没有重复)
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

// 删除学生/老师账号
void Manager::deletePerson()
{
	cout << "请输入删除账号的类型" << endl;
	cout << "1、删除学生" << endl;
	cout << "2、删除老师" << endl;

	string fileName;
	string tip;

	int select = 0;
	while (cin >> select)
	{
		if (select == 1 || select == 2)
		{
			break;
		}
		else
		{
			cout << "输入错误，请重新输入删除账号的类型" << endl;
		}
	}

	string errorTip; // 重复错误提示

	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "请输入删除的学生的学号： ";
		errorTip = "学号不存在，请重新输入";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "请输入删除的职工的编号：";
		errorTip = "职工号不存在，请重新输入";
	}

	int id;
	cout << tip << endl;

	while (true)
	{
		cin >> id;

		bool ret = this->checkRepeat(id, select);

		if (ret) // 存在该号码
		{
			break;
		}
		else
		{
			cout << errorTip << endl;
		}
	}

	ofstream ofs;
	ofs.open(fileName, ios::out);
	if (select == 1)
	{
		for (vector<Student>::iterator iter = vStu.begin(); iter != vStu.end(); iter++)
		{
			if (iter->id == id)
			{
				continue;
			}
			else
			{
				ofs << iter->id << " " << iter->name << " " << pwd << endl;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator iter = vTea.begin(); iter != vTea.end(); iter++)
		{
			if (iter->empId == id)
			{
				continue;
			}
			else
			{
				ofs << iter->empId << " " << iter->name << " " << pwd << endl;
			}
		}
	}

	ofs.close();
	cout << "删除成功！" << endl;

	system("pause");
	system("cls");

	// 初始化容器
	this->initVector();
}