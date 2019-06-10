#include<iostream>
#include<vector>
using namespace std;

int divide(int dividend, int divisor)
{
	if (dividend == 0 || dividend < divisor) return 0;

	long long NewDividend = dividend, NewDivisor = divisor;
	long long cur_bit = 1, result = 0;

	NewDividend = abs(NewDividend);
	NewDivisor = abs(NewDivisor);

	while (NewDividend >= (NewDivisor << 1))
	{
		NewDivisor <<= 1;
		cur_bit <<= 1;
	}

	while (cur_bit > 0 && NewDividend > 0)
	{
		if (NewDividend > NewDivisor)
		{
			NewDividend -= NewDivisor;
			result += cur_bit;
		}
		cur_bit >>= 1;
		NewDivisor >>= 1;
	}

	result = ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) ? -result : result;

	if (result > INT32_MAX) return INT32_MAX;
	return result;
}


int divide1(int dividend, int divisor)
{
	if (divisor == 0 || (dividend == INT32_MIN && divisor == -1)) return INT32_MAX;

	int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
	long long ms = (long long)dividend, ns = (long long)divisor;
	ms = abs(ms), ns = abs(ns);
	long long num = 0;
	while (ms >= ns)
	{
		long long m = ns, n = 1;
		while (ms >= (m << 1))
		{
			m <<= 1;
			n <<= 1;
		}
		num += n;
		ms -= m;
	}
	return (int)num * sign;
}

#if 0
int main()
{
	int res = divide1(-214748364, 1);
	return 0;
}
#endif

#if 0
int main()
{
	auto a = -2147483647-1;
	auto b = 2147483648;
	auto c = 2147483647;
	cout << a << typeid(a).name() << endl;
	cout << b << typeid(b).name() << endl;
	cout << c << typeid(c).name() << endl;
	return 0;
}
#endif
