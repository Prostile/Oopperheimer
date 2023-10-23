#pragma once
#включить <iostream>
#включить <алгоритм>

шаблон <имя типа T>
класс TempArr
{
 T * a; 
 int n;

 аннулирует ShiftLeft(int);

public:
 TempArr(int m = 1);
 TempArr(T * b, int m);
 TempArr(постоянная температура<T>&);
 TempArr& operator= (const TempArr<T>&);
 ~TempArr();

 аннулирует сканирование();
 аннулирует печать();

 T& operator [] (int) const;
 int FindKey(int);

 TempArr<T>& operator+= (T X);
 TempArr<T> оператор+ (клавиша T);
 TempArr<T>& оператор+= (TempArr<T>& X);
 TempArr<T> оператор+ (TempArr<T>& X);

 TempArr<T>& operator-= (T X);
 TempArr<T> оператор- (клавиша T);

 TempArr<T>& DelPosEq(int X);
 TempArr<T> DelPosNew(ключ int);

 оператор bool== (TempArr<T>&);
 оператор bool!= (const TempArr<T>&) const;

 int Max();
 int Min();
 сортировка пустоты();

 шаблон <класс T> friend std::ostream& operator<< (std::ostream& r, TempArr<T>& X);
 шаблон <class T> friend std::istream& operator>> (std::istream& r, TempArr<T>& X);

 int GetN() { возвращает n; }
};


шаблон <класс T>
аннулирует TempArr<T>::ShiftLeft(int pos)
{
 T * Ta = новое T[n - 1]; 
 для (int i = 0; i < pos; i++) Ta[i] = a[i];
 для (int i = pos; i < n - 1; i++) Ta[i] = a[i + 1];
 удалить[] a;
 a = Ta;
}

шаблон <класс T>
TempArr<T>::TempArr(int m)
{
 std::cout << "ааааа" << std::endl;
 a = новый T[m];
 n = m; 
 для (int i = 0; i < n; i++) a[i] = 0;
}

шаблон <класс T>
TempArr<T>::TempArr(T* b, int m)
 : n(std::max(0,m))
 , a(новое значение T[n])
{
 std::копировать(b, b + n, a);
}

шаблон <класс T>
TempArr<T>::TempArr(const TempArr& X) : TempArr(X.a, X.n) {}

шаблон <класс T>
TempArr<T>& TempArr<T>::operator= (const TempArr& X)
{
 if (*this != X)
 { 
 удалить[]a;
 n = X.n;
 a = новый T[n];
 for (int i = 0; i < n; i++)
 a[i] = X.a[i];
 }
 возвращает *этот;
}

шаблон <класс T>
TempArr<T>::~TempArr()
{
 удалить[]a;
}

шаблон <класс T>
void TempArr<T>::Сканировать() //???? ??????? ?? m ??-???? ??????????
{
 int m;
 std::cout << "введите количество элементов: " << std::endl;
 std::cin >> m;
 std::cout << "ввести" << m << "элементы: "; 
 if (n != m)
 { 
 удалить[]a; n = m;
 a = создать T[m];
 } 
 for (int i = 0; i < n; i++)
 std::cin >> a[i];
 std::cout << std::endl;
}

шаблон <класс T>
аннулирует TempArr<T>::Print() //????? ??????? ?? ???????
{
 для (int i = 0; i < n; i++)
 std::cout << a[i] << ' ';
 std::cout << std::endl;
}

шаблон <класс T>
T& TempArr<T>::operator [] (int k) const //?????????? я-?? ??-????????? a 
{
 попробуй {
 if (k < 0) 
 выбросить 0; 
 if (k >= n)
 выбросить "неправильный индекс";
 вернуть a[k];
 }
 поймать (int m)
 { 
 std::cout << "index <0";
 возвращает a[m];
 }
 catch (char * s)
 {
 std::cout << s; 
 возвращает a[n - 1];
 }
 catch (...)
 { 
 std::cout << "неверный индекс";
 возвращает a[0];
 }
}

шаблон <класс T>
int TempArr<T>::FindKey (ключ int)
{
 for (int i = 0; i < n; i++)
 { 
 if (a[i] == ключ) возвращает i;
 } 
 возвращает -1;
}

шаблон <класс T>
TempArr<T>& TempArr<T>::оператор+= (клавиша T)
{
 int i; T* t;
 t = создать T[n + 1]; 
 для (i = 0; i < n; i++) t[i] = a[i];
 t[n] = ключ;
 удалить[]a;
 a = t; n++;
 возвращает * этот;
}

шаблон <класс T>
TempArr<T> TempArr<T>::оператор+ (клавиша T)
{
 TempArr<T> Res(n + 1);
 для (int i = 0; i < n; i++)
 Res.a[i] = a[i];
 Res.a[n] = ключ;
 возвращать Res; 
}

шаблон <класс T>
TempArr<T>& TempArr<T>::оператор+= (TempArr<T>& X)
{
 TempArr<T> Temp(a, n); 
 int N = n + X.n;
 удалить[] a;
 a = создать T[N];
 for (int i = 0; i < n; i++) a[i] = Temp.a[i];
 for (int i = n, j = 0; i < N; i++, j++) a[i] = X.a[j];
 n = N; 
 возвращает *этот;
}

шаблон <класс T>
TempArr<T> TempArr<T>::оператор+ (TempArr<T>& X)
{
 TempArr<T> b(a, n);
 b += X; 
 возвращает b;
}

шаблон <класс T>
TempArr<T>& TempArr<T>::оператор-= (T X)
{
 //Температура<T> k(n - 1); 
 ////Смещение (ind);
 //int ind = FindKey(X); 
 //для (int i = 0; i < n - 1; i++)
 //{
 // если (ind == i) {
 // k.a[i] = a[i + 1];
 // i++;
 // }
 // к.a[i] = a[i];
 //}
 //n--; 
 int ind = FindKey(X);
 ShiftLeft(ind);
 возвращает *этот;
}

шаблон <класс T>
TempArr<T> TempArr<T>::оператор- (клавиша T)
{
 TempArr<T> k(n - 1); 
 int Tkey = FindKey(ключ);
 for (int i = 0; i < n - 1; i++)
 { 
 если (Tkey == i) { 
 k.a[i] = a[i + 1];
 }
 else k.a[i] = a[i];
 }
 //n -= 1; 
 возвращает k;
}

шаблон <класс T>
TempArr<T>& TempArr<T>::DelPosEq(int k)
{
 ShiftLeft(k);
 возвращает *это; 
}

шаблон <класс T>
TempArr<T> TempArr<T>::DelPosNew(ключ ввода)
{
 TempArr<T> k(n - 1);
 for (int i = 0; i < n - 1; i++)
 { 
 если (ключ == i) { 
 k.a[i] = a[i + 1];
 }
 else k.a[i] = a[i];
 }
 //n -= 1; 
 возвращает k;
}

шаблон <класс T>
bool TempArr<T>::оператор== (TempArr<T>& X)
{
 если (n == X.n)
 {
 для (int i = 0; i < n; i++)
 { 
 if (a[i] == X[i]);
 else возвращает false;
 } 
 возвращает true;
 } 
 else возвращает false;
}

шаблон <класс T>
bool TempArr<T>::оператор!= (const TempArr<T>& X) const
{
 если (n != X.n)
 {
 for (int i = 0; i < n; i++)
 { 
 if (a[i] != X[i]);
 else возвращает false;
 } 
 возвращает true;
 } 
 else возвращает false;
 /*

 if(!(*this==X))возвращает true;
 else возвращает false;
 */
}

шаблон <класс T>
int TempArr<T>::Max()
{
 if (n <= 0) { 
 возвращает значение -1;
 }

 int Mi = 0; T M = a[0];
 for (int i = 1; i < n; i++)
 { 
 if (M < a[i]) { M = a[i]; Mi = i; }
 }
 возвращает Mi;
}

шаблон <класс T>
int TempArr<T>::Min()
{
 if (n <= 0) { 
 возвращает значение -1; 
 }

 int mi = 0; T m = a[0];
 для (int i = 1; i < n; i++)
 { 
 if (m > a[i]) {m = a[i]; mi = i; }
 }
 возвращает mi;
}

шаблон <класс T>
аннулирует TempArr<T>::Сортировка()
{
 std::сортировка(a, a + n);
}

шаблон <класс T>
std::ostream& operator<< (std::ostream& r, TempArr<T>& X)
{
 r << "количество элементов: " << X.n << std::endl;
 для (int i = 0; i < X.n; i++)
 {
 r << X.a[i] << " ";
 } 
 возвращает r;
}

шаблон <класс T>
std::istream& operator>> (std::istream& r, TempArr<T>& X)
{
 std::cout << "введите количество элементов: "; 
 int m; std::cin >> m; 
 if (X.n != m)
 { 
 удалить[]X.a;
 X.a = новое T[m]; X.n = m;
 } 
 std::cout << "ввести" << m << "элементы TempArr: "; 
 for (int i = 0; i < X.n; i++) r >> X.a[i];
 возвращать r; 
}
