#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void SavevectorToFile(string FullFile, vector <string> vDataFile)
{
	fstream MyFile;

	MyFile.open(FullFile, ios::out | ios::app);

	if (MyFile.is_open())
	{
		for (string& DataFile : vDataFile)
		{
			MyFile << DataFile << endl;
		}

		MyFile.close();
	}
}

int main()
{
	vector <string> vDataFile = {"Amine", "Lotfi", "Widad"};

	SavevectorToFile("MyFile_2.cpp", vDataFile);

	return 0;
}
