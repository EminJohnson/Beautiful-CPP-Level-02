#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

int ReadInt(string Message, unsigned short From, unsigned short To)
{
	int Number = 0;

	cout << Message;

	while (true)
	{
		if (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid !!, Enter a real Number : \n";
			continue;
		}

		if (Number < From || Number > To)
		{
			cout << "Enter a Number [" + to_string(From) + " - > " + to_string(To) + "] : \n";
			continue;
		}

		return Number;
	}
}

void GetVectorElements(vector<int>& vNumber)
{
    char ReadMore = 'Y';
    while (ReadMore == 'Y' || ReadMore == 'y')
    {
        vNumber.push_back(ReadInt("Enter your Number: ", 1, 50));
        cout << "\nDo you want to add more numbers? (Y/N): ";
        cin >> ReadMore;
    }
}


void PrintElement(const vector<int>& vNumber) 
{
    for (const int& Number : vNumber) 
    {
        cout << setw(4) << Number;
    }
}


int main()
{
	vector <int> vNumber;
    GetVectorElements(vNumber);
    PrintElement(vNumber);

	return 0;
}
