#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

struct stInfo
{
	string FirstName = "";
	string LastName = "";
	int Salary = 0;
};

void Getint(string Message, int& Number, unsigned short From, unsigned short To)
{
	cout << Message;
	while (true)
	{
		if (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid !!, Enter a real Number ";
			continue;
		}

		if (Number < From || Number > To)
		{
			cout << "Enter a Number [" << From << " - > " << To << "] : \n";
			continue;
		}

		break;
	}
}

stInfo ReadEmployeeInformation(stInfo& EmployeeInf)
{
	
	cout << "Enter her /hes first Name : \n";
	getline(cin, EmployeeInf.FirstName);
	
	cout << "Enter her /hes last Name : \n";
	getline(cin, EmployeeInf.LastName);

	Getint("Enter her /hes Saliry : \n", EmployeeInf.Salary, 200, 20000);
	return EmployeeInf;
}

void promptAndInsertData(stInfo& EmployeeInf, vector <stInfo>& vEmployeeInfo)
{
	char Prompt = 'Y';

	do
	{
		ReadEmployeeInformation(EmployeeInf);
		vEmployeeInfo.push_back(EmployeeInf);

		cout << "\nDo you want to read more employees? Y/N ?";
		cin >> Prompt;
		cin.ignore(1, '\n');
	} 
	while (Prompt == 'Y' || Prompt == 'y');

}

void PrintInformation(vector <stInfo>& vEmployeeInfo)
{
	for (stInfo& EmployeeInfo : vEmployeeInfo)
	{
		cout << "FirstName: " << EmployeeInfo.FirstName << endl;
		cout << "LastName : " << EmployeeInfo.LastName << endl;
		cout << "Salary : " << EmployeeInfo.Salary << endl;
		cout << endl;
	}
	cout << endl;
}

int main()
{
	stInfo EmployeeInfo;
	vector <stInfo> vEmployeeInfo;

	promptAndInsertData(EmployeeInfo, vEmployeeInfo);
	PrintInformation(vEmployeeInfo);
	return 0;
}
