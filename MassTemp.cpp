#include "MassiveTemp.h"
#include <iostream>

int main()
{
	TempArr<int> mas1;
	//1)	Создайте объект Array mas1. Занесите в него 5 чисел: 1,2,3,4,5
	//  (элементы вводятся с клавиатуры, для заполнения член-данных используйте функцию Scan).
	//Выведите mas1 на экран, используя функцию Print.

	mas1.Scan();
	std::cout << "1:" << std::endl;
	mas1.Print();

	//2)	Создайте объект Array mas2, инициализировав его при создании объектом mas 1.
	//Выведите mas2 на экран, используя потоковый вывод.

	std::cout << "2:" << std::endl;
	TempArr<int> mas2 = mas1;
	mas2.Print();
	//3)	Сравните массивы mas1 и mas2.

	std::cout << "3:" << std::endl;
	std::cout << "int: " << std::endl;
	if (mas1 == mas2) std::cout << "равны" << std::endl;
	else std::cout << "не равны" << std::endl;
	//4)	Измените mas1 добавив в него число 6. Выведите измененный mas1 на экран.Сравните массивы mas1 и mas2.

	std::cout << "4:" << std::endl;
	mas1 += 6;

	mas1.Print();

	std::cout << "int: " << std::endl;
	if (mas1 == mas2) std::cout << "равны" << std::endl;
	else std::cout << "не равны" << std::endl;
	//5)	Создайте объект Array mas3, который получается добавлением к mas1  числа 7. Выведите mas3 на экран.

	std::cout << "5:" << std::endl;
	TempArr<int> mas3 = mas1 + 7;// += 7;
	mas3.Print();
	//6)	Удалите первый элемент из mas3.Выведите получившийся mas3 на экран.
	std::cout << "6:" << std::endl;

	mas3.DelPosEq(0);

	mas3.Print();
	//7)	Создайте массив mas4, который получается из mas3 удалением последнего элемента.Выведите получившийся mas4 на экран.
	std::cout << "7:" << std::endl;

	int lastInt = mas3.GetN() - 1;

	TempArr<int> mas4 = mas3.DelPosNew(lastInt);

	mas4.Print();
	//8)	Удалите из mas1 элемент key = 1. Проверьте, равны ли mas1 и mas4
	std::cout << "8:" << std::endl;
	mas1 -= 1;

	if (mas1 == mas4) std::cout << "равны" << std::endl;
	else std::cout << "не равны" << std::endl;
	//9)	Введите число n  и сформируйте массив b из n случайных чисел.Создайте объект Array mas5, 
	//		используя конструктор с аргументом - массив.
	std::cout << "9:" << std::endl;
	int n = -1;

	while (n < 0)
	{
		std::cout << "введите число n элементов: " << std::endl;
		std::cin >> n;
		if (n < 0) std::cout << "число меньше 0" << std::endl;
	}

	int* b = new int[n];
	for (int i = 0; i < n; i++)
	{
		b[i] = rand() % 100;
	}

	TempArr<int> mas5(b, n);

	mas5.Print();
	//10)  Найдите максимальный и минимальный элемент в mas5.Выведите на экран эти элементы и их индексы.
	std::cout << "10:" << std::endl;
	std::cout << "max: " << mas5[mas5.Max()] << " min: " << mas5[mas5.Min()] << std::endl;
	//11)	Сортируйте mas5 и выведите результат на экран.
	std::cout << "11:" << std::endl;
	mas5.Sorting();

	mas5.Print();
	//12)	Создайте  объект Array mas6, объединив mas1 и mas5.Выведите результат на экран
	std::cout << "12:" << std::endl;
	TempArr<int> mas6 = mas1 + mas5;

	mas6.Print();
	//13)  Создайте  объект Array mas7 – массив из 4 - х элементов.
	//Заполните член - данные(10, 11, 12, 13), используя потоковый ввод.
	std::cout << "13:" << std::endl;
	TempArr<int> mas7;
	std::cin >> mas7;
	mas7.Print();
	//14)  Проверьте, входят ли в mas7 элементы 1 и 10. Создайте mas8, который получается из mas7 удалением элемента 10.
	std::cout << "14:" << std::endl;
	if (mas7.FindKey(1) != -1) std::cout << "1 входит в массив" << std::endl;
	else std::cout << "1 входит в массив" << std::endl;
	if (mas7.FindKey(10) != -1) std::cout << "10 не входит в массив" << std::endl;
	else std::cout << "10 не входит в массив" << std::endl;
	TempArr<int> mas8 = mas7 - 10;
	mas8.Print();
	//15)	Измените mas4, добавив к нему mas7.Выведите результат на экран.Сравните mas6 и mas4.
	std::cout << "15:" << std::endl;
	mas4 += mas7;

	if (mas6 == mas4) std::cout << "равны" << std::endl;
	else std::cout << "не равны" << std::endl;

	//16) Осуществите присвоение mas4 = mas6.Выведите результат на экран
	std::cout << "7:" << std::endl;
	mas4 = mas6;
	mas4.Print();

}
