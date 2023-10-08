#include "MassiveTemp.h"
#include <iostream>

int main()
{
	TempArr<int> Aint;
	//1)	�������� ������ Array mas1. �������� � ���� 5 �����: 1,2,3,4,5
	//  (�������� �������� � ����������, ��� ���������� ����-������ ����������� ������� Scan).
	//�������� mas1 �� �����, ��������� ������� Print.

	Aint.Scan();
	std::cout << "1:" << std::endl;
	Aint.Print();

	//2)	�������� ������ Array mas2, ��������������� ��� ��� �������� �������� mas 1.
	//�������� mas2 �� �����, ��������� ��������� �����.

	std::cout << "2:" << std::endl;
	TempArr<int> Bint = Aint;
	Bint.Print();
	//3)	�������� ������� mas1 � mas2.

	std::cout << "3:" << std::endl;
	std::cout << "int: " << std::endl;
	if (Aint == Bint) std::cout << "�����" << std::endl;
	else std::cout << "�� �����" << std::endl;
	//4)	�������� mas1 ������� � ���� ����� 6. �������� ���������� mas1 �� �����.�������� ������� mas1 � mas2.

	std::cout << "4:" << std::endl;
	Aint += 2;

	Aint.Print();

	std::cout << "int: " << std::endl;
	if (Aint == Bint) std::cout << "�����" << std::endl;
	else std::cout << "�� �����" << std::endl;
	//5)	�������� ������ Array mas3, ������� ���������� ����������� � mas1  ����� 7. �������� mas3 �� �����.

	std::cout << "5:" << std::endl;
	TempArr<int> Cint = Aint += 7;
	Cint.Print();
	//6)	������� ������ ������� �� mas3.�������� ������������ mas3 �� �����.
	std::cout << "6:" << std::endl;

	Cint -= 0;

	Cint.Print();
	//7)	�������� ������ mas4, ������� ���������� �� mas3 ��������� ���������� ��������.�������� ������������ mas4 �� �����.
	std::cout << "7:" << std::endl;
	int lastInt = Cint.GetN() - 1;
		//std::cout << lastInt << " " << lastFloat << " " << lastChar;

	Cint -= lastInt;
	TempArr<int> Dint = Cint;

	Dint.Print();
	//8)	������� �� mas1 ������� key = 1. ���������, ����� �� mas1 � mas4
	
	Aint -= Aint.FindKey(1);

	if (Aint == Dint) std::cout << "�����" << std::endl;
	else std::cout << "�� �����" << std::endl;
	//9)	������� ����� n  � ����������� ������ b �� n ��������� �����.�������� ������ Array mas5, 
	//		��������� ����������� � ���������� - ������.
	int n = -1;

	while (n < 0)
	{
		std::cout << "������� ����� n ���������: " << std::endl;
		std::cin >> n;
		if (n < 0) std::cout << "����� ������ 0" << std::endl;
	}

	int* bInt = new int[n];
	for (int i = 0; i < n; i++)
	{
		bInt[i] = rand() % 100;
	}

	TempArr<int> Eint(bInt, n);

	Eint.Print();
	//10)  ������� ������������ � ����������� ������� � mas5.�������� �� ����� ��� �������� � �� �������.
	 
	std::cout << "max: " << Eint[Eint.Max()] << " min: " << Eint[Eint.Min()] << std::endl;
	//11)	���������� mas5 � �������� ��������� �� �����.
	
	Eint.Sorting();

	Eint.Print();
	//12)	��������  ������ Array mas6, ��������� mas1 � mas5.�������� ��������� �� �����

	TempArr<int> Fint = Aint + Eint;

	Fint.Print();
	//13)  ��������  ������ Array mas7 � ������ �� 4 - � ���������.
	//��������� ���� - ������(10, 11, 12, 13), ��������� ��������� ����.
	
	TempArr<int> Gint(4);
	std::cout << "������� 4 ��������: ";
	for (int i = 0; i < 4; i++)
	{
		int n; std::cin >> n; Gint[i] = n;
	}
	Gint.Print();
	//14)  ���������, ������ �� � mas7 �������� 1 � 10. �������� mas8, ������� ���������� �� mas7 ��������� �������� 10.
	
	if (Gint.FindKey(1) != -1) std::cout << "1 ������ � ������" << std::endl;
	else std::cout << "1 �� ������ � ������" << std::endl;
	if(Gint.FindKey(10) != -1) std::cout << "10 ������ � ������" << std::endl;
	else std::cout << "10 �� ������ � ������" << std::endl;
	TempArr<int> Hint = Gint - 10;
	Hint.Print();
	//15)	�������� mas4, ������� � ���� mas7.�������� ��������� �� �����.�������� mas6 � mas4.
	
	Dint += Hint;
	Dint.Print();



	//16) ����������� ���������� mas4 = mas6.�������� ��������� �� �����
	 
	Dint = Fint;
	Dint.Print();

}
