#pragma once

struct Matrix // matrix a*b
{
	int a, b; // a - строки b - столбцы
	int *m;
	int &operator[](int i)
	{
		return m[i];
	}
	int get(int i, int j)
	{
		return m[i * b + j];
	}
	int &set(int i, int j)
	{
		return m[i * b + j];
	}
	Matrix(int i, int j)
	{
		m = new int[i * j];
		for (int k = 0; k < i * j; k++)
			m[k] = 0;
		a = i;
		b = j;
	}
	~Matrix()
	{
		delete[] m;
	}
};

struct Graph
{
	int points; //кол-во точек
	Matrix *m; //матрица смежности

	Graph(int p)
	{
		m = new Matrix(p, p);
		points = p;
	}
	~Graph()
	{
		delete m;
	}

	int &setM(int i, int j)
	{
		return (*m)[i * points + j];
	}
	int findMove(int a, int b);// поиск пути из a в b
};