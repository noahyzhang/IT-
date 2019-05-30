#include<iostream>
#if 0
int main()
{
	using namespace std;
	cout << "Enter an integer: ";
	int n;
	cin >> n;

	cout << "n	n*n\n";
	cout << n << "	" << n * n << " (decimal)\n";

	cout << hex;
	cout << n << "	";
	cout << n * n << " (hexadecimal)\n";

	cout << oct << n << "    " << n * n << " (octal)\n";

	dec(cout);
	cout << n << "    " << n * n << " (decimal)\n";

	system("pause");
	return 0;
}
#endif
//
//int main()
//{
//	//std::cout << std::cout.width();
//	//std::cout << "#";
//	//std::cout.width(12);
//	//std::cout.fill('*');
//	//std::cout << 12 << "#" << 24 << "#\n";
//
//	float f = 1222.0;
//	//std::cout.precision(10);
//	std::cout.setf(std::ios_base::showpoint);
//	std::cout << f << std::endl;
//	return 0;
//}

#if 0
int main()
{
	int temperature = 63;
	std::cout << "Today water temperature: ";
	std::cout.setf(std::ios_base::showpos);
	std::cout << temperature << std::endl;

	std::cout << "For our programming friends,that is \n";
	std::cout << std::hex << temperature << std::endl;
	std::cout.setf(std::ios_base::uppercase);
	std::cout.setf(std::ios_base::showbase);
	std::cout << "or\n";
	std::cout << temperature << std::endl;
	std::cout << "How " << true << "!  oops -- How";
	std::cout.setf(std::ios_base::boolalpha);
	std::cout << true << "!\n";

	system("pause");
	return 0;
}
#endif

#if 0
int main()
{
	while (1)
	{
		int a = 1;
		std::cin >> std::oct >> a;
		//std::cin >> a;
		//std::cout.dec;
		std::cout << a << std::endl;
	}
	system("pause");
	return 0;
}
#endif
#if 0
int main()
{
	int ev;
	std::cin >> ev;
	std::cout << ev << std::endl;
	system("pause");
	return 0;
}
#endif

#if 0
int main()
{
	int ct = 0;
	char ch;
	std::cin >> ch;
	while (ch != '\n')
	{
		std::cout << ch;
		ct++;
		std::cin >> ch;
	}
	std::cout << ct << std::endl;

	system("pause");
	return 0;
}
#endif

