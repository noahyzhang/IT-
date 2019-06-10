#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>

#if 0

inline void eatline() { while (std::cin.get() != '\n' ) continue; }

struct planet {
	char name[20];
	double population;
	double g;
};

const char* file = "E://vs 项目/算法与数据结构/planets.dat";

int main()
{
	using namespace std;

	planet p1;
	cout << fixed << right;
	ifstream fin;
	fin.open(file, ios_base::in | ios_base::binary);
	if (fin.is_open())
	{
		cout << "Here are the current contents of the " << file << " file:\n";
		while (fin.read((char*)&p1, sizeof(p1)))
		{
			cout << setw(20) << p1.name << ": " << setprecision(0) << setw(12)
				<< p1.population << setprecision(2) << setw(6) << p1.g << endl;
		}
		fin.close();
	}

	ofstream fout(file, ios_base::out | ios_base::app | ios_base::binary);
	if (!fout.is_open())
	{
		cerr << "Can not open " << file << " file for output:\n";
		exit(EXIT_FAILURE);
	}
	cout << "Enter plant name (enter a blank line to quit):\n";
	cin.get(p1.name, 20);
	while (p1.name[0] != '\0')
	{
		eatline();
		cout << "Enter planetary population: ";
		cin >> p1.population;
		cout << "Enter planter is acceleration of gravity: ";
		cin >> p1.g;
		eatline();
		fout.write((char*)&p1, sizeof(p1));
		cout << "Enter planet name (enter a blank line to quit):\n";
		cin.get(p1.name, 20);
	}
	fout.close();

	fin.clear();
	fin.open(file, ios_base::in | ios_base::binary);
	if (fin.is_open())
	{
		cout << "Here are the new contents of the " << file << " file:\n";
		while (fin.read((char*)&p1, sizeof(p1)))
		{
			cout << setw(20) << p1.name << ": " << setprecision(0) << setw(12) << p1.population 
				<< setprecision(2) << setw(6) << p1.g << endl;
		}
		fin.close();
	}
	cout << "Done.\n";
	return 0;
}
#endif
#if 0
//随机生成文件名
#include<cstdio>
int main()
{
	char pszName[L_tmpnam] = { '\0' };
	std::cout << "Here are ten names:\n";
	for (int i = 0; i < 10; ++i)
	{
		tmpnam(pszName);
		std::cout << pszName << std::endl;
	}
	return 0;
}
#endif