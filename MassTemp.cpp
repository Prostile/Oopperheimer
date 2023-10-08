#include "MassiveTemp.h"
#include <iostream>

int main()
{
	TempArr<int> Aint;
	//1)	Создайте объект Array mas1. Занесите в него 5 чисел: 1,2,3,4,5
	//  (элементы вводятся с клавиатуры, для заполнения член-данных используйте функцию Scan).
	//Выведите mas1 на экран, используя функцию Print.

	Aint.Scan();
	std::cout << "1:" << std::endl;
	Aint.Print();

	//2)	Создайте объект Array mas2, инициализировав его при создании объектом mas 1.
	//Выведите mas2 на экран, используя потоковый вывод.

	std::cout << "2:" << std::endl;
	TempArr<int> Bint = Aint;
	Bint.Print();
	//3)	Сравните массивы mas1 и mas2.

	std::cout << "3:" << std::endl;
	std::cout << "int: " << std::endl;
	if (Aint == Bint) std::cout << "равны" << std::endl;
	else std::cout << "не равны" << std::endl;
	//4)	Измените mas1 добавив в него число 6. Выведите измененный mas1 на экран.Сравните массивы mas1 и mas2.

	std::cout << "4:" << std::endl;
	Aint += 2;

	Aint.Print();

	std::cout << "int: " << std::endl;
	if (Aint == Bint) std::cout << "равны" << std::endl;
	else std::cout << "не равны" << std::endl;
	//5)	Создайте объект Array mas3, который получается добавлением к mas1  числа 7. Выведите mas3 на экран.

	std::cout << "5:" << std::endl;
	TempArr<int> Cint = Aint += 7;
	Cint.Print();
	//6)	Удалите первый элемент из mas3.Выведите получившийся mas3 на экран.
	std::cout << "6:" << std::endl;

	Cint -= 0;

	Cint.Print();
	//7)	Создайте массив mas4, который получается из mas3 удалением последнего элемента.Выведите получившийся mas4 на экран.
	std::cout << "7:" << std::endl;
	int lastInt = Cint.GetN() - 1;
		//std::cout << lastInt << " " << lastFloat << " " << lastChar;

	Cint -= lastInt;
	TempArr<int> Dint = Cint;

	Dint.Print();
	//8)	Удалите из mas1 элемент key = 1. Проверьте, равны ли mas1 и mas4
	
	Aint -= Aint.FindKey(1);

	if (Aint == Dint) std::cout << "равны" << std::endl;
	else std::cout << "не равны" << std::endl;
	//9)	Введите число n  и сформируйте массив b из n случайных чисел.Создайте объект Array mas5, 
	//		используя конструктор с аргументом - массив.
	int n = -1;

	while (n < 0)
	{
		std::cout << "введите число n элементов: " << std::endl;
		std::cin >> n;
		if (n < 0) std::cout << "число меньше 0" << std::endl;
	}

	int* bInt = new int[n];
	for (int i = 0; i < n; i++)
	{
		bInt[i] = rand() % 100;
	}

	TempArr<int> Eint(bInt, n);

	Eint.Print();
	//10)  Найдите максимальный и минимальный элемент в mas5.Выведите на экран эти элементы и их индексы.
	 
	std::cout << "max: " << Eint[Eint.Max()] << " min: " << Eint[Eint.Min()] << std::endl;
	//11)	Сортируйте mas5 и выведите результат на экран.
	
	Eint.Sorting();

	Eint.Print();
	//12)	Создайте  объект Array mas6, объединив mas1 и mas5.Выведите результат на экран

	TempArr<int> Fint = Aint + Eint;

	Fint.Print();
	//13)  Создайте  объект Array mas7 – массив из 4 - х элементов.
	//Заполните член - данные(10, 11, 12, 13), используя потоковый ввод.
	
	TempArr<int> Gint(4);
	std::cout << "введите 4 элемента: ";
	for (int i = 0; i < 4; i++)
	{
		int n; std::cin >> n; Gint[i] = n;
	}
	Gint.Print();
	//14)  Проверьте, входят ли в mas7 элементы 1 и 10. Создайте mas8, который получается из mas7 удалением элемента 10.
	
	if (Gint.FindKey(1) != -1) std::cout << "1 входит в массив" << std::endl;
	else std::cout << "1 не входит в массив" << std::endl;
	if(Gint.FindKey(10) != -1) std::cout << "10 входит в массив" << std::endl;
	else std::cout << "10 не входит в массив" << std::endl;
	TempArr<int> Hint = Gint - 10;
	Hint.Print();
	//15)	Измените mas4, добавив к нему mas7.Выведите результат на экран.Сравните mas6 и mas4.
	
	Dint += Hint;
	Dint.Print();



	//16) Осуществите присвоение mas4 = mas6.Выведите результат на экран
	 
	Dint = Fint;
	Dint.Print();

}
