#include<iostream>
#include<string>
#define MAX 100
using namespace std;

struct Person
{
	string name;
	bool sex;//1 男，0 女
	int age;
	string number;
	string adr;
};
struct Addressbooks
{
	Person personArray[MAX];
	int m_size;
};

//1、菜单界面
void showMenu();
void addPerson(Addressbooks *ads);
void showPerson(Addressbooks *ads);
int isExist(Addressbooks *ads, string name);
void delPerson(Addressbooks *ads);
void findPerson(Addressbooks *ads);
void modifyPerson(Addressbooks *ads);
void delAddressbooks(Addressbooks *ads);

int main()
{
	Addressbooks ads;
	ads.m_size = 0;
	while(true)
	{
		int select = 0;
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:		//  1、添加联系人
			addPerson(&ads);
			break;
		case 2:		//  2、显示联系人
			showPerson(&ads);
			break;
		case 3:		//  3、删除联系人
			delPerson(&ads);
			break;
		case 4:		//  4、查找联系人
			findPerson(&ads);
			break;
		case 5:		//  5、修改联系人
			modifyPerson(&ads);
			break;
		case 6:		//  6、清空联系人
			delAddressbooks(&ads);
			break;
		case 0:		//  0、退出通讯录
			cout << "欢迎下次使用！" << endl;
			return 0;
			break;
		}

	}
	
	return 0;
}

void showMenu()
{
	cout << "***********************" << endl;
	cout << "*****" << "1、添加联系人" << "*****" << endl;
	cout << "*****" << "2、显示联系人" << "*****" << endl;
	cout << "*****" << "3、删除联系人" << "*****" << endl;
	cout << "*****" << "4、查找联系人" << "*****" << endl;
	cout << "*****" << "5、修改联系人" << "*****" << endl;
	cout << "*****" << "6、清空联系人" << "*****" << endl;
	cout << "*****" << "0、退出通讯录" << "*****" << endl;
	cout << "***********************" << endl;
}

void addPerson(Addressbooks * ads)
{
	if (ads->m_size == MAX)
	{
		cout << "通讯录已满！" << endl;
		return;
	}

	string name = "";
	cout << "请输入姓名：" << endl;
	cin >> name;
	ads->personArray[ads->m_size].name = name;

	bool sex = 1;
	cout << "请输入性别（0--女，1--男）：" << endl;
	cin >> sex;
	ads->personArray[ads->m_size].sex = sex;

	int age = 0;
	while (1)
	{
		cout << "请输入年龄：" << endl;
		cin >> age;
		if (age > 0 && age < 150)
		{
			ads->personArray[ads->m_size].age = age;
			break;
		}
		else
			cout << "年龄错误，请重试..." << endl;
	}
	

	string number = "";
	cout << "请输入电话号码：" << endl;
	cin >> number;
	ads->personArray[ads->m_size].number = number;

	string adr = "";
	cout << "请输入地址：" << endl;
	cin >> adr;
	ads->personArray[ads->m_size].adr = adr;

	ads->m_size++;
	cout << "添加成功" << endl;
	system("cls");
	return;
}

void showPerson(Addressbooks *ads)
{
	if (ads->m_size == 0)
	{
		cout << "当前通信录为空，请添加联系人..." << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		for (int i = 0; i < ads->m_size; i++)
		{
			cout << "姓名：" << ads->personArray[i].name << "\t"
				<< "性别：" << (ads->personArray[i].sex == 1 ? "男" : "女") << "\t"
				<< "年龄：" << ads->personArray[i].age << "\t"
				<< "电话号码：" << ads->personArray[i].number << "\t"
				<< "地址：" << ads->personArray[i].adr << "\t" << endl;
		}
		system("pause");
		system("cls");
		return;
	}
}

int isExist(Addressbooks *ads, string name)
{
	for (int i = 0; i < ads->m_size; i++)
	{
		if (ads->personArray[i].name == name)
			return i;
	}
	return -1;
}

void delPerson(Addressbooks *ads)
{
	if (ads->m_size == 0)
	{
		cout << "通讯录为空，请先添加联系人" << endl;
		system("pause");
		system("cls");
		return;
	}
	string name = "";
	cout << "请输入需删除的姓名" << endl;
	cin >> name;
	if (isExist(ads, name) == -1)
		cout << "查无此人" << endl;
	else
	{
		int a = isExist(ads, name);
		for (int i = a; i < (ads->m_size); i++)
		{
			ads->personArray[i].adr = ads->personArray[i + 1].adr;
			ads->personArray[i].age = ads->personArray[i + 1].age;
			ads->personArray[i].name = ads->personArray[i + 1].name;
			ads->personArray[i].number = ads->personArray[i + 1].number;
			ads->personArray[i].sex = ads->personArray[i + 1].sex;
		}
		ads->m_size--;
		cout << "删除成功" << endl;
	}
	system("pause");
	system("cls");
	return;
}

void findPerson(Addressbooks *ads)
{
	if (ads->m_size == 0)
	{
		cout << "通讯录为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		string name = "";
		cout << "请输入要查找的姓名" << endl;
		cin >> name;
		if (isExist(ads, name) == -1)
			cout << "查无此人..." << endl;
		else
		{
			int i = isExist(ads, name);
			cout << "姓名：" << ads->personArray[i].name << "\t"
				<< "性别：" << (ads->personArray[i].sex == 1 ? "男" : "女") << "\t"
				<< "年龄：" << ads->personArray[i].age << "\t"
				<< "电话号码：" << ads->personArray[i].number << "\t"
				<< "地址：" << ads->personArray[i].adr << "\t" << endl;
		}
		system("pause");
		system("cls");
		return;
	}
}

void modifyPerson(Addressbooks *ads)
{
	if (ads->m_size == 0)
	{
		cout << "通讯录为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "请输入要修改的姓名..." << endl;
	string name = "";
	cin >> name;
	int a = isExist(ads, name);
	if (a == -1)
	{
		cout << "查无此人" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "姓名：" << ads->personArray[a].name << "\t"
			<< "性别：" << (ads->personArray[a].sex == 1 ? "男" : "女") << "\t"
			<< "年龄：" << ads->personArray[a].age << "\t"
			<< "电话号码：" << ads->personArray[a].number << "\t"
			<< "地址：" << ads->personArray[a].adr << "\t" << endl;
		int b = 0;
		cout << "请输入类别：\n1：姓名   2：性别   3：年龄   4：电话号码   5：地址   -1:退出修改"<<endl;
		while (b!=-1)
		{
			cin >> b;
			switch (b)
			{
			case 1:
			{
				string name;
				cout << "请输入新的名字：" << endl;
				cin >> name;
				ads->personArray[a].name = name;
				cout << "修改成功，请重新输入类别：" << endl;
			}
				continue;
			case 2:
			{
				bool sex;
				cout << "请输入新的性别：" << endl;
				cin >> sex;
				ads->personArray[a].sex = sex;
				cout << "修改成功，请重新输入类别：" << endl;
			}
				continue;
			case 3:
			{
				int age;
				cout << "请输入新的年龄：" << endl;
				cin >> age;
				ads->personArray[a].age = age;
				cout << "修改成功，请重新输入类别：" << endl;
			}
				continue;
			case 4:
			{
				string number;
				cout << "请输入新的电话号码：" << endl;
				cin >> number;
				ads->personArray[a].number = number;
				cout << "修改成功，请重新输入类别：" << endl;
			}
				continue;
			case 5:
			{
				string adr;
				cout << "请输入新的地址：" << endl;
				cin >> adr;
				ads->personArray[a].adr = adr;
				cout << "修改成功，请重新输入类别：" << endl;
			}
				continue;
			default:
				continue;
			}
		}
		system("cls");
		return;
	}
}
//清空通讯录函数
void delAddressbooks(Addressbooks *ads)
{
	ads->m_size = 0;
	cout << "清空成功" << endl;
	system("pause");
	system("cls");
	return;
}