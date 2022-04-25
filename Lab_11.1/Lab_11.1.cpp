#include <iostream>
#include <fstream>
#include<Windows.h>
#include <string>
using namespace std;

//1 variant

//void CreateBIN(char* fname) // ��������� ����� ������� � �������� �����
//{
//	ofstream fout(fname, ios::binary); // ������� ���� ��� ������
//	string s; // �������� ������������ �����
//	int S;
//	//cin.get(); cin.sync();
//	char ch;
//	//cout << "enter line: "; cin>>S; // ����� �����
//	//fout.write((char*)&S, sizeof(S)); // �������� ������ � ����
//	do
//	{
//		//cin.get(); // ������� ����� ��������� � ��� �� ���� �������
//		//cin.sync(); // "����� �����", ���� ��������� ���� ����� �����
//		cout << "enter line: "; cin>>S; // ����� �����
//		//for (unsigned i = 0; i < s.length(); i++) // ������� �������� �����
//		fout.write((char*)&S, sizeof(S)); // �������� ������ � ����
//		cout << "continue? (y/n): "; cin >> ch;
//		cin.get(); cin.sync();
//	} while (ch == 'y' || ch == 'Y');
//	cout << endl;
//	fout.close();
//}

void PrintBIN(char* fname) // ��������� ����� �� �����
{
	ifstream fin(fname, ios::binary); // ������� ���� ��� ����������
	int c; // ���������� ������
	while (fin.read((char*)&c, sizeof(c))) // ���� ����� ��������� ������
	{
		cout << c << ' '; // �������� ���� �� �����
	}
	cout << endl;
	fin.close();
}

void Write(char* fname, char* gname) // ���������� �� ����� f
{ // � ���� g �������-�����
	ifstream f(fname, ios::binary); // ������� ���� ��� ����������
	ofstream g(gname, ios::binary); // ������� ���� ��� ������
	char space = ' ';
	
	int c; // ���������� ������
	while (f.read((char*)&c, sizeof(c))) // ���� ����� ��������� ������
	{
		//cout << c << endl;
		if (c >= -1 && c <= 1) // ���� ������ � ������
		{
			g.write((char*)&c, sizeof(c)); // �������� ���� � ���� g
			//g.write((char*)&space, sizeof(space));
		}
	}
	f.close();
	g.close();
}

//2variant




void CreateBIN(char* fname) // ��������� ����� ������� � �������� �����
{
	ofstream fout(fname, ios::binary); // ������� ���� ��� ������
	int pos=0,finish,S;
	char words[20];
	string s,word; // �������� ������������ �����
	cout << "enter line: "; getline(cin,s); // ����� �����
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
	cout << "������ ��'� ������� ����� : "; cin.getline(fname, 60);
	char gname[60];
	cout << "������ ��'� ������� �����: "; cin.getline(gname, 60);
	CreateBIN(fname);
	Write(fname,gname);
	PrintBIN(gname);
	return 0;


}