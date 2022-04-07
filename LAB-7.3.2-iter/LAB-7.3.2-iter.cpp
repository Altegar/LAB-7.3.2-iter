// LAB-7.3.2-iter.cpp
// Сушинський Ігор
// Лабораторна робота №7.3
// Опрацювання динамічних багатовимірних масивів.
// Варіант 18
// Ітераційний спосіб

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

void Random(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n);
void Part2_Number(int** a, const int k, const int n, int b, int max, int& c);

int main()
{
	setlocale(LC_ALL, "Ukrainian");

	srand((unsigned)time(NULL));

	int Low = 0;
	int High = 5;

	int k, n;

	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;

	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];

	Random(a, k, n, Low, High);
	Print(a, k, n);
	int b = 1;
	int max = 1;
	int c = 0;

	Part2_Number(a, k, n, b, max, c);
	cout << "C = " << c << endl;

	for (int i = 0; i < k; i++)
		delete[] a[i];
	delete[] a;

	return 0;
}

void Random(int** a, const int k, const int n, const int Low, const int High)
{
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int k, const int n)
{
	cout << endl;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}

void Part2_Number(int** a, const int k, const int n, int b, int max, int& c)
{
	c = 0;
	b = 1;

	for (int j = 0; j < n; j++)
	{
		b = 1;
		for (int i = 0; i < k - 1; i++)
		{
			if (a[i][j] == a[i + 1][j])
			{
				b++;

				if (b >= max)
				{
					max = b;
					c = j;
				}
			}
			else
				b = 1;
		}
	}
}