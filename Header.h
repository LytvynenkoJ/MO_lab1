#pragma once
#include <iostream>
#include "locale.h"
using namespace std;

float eps = 0.00001;

float Pn(float x)
{
	return 2 * x * x * x - 4 * x * x - x + 2;
}
float P1(float x)
{
	return 6 * x * x - 8 * x - 1;
}

float bisection(float a[2])
{
	int i = 0;
	float x = 0;
	float pa = 0;
	float pb = 0;
	float pc = 0;
	float c = (a[0] + a[1]) / 2;
	while (abs(a[0]-a[1])>=eps && x!=c)
	{
		c = (a[0] + a[1]) / 2;
		//cout << c << endl;
		pa = Pn(a[0]);
		pb = Pn(a[1]);
		pc = Pn(c);
		cout << "итерация:   " << i+1 << endl;
		if (pa * pc < 0)
		{
			a[1] = c;
			//cout << "(a,b) = (" << a[0] << ", " << a[1] << ")" << endl;
		}
		if (pb * pc < 0)
		{
			a[0] = c;
			//cout << "(a,b) = (" << a[0] << ", " << a[1] << ")" << endl;
		}
		if (pc == 0)
		{
			x = c;
		}
		cout << "   x* : " << (a[0] + a[1]) / 2 << endl;
		cout << "        |a-b| : " << abs(a[0] - a[1]) << endl << endl;
		i++;
	}
	cout << "Количество итераций:     i = " << i << endl;
	if (x != c)
		x = (a[0] + a[1]) / 2;
	return x;
}

float newton(float a[2])
{
	int i = 0;
	float x = 1;
	//float pa = 0;
	//float pb = 0;
	float pc = 0;
	//pa = Pn(a[0]);
	//pb = Pn(a[1]);
	float c1 = a[0];
	float c2 = 0;
	while (abs(c1-c2) >= eps && x!=c2)
	{
		cout << "итерация:   " << i + 1 << endl;
		c2 = c1 - Pn(c1) / P1(c1);
		pc = Pn(c2);
		if (abs(pc) < eps || abs(c1 - c2) < eps)
		{
			x = c2;
		}
		else
		{
			float temp = 0;
			temp = c1;
			c1 = c2;
			c2 = temp;
		}
		cout << "   x* : " << (c1 + c2) / 2 << endl;
		cout << "     |f(c)| : " << abs(pc) << endl;
		cout << "        |x_{k}-x_{k-1}| : " << abs(c1 - c2) << endl << endl;
		//cout << endl;
		i++;
	}
	cout << "Количество итераций:     i = " << i << endl;
	if (x != c2)
		x = (c1 + c2) / 2;
	return x;
}

float secant(float a[2]) //хорд
{
	int i = 0;
	float x = 1;
	float pa = Pn(a[0]);
	float pb = Pn(a[1]);
	float pc = 0;
	float c = 0;
	while (abs(a[0] - a[1]) >= eps && x != c)
	{
		c = (a[0] * pb - a[1] * pa) / (pb - pa);
		pa = Pn(a[0]);
		pb = Pn(a[1]);
		//cout << c << endl;
		pc = Pn(c);
		cout << "итерация:   " << i + 1 << endl;
		if (pa * pc < 0)
		{
			a[1] = c;
			//cout << "(a,b) = (" << a[0] << ", " << a[1] << ")" << endl;
		}
		if (pb * pc < 0)
		{
			a[0] = c;
			//cout << "(a,b) = (" << a[0] << ", " << a[1] << ")" << endl;
		}
		if (abs(pc) <= eps)
		{
			x = c;
		}
		cout << "   x* : " << (a[0] + a[1]) / 2 << endl;
		cout << "     |c-c_p| : " << abs(a[0] - a[1]) << endl ;
		cout << "        |f(c)| : " << abs(pc) << endl<< endl;
		i++;
	}
	cout << "Количество итераций:     i = " << i << endl;
	if (x != c)
		x = (a[0] + a[1]) / 2;
	return x;
}