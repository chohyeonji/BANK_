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
	Account(const Account& ref) { //디폴드 복사 생성자
		this->accID = ref.accID;
		this->balance = ref.balance;
		this->cusName = ref.cusName;
		this->ID_card_number = ref.ID_card_number;
		cout << "복사생성자 호출" << endl;
	}

	~Account() {
		delete cusName;
		delete ID_card_number;
	}
	void check_acc()
	{
		cout << "계좌 ID: " << accID << endl;
		cout << "이  름:" << cusName << endl;
		cout << "잔  액:" << balance << endl;
		cout << "주민번호:" << ID_card_number << endl << endl;
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
	int accID;//계좌번호
	int balance;//잔액
	char *cusName; //고객이름
	const char *ID_card_number; //주민등록번호 //cosnt선언
};


class AccountManager
{
public:
	void printMenu()
	{
		cout << "-----menu-----" << endl;
		cout << "1.계좌 개설" << endl;
		cout << "2.입     금" << endl;
		cout << "3.출     금" << endl;
		cout << "4.계좌정보 전체 출력" << endl;
		cout << "5.프로그램 종료" << endl;
	} //menu 출력

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
			cout << "은행에 가입된 계좌가 없습니다." << endl;
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

		cout << "[계좌개설]" << endl;
		cout << "계좌ID: "; cin >> accID;
		cout << "이  름: "; cin >> cusName;
		cout << "입금액 : "; cin >> balance;
		cout << "주민번호 : "; cin >> ID_card_number;

		if (balance < 10)
		{
			cout << "계좌개설 시에는 10원 이상의 입금액을 넣어야 합니다.\n" << endl;
			return;
		}

		if (bankCheck(accID) != -1) {
			cout << "이미 있는 계좌 ID입니다. \n다른 계좌ID를 입력해주세요" << endl;
			return;
		}

		for (int i = 0; i < index; i++)
		{
			if (strcmp(bankarr[i]->getcusName(), ID_card_number) == 0)
			{
				cout << "이미 있는 주민번호 입니다. \n다른 주민번호를 입력해주세요" << endl;
				return;
			}
		}

		bankarr[index++] = new Account(accID, balance, cusName, ID_card_number);
	}//계좌개설

	void deposit()
	{
		if (know_people() == true) return;

		int money;
		int id;
		int id_idx;

		cout << "[입    금]" << endl;
		cout << "계좌ID: "; cin >> id;
		cout << "입금액: "; cin >> money;

		if (money <= 0) {
			cout << "최소 1원 이상 넣어주세요" << endl;
			return;
		}

		id_idx = bankCheck(id);

		if (id_idx != -1)
		{
			bankarr[id_idx]->deposit(money);
			return;
		}
		cout << "유료하지 않는 ID입니다." << endl;
	}//입금

	void withdraw()
	{
		if (know_people() == true) return;

		int money;
		int id;
		int id_idx;

		cout << "[출    금]" << endl;
		cout << "계좌ID: "; cin >> id;
		cout << "입금액: "; cin >> money;

		if (money <= 0) {
			cout << "최소 1원 이상 빼주세요" << endl;
			return;
		}

		id_idx = bankCheck(id);

		if (id_idx != -1)
		{
			if (bankarr[id_idx]->getbalance() < money)
			{
				cout << "출금 금액이 현재 잔액보다 적습니다" << endl;
				return;
			}
			bankarr[id_idx]->withdraw(money);
			return;
		}
		cout << "유료하지 않는 ID입니다." << endl;
	}//출금

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
		cout << "선택:";
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
			cout << "없는 설정입니다" << endl;
			break;
		}
	}
}
