#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void ReadFileData(string DataFile)
{
	fstream MyFile;

	MyFile.open(DataFile, ios::in);

	if (MyFile.is_open())
	{
		string Line;

		while (getline(MyFile, Line))
		{
			cout << Line << endl;
		}
		MyFile.close();

	}
}

void SiveDataFile(string DataFile, vector <string>& vDataFile)
{
	fstream MyFile;

	MyFile.open(DataFile, ios::in);

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

void DeleteDataFile(vector <string>& vDataFile, string DataDeleted)
{
	for (string& Line : vDataFile)
	{
		if (Line == DataDeleted)
		{
			Line = "";
		}
	}
}

void SaveNewDataFile(string DataFile, vector <string> vDataFile)
{
	fstream MyFile;

	MyFile.open(DataFile, ios::out);

	if (MyFile.is_open()) 
	{
		for (const string& Line : vDataFile)
		{
			if (Line != "")
			{
				MyFile << Line << endl;
			}
		} 

		MyFile.close(); 
	}
}

int main()
{
	vector <string> vDataFile;
	string DataFile = "MyFile_2.cpp";

	SiveDataFile(DataFile, vDataFile);
	DeleteDataFile(vDataFile, "walid");
	SaveNewDataFile(DataFile, vDataFile);

	ReadFileData(DataFile);
	return 0;
}
