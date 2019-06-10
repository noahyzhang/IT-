#include<iostream>
#if 0
class Plebe {
public:
	Plebe() {}
	Plebe(int) {}
	explicit Plebe(double) {}
};

int main()
{
	Plebe a, b;
	a = 5;
	b = 0.5;
	b = Plebe(0.5);
}
#endif
#if 0
class Session
{
	int mem1 = 10;
	double mem2{ 1966.54 };
	short mem3;
public:
	Session() {}
	Session(short s) :mem3(s) {}
};

int main()
{
	return 0;
}
#endif