#include <iostream>
using namespace std;
#define NAME_LEN 20

typedef struct
{
	int accID;//계좌번호
	int balance;//잔액
	char cusName[NAME_LEN]; //고객이름
}Account;

Account bankarr[100];
int index = 0;

void printMenu()
{
	cout << "-----menu-----" << endl;
	cout << "1.계좌 개설" << endl;
	cout << "2.입     금" << endl;
	cout << "3.출     금" << endl;
	cout << "4.계좌정보 전체 출력" << endl;
	cout << "5.프로그램 종료" << endl;
} //menu 출력
int makeacc()
{
	int accID;
	char cusName[NAME_LEN];
	int balance;

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: "; cin >> accID;
	cout << "이  름:"; cin >> cusName;
	cout << "입금액 :"; cin >> balance;

	if (balance < 10)
	{
		cout << "계좌개설 시에는 10원 이상의 입금액을 넣어야 합니다.\n" << endl;
	}
	strcpy_s(bankarr[index].cusName, cusName);
	bankarr[index].accID = accID;
	bankarr[index].balance = balance;
	for (int i = 0; i < index; i++)
	{
		if (bankarr[i].accID == accID)
		{
			cout << "이미 있는 계좌 ID입니다. \n다른 계좌ID를 입력해주세요" << endl;
			accID = NULL;
			balance = NULL;
			cusName[0] = NULL;
			index--;

		}
	}
	index++;
}//계좌개설

void deposit()
{
	int money;
	int id;

	cout << "[입    금]" << endl;
	cout << "계좌ID:", cin >> id;
	cout << "입금액:"; cin >> money;

	for (int i = 0; i < index; i++)
	{
		if (bankarr[i].accID == id)
		{
			bankarr[i].balance += money;
			return;
		}
	}
	cout << "유료하지 않는 ID입니다." << endl;
}//입금
void withdraw()
{
	int money;
	int id;

	cout << "계좌 ID:"; cin >> id;
	cout << "출금액:"; cin >> money;

	for (int i = 0; i < index; i++)
	{
		if (bankarr[i].accID == id)
		{
			if (bankarr[i].balance < money)
			{
				bankarr[i].balance += money;
				cout << "출금 금액이 현재 잔액보다 적습니다" << endl;
				return;
			}
			else
			{
				bankarr[i].balance -= money;
				return;
			}
		}
	}
	cout << "유효하지 않은 ID입니다." << endl;
}//출금

void check_acc()
{
	for (int i = 0; i < index; i++)
	{
		cout << "계좌 ID: " << bankarr[i].accID << endl;
		cout << "이  름:" << bankarr[i].cusName << endl;
		cout << "잔  액:" << bankarr[i].balance << endl;
	}
}
int main(void)
{
	int choice;
	while (1)
	{
		printMenu();
		cout << "선택:";
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
			cout << "없는 설정입니다" << endl;
			break;
		}
	}
}
