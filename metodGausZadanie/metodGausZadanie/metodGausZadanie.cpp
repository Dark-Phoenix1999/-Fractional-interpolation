#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include <string.h>
#include<math.h>
#include<Windows.h>
#include<iostream>

double fun(double x) {
	return (1 + 2 * x - 3 * x * x + 4 * x * x * x) / (5 - 6 * x + 7 * x * x);
}

using namespace std;
int main()
{
	system("color 02");
	setlocale(LC_ALL, "RUS");
	int i, j, n, k, l, l1, g = 0;
	//создаем массив
	cout << "введи порядок числителя: ";
	cin >> k;
	cout << "введи порядок знаменателя: ";
	cin >> l1;
	n = k + l1 + 1;
	double matrix[100][100];
	double x[1000];
	double fx[1000];
	double* cat = new double[n];
	//инициализируем
	for (i = 0; i < n; i++)
	{
		cout << "x " << "[" << i + 1 << " ]: ";
		cin >> x[i];
	}
	for (i = 0; i < n; i++)
	{
		fx[i] = fun(x[i]);
	}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			if (j < k)
			{
				matrix[i][j] = pow(x[i], j + 1);
			}
			else
				matrix[i][j] = -fx[i] * pow(x[i], j - k);
		}

	for (i = 0; i < n; i++)
	{
		cat[i] = -1;
	}
	//выводим массив
	cout << "matrix: " << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << matrix[i][j] << " ";
		cout << cat[i] << " ";
		cout << endl;
	}
	cout << endl;
	double kaif, up, daun;
	//Метод Гаусса
	double tmp, xx[100];
	int k1;
	for (i = 0; i < n; i++)
	{
		g = 0;
		tmp = matrix[i][i];
		for (j = i + 1; j < n; j++) {
			if (fabs(tmp) < fabs(matrix[j][i])) {
				tmp = matrix[j][i];
				l = j;
				g = 1;
			}
		}
		if (g == 1) {
			for (j = 0; j < n; j++) {
				up = matrix[l][j];
				daun = matrix[i][j];
				matrix[i][j] = up;
				matrix[l][j] = daun;
			}
			up = cat[l];
			daun = cat[i];
			cat[i] = up;
			cat[l] = daun;
		}
		g = 0;
		for (j = 0; j <= n; j++)
			matrix[i][j] /= tmp;
		cat[i] /= tmp;
		for (k1 = i + 1; k1 < n; k1++)
		{
			tmp = matrix[k1][i];
			for (j = 0; j < n; j++)
				matrix[k1][j] = matrix[k1][j] / tmp - matrix[i][j];
			cat[k1] = cat[k1] / tmp - cat[i];
		}
	}
	for (i = n - 1; i >= 0; i--)
	{
		if (matrix[i][i] != 0)
		{
			tmp = matrix[i][i];
			for (j = n - 1; j >= 0; j--)
				matrix[i][j] /= tmp;
			cat[i] /= tmp;
			for (k1 = i - 1; k1 >= 0; k1--)
			{
				if (matrix[k1][i] != 0) {
					tmp = matrix[k1][i];
					for (j = n - 1; j >= 0; j--)
						matrix[k1][j] = matrix[k1][j] / tmp - matrix[i][j];
					cat[k1] = cat[k1] / tmp - cat[i];
				}
			}
		}
	}

	
	cout << "matrix: " << endl;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << matrix[i][j] << " ";
		cout << cat[i] << " ";
		cout << endl;
	}
	cout << endl;
	//Выводим решения
	for (i = 0; i < n; i++)
		cout << cat[i] << " ";
	cout << endl;
	getchar(); getchar();
	return 0;
}