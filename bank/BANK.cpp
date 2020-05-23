#include <iostream>
using namespace std;
#define NAME_LEN 20

typedef struct
{
	int accID;//���¹�ȣ
	int balance;//�ܾ�
	char cusName[NAME_LEN]; //���̸�
}Account;

Account bankarr[100];
int index = 0;

void printMenu()
{
	cout << "-----menu-----" << endl;
	cout << "1.���� ����" << endl;
	cout << "2.��     ��" << endl;
	cout << "3.��     ��" << endl;
	cout << "4.�������� ��ü ���" << endl;
	cout << "5.���α׷� ����" << endl;
} //menu ���
int makeacc()
{
	int accID;
	char cusName[NAME_LEN];
	int balance;

	cout << "[���°���]" << endl;
	cout << "����ID: "; cin >> accID;
	cout << "��  ��:"; cin >> cusName;
	cout << "�Աݾ� :"; cin >> balance;

	if (balance < 10)
	{
		cout << "���°��� �ÿ��� 10�� �̻��� �Աݾ��� �־�� �մϴ�.\n" << endl;
	}
	strcpy_s(bankarr[index].cusName, cusName);
	bankarr[index].accID = accID;
	bankarr[index].balance = balance;
	for (int i = 0; i < index; i++)
	{
		if (bankarr[i].accID == accID)
		{
			cout << "�̹� �ִ� ���� ID�Դϴ�. \n�ٸ� ����ID�� �Է����ּ���" << endl;
			accID = NULL;
			balance = NULL;
			cusName[0] = NULL;
			index--;

		}
	}
	index++;
}//���°���

void deposit()
{
	int money;
	int id;

	cout << "[��    ��]" << endl;
	cout << "����ID:", cin >> id;
	cout << "�Աݾ�:"; cin >> money;

	for (int i = 0; i < index; i++)
	{
		if (bankarr[i].accID == id)
		{
			bankarr[i].balance += money;
			return;
		}
	}
	cout << "�������� �ʴ� ID�Դϴ�." << endl;
}//�Ա�
void withdraw()
{
	int money;
	int id;

	cout << "���� ID:"; cin >> id;
	cout << "��ݾ�:"; cin >> money;

	for (int i = 0; i < index; i++)
	{
		if (bankarr[i].accID == id)
		{
			if (bankarr[i].balance < money)
			{
				bankarr[i].balance += money;
				cout << "��� �ݾ��� ���� �ܾ׺��� �����ϴ�" << endl;
				return;
			}
			else
			{
				bankarr[i].balance -= money;
				return;
			}
		}
	}
	cout << "��ȿ���� ���� ID�Դϴ�." << endl;
}//���

void check_acc()
{
	for (int i = 0; i < index; i++)
	{
		cout << "���� ID: " << bankarr[i].accID << endl;
		cout << "��  ��:" << bankarr[i].cusName << endl;
		cout << "��  ��:" << bankarr[i].balance << endl;
	}
}
int main(void)
{
	int choice;
	while (1)
	{
		printMenu();
		cout << "����:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			makeacc();
			break;
		case 2:
			deposit();
			break;
		case 3:
			withdraw();
			break;
		case 4:
			check_acc();
			break;
		case 5:
			return 0;
			break;
		default:
			cout << "���� �����Դϴ�" << endl;
			break;
		}
	}
}
