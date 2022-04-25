#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_11.1/Lab_11.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	void FromFile(char* fname,int c[7]) // виведення файлу на екран
	{
		ifstream fin(fname, ios::binary); // відкрили файл для зчитування
		int i = 0;// прочитаний символ
		while (fin.read((char*)&c[i++], sizeof(int))) // поки можна прочитати символ
		{
		}
		fin.close();
	}
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int c[7];
			int b[]{ 1,-1,0,1,1,0,-1 };
			Write("proba1.bit", "Proba2.bit");
			FromFile("proba2.bit", c);
			for (int i = 0; i < 7; i++)
			{
				Assert::AreEqual(c[i], b[i]);
			}
		}
	};
}
