#include<iostream>
#include<algorithm>

bool g_InvalidInput = false;

bool equal(double num1, double num2)
{
	if (num1 - num2 > -0.000001 && num1 - num2 < 0.000001)
		return true;
	return false;
}

double PowerWithUsignedExponent(double base, int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;
	double result = PowerWithUsignedExponent(base, exponent >> 1);
	result *= result;
	if (exponent & 0x1)
		result *= base;
	return result;
}

double Power(double base, int exponent)
{
	g_InvalidInput = false;
	if (equal(base,0.0) && exponent < 0)
	{
		g_InvalidInput = true;
		return 0.0;
	}
	unsigned int absExponent = (unsigned int)(exponent);
	if (exponent < 0)
		absExponent = (unsigned int)(-exponent);

	double result = PowerWithUsignedExponent(base, exponent);
	if (exponent < 0)
		result = 1.0 / result;
	return result;
}