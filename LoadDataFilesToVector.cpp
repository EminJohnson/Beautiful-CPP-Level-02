#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void LoadDataFilesToVector(string FullFile, vector <string>& vDataFile)
{
	fstream MyFile;

	MyFile.open(FullFile, ios::in);

	if (MyFile.is_open())
	{
		string Line;

		while (getline(MyFile, Line))
		{
			vDataFile.push_back(Line);
		}

		MyFile.close();
	}
}

void PrintDataFile(vector <string>& vDataFile)
{
	for (string& DataFile : vDataFile)
	{
		cout << DataFile << endl;
	}
}

int main()
{
	vector <string> vDataFile;

	LoadDataFilesToVector("MyFile.cpp", vDataFile);

 	PrintDataFile(vDataFile);

	return 0;
}
