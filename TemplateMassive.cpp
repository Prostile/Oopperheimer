#include <iostream>
#include "MassiveTemp.cpp"

using namespace std;

int main()
{
	//1
	cout << "1) ";
	MassiveTemp<int> mas1;
	mas1.Scan(5);
	cout << "mas1: ";
	mas1.Print();
	cout << endl;
	//2
	cout << "2) "; cout << endl;
	MassiveTemp<int> mas2(mas1);
	cout << "mas2: " << mas2 << endl;
	//3
	cout << "3) "; cout << endl;
	if (mas1 == mas2)cout << "equal" << endl;
	else cout << "nonequal" << endl;
	//4
	cout << "4) "; cout << endl;
	mas1 += 6;
	cout << "mas1: ";
	mas1.Print();
	cout << endl;
	//5
	cout << "5) "; cout << endl;
	MassiveTemp<int> mas3 = mas1 + 7;
	cout << "mas3: ";
	mas3.Print();
	cout << endl;
	//6
	cout << "6) "; cout << endl;
	mas3.DelPosEq(0);
	cout << "mas3: ";
	mas3.Print();
	cout << endl;
	//7
	cout << "7) "; cout << endl;
	MassiveTemp<int> mas4 = mas3.DelPosNew(mas3.GetN() - 1);
	cout << "mas4: ";
	mas4.Print();
	cout << endl;
	//8
	cout << "8) "; cout << endl;
	mas1.DelPosEq(1);
	if (mas1 == mas2)cout << "equal" << endl;
	else cout << "nonequal" << endl;
	//9
	cout << "9) "; cout << endl;
	cout << "input N: ";
	int* b, n;
	cin >> n;
	b = new int[n];
	for (int i = 0; i < n; i++)
	{
		b[i] = rand() % 100;
	}
	MassiveTemp<int> mas5(b, n);
	cout << "mas5: ";
	mas5.Print();
	cout << endl;
	//10
	cout << "10) "; cout << endl;
	cout << "Max element: " << mas5.Max() << " Min element: " << mas5.Min() << endl;
	//11
	cout << "11) "; cout << endl;
	mas5.Sorting();
	cout << "mas5: ";
	mas5.Print();
	cout << endl;
	//12
	cout << "12) "; cout << endl;
	MassiveTemp<int> mas6 = mas1 + mas5;
	cout << "mas6: ";
	mas6.Print();
	cout << endl;
	//13
	cout << "13) "; cout << endl;
	MassiveTemp<int> mas7(4);
	cout << "input 4 elements of mas7" << endl;
	cin >> mas7;
	//14
	cout << "14) "; cout << endl;
	if ((mas7.FindKey(1) != -1) && (mas7.FindKey(10) != -1)) cout << "mas7 has included elements 1 and 10" << endl;
	else cout << "mas7 has no included elements 1 and 10" << endl;
	MassiveTemp<int> mas8 = mas7.DelPosNew(10);
	//15
	cout << "15) "; cout << endl;
	mas4 += mas7;
	cout << "mas4: ";
	mas4.Print();
	cout << endl;
	if (mas4 == mas6)cout << "equal" << endl;
	else cout << "nonequal" << endl;
	//16
	cout << "16) "; cout << endl;
	mas4 = mas6;
	cout << "mas4: ";
	mas4.Print();
	cout << endl;
}