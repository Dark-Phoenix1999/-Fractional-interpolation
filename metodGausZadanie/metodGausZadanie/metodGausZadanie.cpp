#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include <string.h>
#include<math.h>
#include<Windows.h>
#include<iostream>

using namespace std;
int main()
{
	system("color 02");
	setlocale(LC_ALL, "RUS");
	int i, j, n, k, l,l1, g = 0;
	//создаем массив
	cout << "введи порядок числителя: ";
	cin >> k;
	cout << "введи порядок знаменателя: ";
	cin >> l1;
	n = k + l1 + 1;
	float matrix[100][100];
	float x[1000];
	float fx[1000];
	float* cat = new float[n];
	//инициализируем
	for (i = 0; i < n; i++)
	{
		cout << "x " << "[" << i + 1 << " ]: ";
		cin >> x[i];
	}
	for (i = 0; i < n; i++)
	{
		cout << "fx " << "[" << i + 1 << " ]: ";
		cin >> fx[i];
	}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			if (j < k)
				matrix[i][j] = pow(x[i], i + 1);
			else
				matrix[i][j] =x[i]*pow(fx[i], i);
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
	float kaif, up, daun;
	//Метод Гаусса
	float tmp, xx[100];
	int k;
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
		/* cout << "matrix: " << endl;
		for ( k= 0; k<n; k++)
		{
		for (j = 0; j<m; j++)
		cout << matrix[k][j] << " ";
		cout << cat[k] << " ";
		cout << endl;
		}
		cout << endl;*/
		//проверка
		for (j = 0; j <= n; j++)
			matrix[i][j] /= tmp;
		cat[i] /= tmp;
		for (k = i + 1; k < n; k++)
		{
			tmp = matrix[k][i];
			for (j = 0; j < n; j++)
				matrix[k][j] = matrix[k][j] / tmp - matrix[i][j];
			cat[k] = cat[k] / tmp - cat[i];
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
			for (k = i - 1; k >= 0; k--)
			{
				if (matrix[k][i] != 0) {
					tmp = matrix[k][i];
					for (j = n - 1; j >= 0; j--)
						matrix[k][j] = matrix[k][j] / tmp - matrix[i][j];
					cat[k] = cat[k] / tmp - cat[i];
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