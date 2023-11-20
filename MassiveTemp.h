#pragma once
#include <iostream>

template <class T> class MassiveTemp
{
private:
	T* Massive;  //������ ���������
	int num; //����� ��������� �������

public:
	MassiveTemp(int m = 1);
	MassiveTemp(T* a, int m);
	MassiveTemp(const MassiveTemp<T>& x);
	MassiveTemp& operator=(const MassiveTemp<T>& X);
	~MassiveTemp();

	void Scan(int m);
	void Print();
	T& operator[] (int i);
	int FindKey(T key);

	MassiveTemp<T>& operator += (T key);
	MassiveTemp<T> operator + (T key);
	MassiveTemp<T>& operator += (MassiveTemp<T>& arr2);
	MassiveTemp<T> operator + (MassiveTemp<T>& arr2);

	MassiveTemp<T>& operator -= (T key);
	MassiveTemp<T> operator - (T key);

	MassiveTemp<T>& DelPosEq(int pos);
	MassiveTemp<T> DelPosNew(int pos);

	bool operator == (MassiveTemp<T>& arr2);
	bool operator != (MassiveTemp<T>& arr2);

	int Max();
	int Min();

	void Sorting();
	int GetN();

	template <class T> friend std::ostream& operator<< (std::ostream& r, MassiveTemp<T>& x)
	{
		for (int i = 0; i < x.num; i++)
			r << x.Massive[i] << " ";
		return r;
	}
	template <class T> friend std::istream& operator>> (std::istream& r, MassiveTemp<T>& x) { // ������� ������������� ���� ������� ��������� �����.
																		   // ��� ��� ����������� ������� �� ������ �� ����� ��������� ��������
		for (int i = 0; i < x.num; i++)
			r >> x.Massive[i];
		return r;
	}
private:// ����� �������� ��� ��� �� �������� � �� ��� ������ ������. ����� - ��������
	T* PutArr() {
		T* a;

		a = new T[num + 1];

		for (int i = 0; i < num; i++)
			a[i] = Massive[i];

		return a;
	} //������� ����������� ������� ������ � ������

	T* PutArrArr(T* arr_2, int num_2) {
		T* a;
		a = new T[num + num_2];

		for (int i = 0; i < num; i++)
			a[i] = Massive[i];
		for (int j = 0; j < num_2; j++)
			a[j + num] = arr_2[j];

		return a;
	} //������� ����������� ��������

	int PutArrDelKey(T* arr_q, T key) {
		int n = 0;

		for (int i = 0; i < num; i++)
			if (Massive[i] != key) {
				arr_q[n] = Massive[i];
				n++;
			}

		return n;
	} //������� �������� �������� �� �����

	int PutArrDelPos(T* arr_q, int pos) {
		int n = 0;

		for (int i = 0; i < num; i++)
			if (i != pos) {
				arr_q[n] = Massive[i];
				n++;
			}

		return n;
	} //������� �������� �������� �� �������
};


