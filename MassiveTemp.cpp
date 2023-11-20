#pragma once
#include <iostream>
#include "MassiveTemp.h"

using namespace std;

template <class T> MassiveTemp<T>::MassiveTemp(int m) {

	num = max(1, m);

	Massive = new T[num];
}

template <class T> MassiveTemp<T>::MassiveTemp(T* a, int m) {

	num = max(1, m);

	Massive = new T[num];

	for (int i = 0; i < num; i++)
		Massive[i] = a[i];
}

template <class T> MassiveTemp<T>::MassiveTemp(const MassiveTemp<T>& X) {
	num = X.num;
	Massive = new T[X.num];
	for (num = 0; num < X.num; num++)
		Massive[num] = X.Massive[num];
}

template <class T> MassiveTemp<T>& MassiveTemp<T>::operator = (const MassiveTemp& X) {
	if (this != &X)
	{
		delete[] Massive;
		Massive = new T[(num = X.num)];

		for (int i = 0; i < num; i++)
			Massive[i] = X.Massive[i];
	}

	return *this;
}

template <class T> MassiveTemp<T>::~MassiveTemp() {
	delete[] Massive;
}

template <class T> void MassiveTemp<T>::Scan(int m) {

	delete[]Massive;

	num = max(1, m);

	Massive = new T[num];

	cout << "\nInput " << num << " elements: ";
	for (int i = 0; i < num; i++)
		cin >> Massive[i];
};
template <class T> void MassiveTemp<T>::Print() {
	for (int i = 0; i < num; i++)
		cout << Massive[i] << ' ';
};
template <class T> T& MassiveTemp<T>::operator[] (int i) {
	if (i >= 0 && i < num)
		return Massive[i];
	else
	{
		cout << "\n¬ведЄн индекс вне пределов массива.\nЅудет выведен первый элемент\n";
		return Massive[0];
	}
}
template <class T> int MassiveTemp<T>::FindKey(T key) {
	for (int i = 0; i < num; i++)
		if (Massive[i] == key)
			return i;
	return -1;
}
template <class T> int MassiveTemp<T>::GetN() {
	return num;
}

template <class T> MassiveTemp<T>& MassiveTemp<T>::operator += (T key) {
	T* Massive1;

	Massive1 = PutArr();

	Massive1[num] = key;
	delete[]Massive;
	Massive = Massive1;
	num++;

	return *this;
}
template <class T> MassiveTemp<T> MassiveTemp<T>::operator + (T key) {
	MassiveTemp<T> TmasNew(num + 1);

	TmasNew.Massive = PutArr();

	TmasNew.Massive[num] = key;

	return TmasNew;
}
template <class T> MassiveTemp<T>& MassiveTemp<T>::operator += (MassiveTemp<T>& Tmas2) {
	T* Massive1;
	Massive1 = new T[num + Tmas2.num];

	Massive1 = PutArrArr(Tmas2.Massive, Tmas2.num);

	delete[]Massive;
	Massive = Massive1;
	num += Tmas2.num;

	return *this;
}
template <class T> MassiveTemp<T> MassiveTemp<T>::operator + (MassiveTemp<T>& Tmas2) {
	MassiveTemp<T> TmasNew(num + Tmas2.num);

	TmasNew.Massive = PutArrArr(Tmas2.Massive, Tmas2.num);

	return TmasNew;
}


template <class T> MassiveTemp<T>& MassiveTemp<T>::operator -= (T key) {
	if (FindKey(key) != -1)
	{
		T* Tmas1;

		Tmas1 = new T[num - 1];

		int n = PutArrDelKey(Tmas1, key);

		delete[]Massive;
		Massive = Tmas1;
		num = n;
	}

	return *this;
}
template <class T> MassiveTemp<T> MassiveTemp<T>::operator - (T key) {
	MassiveTemp<T> TmasNew(num - 1);

	if (FindKey(key) != -1)
	{
		T* Tmas1;

		Tmas1 = new T[num - 1];

		int n = PutArrDelKey(Tmas1, key);

		TmasNew.Massive = Tmas1;
		TmasNew.num = n;
	}
	else
	{
		TmasNew = *this;
	}

	return TmasNew;
}


template <class T> MassiveTemp<T>& MassiveTemp<T>::DelPosEq(int pos) {
	if (pos >= 0 && pos < num)
	{
		T* Tmas1;

		Tmas1 = new T[num - 1];

		int n = PutArrDelPos(Tmas1, pos);

		delete[]Massive;
		Massive = Tmas1;
		num = n;
	}


	return *this;
}
template <class T> MassiveTemp<T> MassiveTemp<T>::DelPosNew(int pos) {
	MassiveTemp<T> TmasNew(num - 1);

	if (pos >= 0 && pos < num)
	{
		T* Tmas1;

		Tmas1 = new T[num - 1];

		int n = PutArrDelPos(Tmas1, pos);

		TmasNew.Massive = Tmas1;
		TmasNew.num = n;
	}
	else
	{
		TmasNew = *this;
	}

	return TmasNew;
}


template <class T> bool MassiveTemp<T>::operator == (MassiveTemp<T>& Tmas2)
{
	if (num != Tmas2.num)
		return false;
	else {
		for (int i = 0; i < num; i++)
			if (Massive[i] != Tmas2.Massive[i])
				return false;
	}

	return true;
}
template <class T> bool MassiveTemp<T>::operator != (MassiveTemp<T>& Tmas2) {
	if (num != Tmas2.num)
		return true;
	else {
		for (int i = 0; i < num; i++)
			if (Massive[i] != Tmas2.Massive[i])
				return true;
	}

	return false;
}


template <class T> int MassiveTemp<T>::Max() {
	T MaxN = Massive[0];
	int MaxI = 0;

	for (int i = 1; i < num; i++)
	{
		if (MaxN < Massive[i]) {
			MaxN = Massive[i];
			MaxI = i;
		}
	}

	return MaxI;
}
template <class T> int MassiveTemp<T>::Min() {
	T MinN = Massive[0];
	int MinI = 0;

	for (int i = 1; i < num; i++)
	{
		if (MinN > Massive[i]) {
			MinN = Massive[i];
			MinI = i;
		}
	}

	return MinI;
}


template <class T> void MassiveTemp<T>::Sorting() {
	sort(Massive, Massive + num);
}