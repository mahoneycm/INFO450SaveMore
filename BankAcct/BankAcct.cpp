// BankAcct.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class BankAccount
{
protected:
	string AcctNo = "0";
	float IntRate = 0;
	float AcctBalance;
	float AccruedInterest;
	char AcctType;
	char Action;
	float wamount;
	float damount;
	float tamount;
	int TermLength;
	int month;
public:
	void NewAcct(float ab)
	{
		AcctBalance = ab;
	}
	void NewCD(int tl, float ab)
	{
		TermLength = tl; AcctBalance = ab;
	}
	void getnumber(float t)
	{
		tamount = t;
	}
	void getmonth(float m)
	{
		month = m;
	}
	virtual float Deposit() = 0;
	virtual float Display() { return 0; };
	virtual float Withdraw() = 0;
	virtual float Interest() = 0;
	virtual int OrderChecks() = 0;
	
};
class Sacct : public BankAccount
{
	float WithdrawalFee = 2;
	int Month;
public:
	float Deposit()
	{
		AcctBalance += tamount;
		return 0;
	}
	float Withdraw()
	{
		if ((AcctBalance - tamount) < 0)
		{
			cout << "INNSUFICIENT FUNDS! TRANSACTION DENIED." << endl;
			return -1;
		}
		else
		{
			AcctBalance -= (tamount + WithdrawalFee);
		}
	}
	float Interest()
	{
		if (AcctBalance < 10000)
		{
			AcctBalance += (AcctBalance*((.01*month) / 12));
		}
		else
		{
			AcctBalance += (AcctBalance*((.02*month) / 12));
		}
		return 0;
	}
	float Display()
	{
		cout << "Saving: $" << AcctBalance << endl;
		return 0;
	}
	int OrderChecks()
	{
		cout << "Cannot Order Checks from Saving." << endl;
		return 0;
	}

};

class Cacct : public BankAccount
{
public:
	float Deposit()
	{
		return (AcctBalance += tamount);
	}
	float Withdraw()
	{
		if ((AcctBalance - tamount) < 0)
		{
			cout << "INNSUFICIENT FUNDS! TRANSACTION DENIED." << endl;
			return -1;
		}
		else
		{
			AcctBalance -= tamount;
			if (AcctBalance < 500)
			{
				AcctBalance - 5;
			}
		}
	}
	float Interest()
	{
		cout << "Checking account does not earn interest." << endl;
		return 0;
	};
	float Display()
	{
		cout << "Checking: $" << AcctBalance << endl;
		return 0;
	}
	int OrderChecks()
	{
		AcctBalance -= 15;
		return 0;
	}
};

class CD : public BankAccount
{
	int term;
	//int withdrawyear;
public:
	float Deposit()
	{
		AcctBalance = AcctBalance + tamount;
		return 0;
	}
	float Withdraw()
	{
		//for now
		if ((AcctBalance - tamount) < 0)
		{
			cout << "INNSUFICIENT FUNDS! TRANSACTION DENIED." << endl;
		}
		else
		{
			AcctBalance = AcctBalance *.9;
			AcctBalance -= tamount;
		}
		return 0;
	}
	float Interest()
	{
		if (term >= 5)
		{
			AcctBalance += (AcctBalance*((month*.1) / 12));
		}
		else
		{
			AcctBalance += (AcctBalance*((month*.05) / 12));
		}
		return 0;
	}
	float Display()
	{
		cout << "Cert. of Deposit: $" << AcctBalance << endl;
		return 0;
	}
	int OrderChecks()
	{
		cout << "Cannot order checks from this account." << endl;
		return 0;
	}
};





float main()
{
	Cacct Check;
	Sacct Save;
	CD Cert;
	BankAccount * SavePtr;
	BankAccount * CheckPtr;	
	BankAccount * CDPtr;

	CheckPtr = &Check;
	SavePtr = &Save;
	CDPtr = &Cert;
	CheckPtr->NewAcct(600);
	SavePtr->NewAcct(10000);
	CDPtr->NewCD(3, 10000);
	CheckPtr->Display();
	SavePtr->Display();
	CDPtr->Display();
	SavePtr->getmonth(1);
	CDPtr->getmonth(1);
	SavePtr->Interest();
	CDPtr->Interest();
	CheckPtr->Display();
	SavePtr->Display();
	CDPtr->Display();
	CheckPtr->OrderChecks();
	CheckPtr->getnumber(200);
	CheckPtr->Withdraw();
	SavePtr->getnumber(1000);
	SavePtr->Withdraw();
	CDPtr->getnumber(2000);
	CDPtr->Withdraw();
	CheckPtr->Display();
	SavePtr->Display();
	CDPtr->Display();

	//early withdraw of 2000 from CD
	//Display


	return 0;
}

