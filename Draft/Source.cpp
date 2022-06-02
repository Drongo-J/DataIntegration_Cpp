#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Task 
// Persons.txt de insanlarin adlari soyadlari yaslari ve is yerleri yazilib
// onlarin her birinin pin kodlari PINcodes.txt de ardicilliqla yazilib
// bunlari bir biri ile birlesdirib basqa faylda desktopda cixarmaq lazimdir

char* getDesktopPath(const char* filename) {
	char* text = new char[250]{ "../../../../Desktop/" };
	strcat_s(text, strlen(text) + strlen(filename) + 100, filename);
	return text;
}

void createFileOnDesktop(const char* filename) {
	FILE* file;

	fopen_s(&file, getDesktopPath(filename), "w");
	fclose(file);
}

int getDataCount() {
	int numLines = 0;
	ifstream in("PINcodes.txt");
	std::string unused;
	while (std::getline(in, unused))
		++numLines;
	return numLines;
}

void readAndCombineInfos()
{
	ifstream inPIN("PINcodes.txt", ios::in);
	ifstream inPerson("Persons.txt", ios::in);
	ofstream out(getDesktopPath("personsInfo.txt"), ios::out);

	int dataCount = getDataCount();

	string pin = "";
	string personInfo = "";
	for (int x = 0; x < dataCount; x++)
	{
		cout << endl;
		getline(inPIN, pin);
		cout << pin << endl;
		getline(inPerson, personInfo);
		personInfo = personInfo.substr(2, personInfo.size());
		cout << personInfo << endl;

		out << pin << " - " << personInfo << endl;
	}
}

void main() {
	readAndCombineInfos();
}