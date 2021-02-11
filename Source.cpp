#include "Header.h"

int main()
{
	setlocale(LC_ALL,"Russian");
	float* a = new float[2];
	float* b = new float[2];
	float* c = new float[2];
	float* a2 = new float[2];
	float* b2 = new float[2];
	float* c2 = new float[2];
	float x1 = 0, x2 = 0, x3 = 0;
	cout << "Введите интервалы для уточнения корней:" << endl;
	cin >> a[0] >> a[1];
	cin >> b[0] >> b[1];
	cin >> c[0] >> c[1];
	for (int i = 0; i < 2; i++)
	{
		a2[i] = a[i]; b2[i] = b[i]; c2[i] = c[i];
	}
	x1 = bisection(a2);
	cout << "-----------------------------------------------" << endl;
	x2 = bisection(b2);
	cout << "-----------------------------------------------" << endl;
	x3 = bisection(c2);
	cout << "-----------------------------------------------" << endl;
	cout << "Уточненные корни методом бисекции: " << endl;
	cout << "x1 = " << x1 << endl;
	cout << "x2 = " << x2 << endl;
	cout << "x3 = " << x3 << endl;
	x1 = 0; x2 = 0; x3 = 0;
	for (int i = 0; i < 2; i++)
	{
		a2[i] = a[i]; b2[i] = b[i]; c2[i] = c[i];
	}
	cout << endl << "===============================================" << endl << endl;
	x1 = secant(a2);
	cout << "-----------------------------------------------" << endl;
	x2 = secant(b2);
	cout << "-----------------------------------------------" << endl;
	x3 = secant(c2);
	cout << "-----------------------------------------------" << endl;
	cout << "Уточненные корни методом хорд: " << endl;
	cout << "x1 = " << x1 << endl;
	cout << "x2 = " << x2 << endl;
	cout << "x3 = " << x3 << endl;
	x1 = 0; x2 = 0; x3 = 0;
	for (int i = 0; i < 2; i++)
	{
		a2[i] = a[i]; b2[i] = b[i]; c2[i] = c[i];
	}
	cout << endl << "===============================================" << endl << endl;
	x1 = newton(a2);
	cout << "-----------------------------------------------" << endl;
	x2 = newton(b2);
	cout << "-----------------------------------------------" << endl;
	x3 = newton(c2);
	cout << "-----------------------------------------------" << endl;
	cout << "Уточненные корни методом Ньтона: " << endl;
	cout << "x1 = " << x1 << endl;
	cout << "x2 = " << x2 << endl;
	cout << "x3 = " << x3 << endl;
	return 0;
}
