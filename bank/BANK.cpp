#include <iostream>
#include <cstring>
using namespace std;
#define NAME_LEN 20
#define ID_LEN 15

class Account
{
public:
	Account(int scan_accID, int scan_balance, char * scan_cusName, const char * scan_ID_card_number) {
		this->accID = scan_accID;
		this->balance = scan_balance;
		this->cusName = new char[NAME_LEN];
		strcpy(cusName, scan_cusName);
		char* cin_ID_card_number = new char[ID_LEN];
		strcpy(cin_ID_card_number, scan_ID_card_number);
		ID_card_number = cin_ID_card_number;
	}

	Account(const Account& ref) { //������ ���� ������
		this->accID = ref.accID;
		this->balance = ref.balance;
		this->cusName = new char[NAME_LEN];
		strcmp(this->cusName, ref.cusName);
		this->ID_card_number = new char[ID_LEN];
		strcmp(this->ID_card_number, ref.ID_card_number);
		cout << "��������� ȣ��" << endl;
	}

	~Account() {
		if(cusName != nullptr) delete cusName;
		if (ID_card_number != nullptr) delete ID_card_number;
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
		int interest = (int)((double)(balance + money) * 0.01);
		balance = balance + money + interest;
		cout << "������� ���ھ� : " << interest << endl;
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

	const char* getID_card_number()
	{
		return  ID_card_number;
	}
protected:
	int accID;//���¹�ȣ
	int balance;//�ܾ�
	char *cusName = nullptr; //���̸�
	const char *ID_card_number = nullptr; //�ֹε�Ϲ�ȣ //cosnt����
};

class SavingAccount : public Account 
{
public:
	SavingAccount(int scan_accID, int scan_balance, char* scan_cusName, const char* scan_ID_card_number) : Account(scan_accID, scan_balance, scan_cusName, scan_ID_card_number)
	{

	}

	~SavingAccount()
	{

	}

	void deposit(int money)
	{
		int interest = (int)((double)(balance + money) * 0.02);
		balance = balance + money + interest;
		cout << "���ݰ��� ���ھ� : " << interest << endl;
	}

	
	
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

	int bankCheck(int accID, int type)
	{
		if (type == 1)
		{
			for (int i = 0; i < index; i++)
			{
				if (bankarr[i]->getaccID() == accID)
				{
					return i;
				}
			}
		}
		else {
			for (int i = 0; i < index; i++)
			{
				if (savebankarr[i]->getaccID() == accID)
				{
					return i;
				}
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
	void makeAcc()
	{
		int select_menu;
		cout << "���� 1, ���� 2" << endl << "�Է�";
		cin >> select_menu;
		if (select_menu == 1)
		{
			makeOrdinaryAcc();
		}
		else {
			makeSavingAcc();
		}
	}
	void makeOrdinaryAcc()
	{
		int accID;
		int balance;
		char* cusName = new char[NAME_LEN];
		char* ID_card_number = new char[ID_LEN];

		cout << "[������°���]" << endl;
		cout << "����ID: "; cin >> accID;
		cout << "��  ��: "; cin >> cusName;
		cout << "�Աݾ� : "; cin >> balance;
		cout << "�ֹι�ȣ : "; cin >> ID_card_number;

		if (balance < 10)
		{
			cout << "���°��� �ÿ��� 10�� �̻��� �Աݾ��� �־�� �մϴ�.\n" << endl;
			return;
		}

		if (bankCheck(accID, 1) != -1) {
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

	void makeSavingAcc()
	{
		int accID;
		int select_accID;

		cout << "[���ݰ��°���]" << endl;
		cout << "���� ����ID: "; cin >> accID;

		select_accID = bankCheck(accID, 1);

		if (select_accID == -1) {
			cout << "���� ���°� �������� �ʽ��ϴ�." << endl;
			return;
		}

		cout << "�� ����ID: "; cin >> accID;

		if (bankCheck(accID, 1) != -1) {
			cout << "�ߺ��� ���� ��ȣ" << endl;
			return;
		}

		if (bankCheck(accID, 2) != -1) {
			cout << "�ߺ��� ���� ��ȣ" << endl;
		}

		savebankarr[saveindex++] = new SavingAccount(accID, 0, bankarr[select_accID]->getcusName(), bankarr[select_accID]->getID_card_number());
	}//���°���


	void deposit()
	{
		if (know_people() == true) return;

		int money;
		int id;
		int id_idx;
		int acc_type = 1;

		cout << "[��    ��]" << endl;
		cout << "����ID: "; cin >> id;
		cout << "�Աݾ�: "; cin >> money;

		if (money <= 0) {
			cout << "�ּ� 1�� �̻� �־��ּ���" << endl;
			return;
		}

		id_idx = bankCheck(id, 1);
		if (id_idx == -1) {
			id_idx = bankCheck(id, 2);
			acc_type = 2;
		}

		if (id_idx != -1)
		{
			if(acc_type == 1)
				bankarr[id_idx]->deposit(money);
			else
				savebankarr[id_idx]->deposit(money);
			return;
		}
		cout << "��ȿ���� �ʴ� ID�Դϴ�." << endl;
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

		id_idx = bankCheck(id, 1);
		//���� ���´� ��� ���� ����

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
		cout << "��ȿ���� �ʴ� ID�Դϴ�." << endl;
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
	SavingAccount* savebankarr[100];
	int saveindex = 0;
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
			accManager->makeAcc();
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
