#include <iostream>
#include <cstring>
using namespace std;
#define NAME_LEN 20
#define ID_LEN 15

class Account
{
public:
	Account(int accID, int balance, char *cusName, char *ID_card_number) {
		this->accID = accID;
		this->balance = balance;
		this->cusName = cusName;
		this->ID_card_number = ID_card_number;
	}
	Account(const Account& ref) { //������ ���� ������
		this->accID = ref.accID;
		this->balance = ref.balance;
		this->cusName = ref.cusName;
		this->ID_card_number = ref.ID_card_number;
		cout << "��������� ȣ��" << endl;
	}

	~Account() {
		delete cusName;
		delete ID_card_number;
	}
	void check_acc()
	{
		cout << "���� ID: " << accID << endl;
		cout << "��  ��:" << cusName << endl;
		cout << "��  ��:" << balance << endl;
		cout << "�ֹι�ȣ:" << ID_card_number << endl << endl;
	}

	void deposit(int money)
	{
		balance += money;
	}

	void withdraw(int money)
	{
		balance -= money;
	}
	

	
	int getaccID()
	{
		return accID;
	}
	int getbalance()
	{
		return balance;
	}
	char* getcusName()
	{
		return cusName;
	}
private:
	int accID;//���¹�ȣ
	int balance;//�ܾ�
	char *cusName; //���̸�
	const char *ID_card_number; //�ֹε�Ϲ�ȣ //cosnt����
};


class AccountManager
{
public:
	void printMenu()
	{
		cout << "-----menu-----" << endl;
		cout << "1.���� ����" << endl;
		cout << "2.��     ��" << endl;
		cout << "3.��     ��" << endl;
		cout << "4.�������� ��ü ���" << endl;
		cout << "5.���α׷� ����" << endl;
	} //menu ���

	int bankCheck(int accID)
	{
		for (int i = 0; i < index; i++)
		{
			if (bankarr[i]->getaccID() == accID)
			{
				return i;
			}
		}
		return -1;
	}

	bool know_people()
	{
		if (index == 0) {
			cout << "���࿡ ���Ե� ���°� �����ϴ�." << endl;
			return true;
		}
		return false;
	}
	void makeacc()
	{
		int accID;
		int balance;
		char* cusName = new char[NAME_LEN];
		char* ID_card_number = new char[ID_LEN];

		cout << "[���°���]" << endl;
		cout << "����ID: "; cin >> accID;
		cout << "��  ��: "; cin >> cusName;
		cout << "�Աݾ� : "; cin >> balance;
		cout << "�ֹι�ȣ : "; cin >> ID_card_number;

		if (balance < 10)
		{
			cout << "���°��� �ÿ��� 10�� �̻��� �Աݾ��� �־�� �մϴ�.\n" << endl;
			return;
		}

		if (bankCheck(accID) != -1) {
			cout << "�̹� �ִ� ���� ID�Դϴ�. \n�ٸ� ����ID�� �Է����ּ���" << endl;
			return;
		}

		for (int i = 0; i < index; i++)
		{
			if (strcmp(bankarr[i]->getcusName(), ID_card_number) == 0)
			{
				cout << "�̹� �ִ� �ֹι�ȣ �Դϴ�. \n�ٸ� �ֹι�ȣ�� �Է����ּ���" << endl;
				return;
			}
		}

		bankarr[index++] = new Account(accID, balance, cusName, ID_card_number);
	}//���°���

	void deposit()
	{
		if (know_people() == true) return;

		int money;
		int id;
		int id_idx;

		cout << "[��    ��]" << endl;
		cout << "����ID: "; cin >> id;
		cout << "�Աݾ�: "; cin >> money;

		if (money <= 0) {
			cout << "�ּ� 1�� �̻� �־��ּ���" << endl;
			return;
		}

		id_idx = bankCheck(id);

		if (id_idx != -1)
		{
			bankarr[id_idx]->deposit(money);
			return;
		}
		cout << "�������� �ʴ� ID�Դϴ�." << endl;
	}//�Ա�

	void withdraw()
	{
		if (know_people() == true) return;

		int money;
		int id;
		int id_idx;

		cout << "[��    ��]" << endl;
		cout << "����ID: "; cin >> id;
		cout << "�Աݾ�: "; cin >> money;

		if (money <= 0) {
			cout << "�ּ� 1�� �̻� ���ּ���" << endl;
			return;
		}

		id_idx = bankCheck(id);

		if (id_idx != -1)
		{
			if (bankarr[id_idx]->getbalance() < money)
			{
				cout << "��� �ݾ��� ���� �ܾ׺��� �����ϴ�" << endl;
				return;
			}
			bankarr[id_idx]->withdraw(money);
			return;
		}
		cout << "�������� �ʴ� ID�Դϴ�." << endl;
	}//���

	void check_acc()
	{
		if (know_people() == true) return;

		for (int i = 0; i < index; i++)
		{
			bankarr[i]->check_acc();
		}
	}
private:
	Account* bankarr[100];
	int index = 0;
};

int main(void)
{
	AccountManager* accManager = new AccountManager;
	int choice;
	while (1)
	{
		accManager->printMenu();
		cout << "����:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			accManager->makeacc();
			break;
		case 2:
			accManager->deposit();
			break;
		case 3:
			accManager->withdraw();
			break;
		case 4:
			accManager->check_acc();
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
