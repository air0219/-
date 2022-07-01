#include<iostream>
#include<string>
#define MAX 100
using namespace std;

struct Person
{
	string name;
	bool sex;//1 �У�0 Ů
	int age;
	string number;
	string adr;
};
struct Addressbooks
{
	Person personArray[MAX];
	int m_size;
};

//1���˵�����
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
		case 1:		//  1�������ϵ��
			addPerson(&ads);
			break;
		case 2:		//  2����ʾ��ϵ��
			showPerson(&ads);
			break;
		case 3:		//  3��ɾ����ϵ��
			delPerson(&ads);
			break;
		case 4:		//  4��������ϵ��
			findPerson(&ads);
			break;
		case 5:		//  5���޸���ϵ��
			modifyPerson(&ads);
			break;
		case 6:		//  6�������ϵ��
			delAddressbooks(&ads);
			break;
		case 0:		//  0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ�ã�" << endl;
			return 0;
			break;
		}

	}
	
	return 0;
}

void showMenu()
{
	cout << "***********************" << endl;
	cout << "*****" << "1�������ϵ��" << "*****" << endl;
	cout << "*****" << "2����ʾ��ϵ��" << "*****" << endl;
	cout << "*****" << "3��ɾ����ϵ��" << "*****" << endl;
	cout << "*****" << "4��������ϵ��" << "*****" << endl;
	cout << "*****" << "5���޸���ϵ��" << "*****" << endl;
	cout << "*****" << "6�������ϵ��" << "*****" << endl;
	cout << "*****" << "0���˳�ͨѶ¼" << "*****" << endl;
	cout << "***********************" << endl;
}

void addPerson(Addressbooks * ads)
{
	if (ads->m_size == MAX)
	{
		cout << "ͨѶ¼������" << endl;
		return;
	}

	string name = "";
	cout << "������������" << endl;
	cin >> name;
	ads->personArray[ads->m_size].name = name;

	bool sex = 1;
	cout << "�������Ա�0--Ů��1--�У���" << endl;
	cin >> sex;
	ads->personArray[ads->m_size].sex = sex;

	int age = 0;
	while (1)
	{
		cout << "���������䣺" << endl;
		cin >> age;
		if (age > 0 && age < 150)
		{
			ads->personArray[ads->m_size].age = age;
			break;
		}
		else
			cout << "�������������..." << endl;
	}
	

	string number = "";
	cout << "������绰���룺" << endl;
	cin >> number;
	ads->personArray[ads->m_size].number = number;

	string adr = "";
	cout << "�������ַ��" << endl;
	cin >> adr;
	ads->personArray[ads->m_size].adr = adr;

	ads->m_size++;
	cout << "��ӳɹ�" << endl;
	system("cls");
	return;
}

void showPerson(Addressbooks *ads)
{
	if (ads->m_size == 0)
	{
		cout << "��ǰͨ��¼Ϊ�գ��������ϵ��..." << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		for (int i = 0; i < ads->m_size; i++)
		{
			cout << "������" << ads->personArray[i].name << "\t"
				<< "�Ա�" << (ads->personArray[i].sex == 1 ? "��" : "Ů") << "\t"
				<< "���䣺" << ads->personArray[i].age << "\t"
				<< "�绰���룺" << ads->personArray[i].number << "\t"
				<< "��ַ��" << ads->personArray[i].adr << "\t" << endl;
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
		cout << "ͨѶ¼Ϊ�գ����������ϵ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	string name = "";
	cout << "��������ɾ��������" << endl;
	cin >> name;
	if (isExist(ads, name) == -1)
		cout << "���޴���" << endl;
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
		cout << "ɾ���ɹ�" << endl;
	}
	system("pause");
	system("cls");
	return;
}

void findPerson(Addressbooks *ads)
{
	if (ads->m_size == 0)
	{
		cout << "ͨѶ¼Ϊ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		string name = "";
		cout << "������Ҫ���ҵ�����" << endl;
		cin >> name;
		if (isExist(ads, name) == -1)
			cout << "���޴���..." << endl;
		else
		{
			int i = isExist(ads, name);
			cout << "������" << ads->personArray[i].name << "\t"
				<< "�Ա�" << (ads->personArray[i].sex == 1 ? "��" : "Ů") << "\t"
				<< "���䣺" << ads->personArray[i].age << "\t"
				<< "�绰���룺" << ads->personArray[i].number << "\t"
				<< "��ַ��" << ads->personArray[i].adr << "\t" << endl;
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
		cout << "ͨѶ¼Ϊ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "������Ҫ�޸ĵ�����..." << endl;
	string name = "";
	cin >> name;
	int a = isExist(ads, name);
	if (a == -1)
	{
		cout << "���޴���" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "������" << ads->personArray[a].name << "\t"
			<< "�Ա�" << (ads->personArray[a].sex == 1 ? "��" : "Ů") << "\t"
			<< "���䣺" << ads->personArray[a].age << "\t"
			<< "�绰���룺" << ads->personArray[a].number << "\t"
			<< "��ַ��" << ads->personArray[a].adr << "\t" << endl;
		int b = 0;
		cout << "���������\n1������   2���Ա�   3������   4���绰����   5����ַ   -1:�˳��޸�"<<endl;
		while (b!=-1)
		{
			cin >> b;
			switch (b)
			{
			case 1:
			{
				string name;
				cout << "�������µ����֣�" << endl;
				cin >> name;
				ads->personArray[a].name = name;
				cout << "�޸ĳɹ����������������" << endl;
			}
				continue;
			case 2:
			{
				bool sex;
				cout << "�������µ��Ա�" << endl;
				cin >> sex;
				ads->personArray[a].sex = sex;
				cout << "�޸ĳɹ����������������" << endl;
			}
				continue;
			case 3:
			{
				int age;
				cout << "�������µ����䣺" << endl;
				cin >> age;
				ads->personArray[a].age = age;
				cout << "�޸ĳɹ����������������" << endl;
			}
				continue;
			case 4:
			{
				string number;
				cout << "�������µĵ绰���룺" << endl;
				cin >> number;
				ads->personArray[a].number = number;
				cout << "�޸ĳɹ����������������" << endl;
			}
				continue;
			case 5:
			{
				string adr;
				cout << "�������µĵ�ַ��" << endl;
				cin >> adr;
				ads->personArray[a].adr = adr;
				cout << "�޸ĳɹ����������������" << endl;
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

void delAddressbooks(Addressbooks *ads)
{
	ads->m_size = 0;
	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
	return;
}