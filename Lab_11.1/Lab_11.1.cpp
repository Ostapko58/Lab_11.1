#include <iostream>
#include <fstream>
#include<Windows.h>
#include <string>
using namespace std;

//1 variant

//void CreateBIN(char* fname) // створення файлу символів з введених рядків
//{
//	ofstream fout(fname, ios::binary); // відкрили файл для запису
//	string s; // введений користувачем рядок
//	int S;
//	//cin.get(); cin.sync();
//	char ch;
//	//cout << "enter line: "; cin>>S; // ввели рядок
//	//fout.write((char*)&S, sizeof(S)); // записали символ у файл
//	do
//	{
//		//cin.get(); // очищуємо буфер клавіатури – щоб не було символу
//		//cin.sync(); // "кінець рядка", який залишився після вводу числа
//		cout << "enter line: "; cin>>S; // ввели рядок
//		//for (unsigned i = 0; i < s.length(); i++) // скануємо введений рядок
//		fout.write((char*)&S, sizeof(S)); // записали символ у файл
//		cout << "continue? (y/n): "; cin >> ch;
//		cin.get(); cin.sync();
//	} while (ch == 'y' || ch == 'Y');
//	cout << endl;
//	fout.close();
//}

void PrintBIN(char* fname) // виведення файлу на екран
{
	ifstream fin(fname, ios::binary); // відкрили файл для зчитування
	int c; // прочитаний символ
	while (fin.read((char*)&c, sizeof(c))) // поки можна прочитати символ
	{
		cout << c << ' '; // виводимо його на екран
	}
	cout << endl;
	fin.close();
}

void Write(char* fname, char* gname) // переписати із файлу f
{ // у файл g символи-цифри
	ifstream f(fname, ios::binary); // відкрили файл для зчитування
	ofstream g(gname, ios::binary); // відкрили файл для запису
	char space = ' ';
	
	int c; // прочитаний символ
	while (f.read((char*)&c, sizeof(c))) // поки можна прочитати символ
	{
		//cout << c << endl;
		if (c >= -1 && c <= 1) // якщо символ є цифрою
		{
			g.write((char*)&c, sizeof(c)); // записуємо його у файл g
			//g.write((char*)&space, sizeof(space));
		}
	}
	f.close();
	g.close();
}

//2variant




void CreateBIN(char* fname) // створення файлу символів з введених рядків
{
	ofstream fout(fname, ios::binary); // відкрили файл для запису
	int pos=0,finish,S;
	char words[20];
	string s,word; // введений користувачем рядок
	cout << "enter line: "; getline(cin,s); // ввели рядок
	while ((pos = s.find_first_not_of(" ,._", pos)) != -1)
	{
		finish = s.find_first_of(" ,._", pos) - 1;
		if (finish == -1)
		{
			finish = s.length() - 1;
		}
		word = s.substr(pos, (finish - pos) + 1);
		S = stoi(word);
		fout.write((char*)&S, sizeof(S));
		pos = finish + 1;
	}
	fout.close();
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char fname[60];
	cout << "Введіть ім'я першого файлу : "; cin.getline(fname, 60);
	char gname[60];
	cout << "Введіть ім'я другого файлу: "; cin.getline(gname, 60);
	CreateBIN(fname);
	Write(fname,gname);
	PrintBIN(gname);
	return 0;


}