#pragma once
#pragma once
#include <iostream>
#include <algorithm>

template <typename T>
class TempArr
{
    T* a;
    int n;

    void ShiftLeft(int);

public:
    TempArr(int m = 1);
    TempArr(T* b, int m);
    TempArr(const TempArr<T>&);
    TempArr& operator= (const TempArr<T>&);
    ~TempArr();

    void Scan();
    void Print();

    T& operator [] (int)const;
    int FindKey(int);

    TempArr<T>& operator+= (T X);
    TempArr<T>  operator+ (T key);
    TempArr<T>& operator+= (TempArr<T>& X);
    TempArr<T> operator+ (TempArr<T>& X);
    
    TempArr<T>& operator-= (T X);
    TempArr<T>  operator- (T key);

    TempArr<T>& DelPosEq(int k);
    TempArr<T> DelPosNew(int k);

    bool operator== (const TempArr<T>&)const;
    bool operator!= (const TempArr<T>&) const;

    int Max();
    int Min();
    void Sorting();

    template <class T> friend std::ostream& operator<< (std::ostream& r, TempArr<T>& X);
    template <class T> friend std::istream& operator>> (std::istream& r, TempArr<T>& X);

    int GetN() { return n; }
};


template <class T>
void TempArr<T>::ShiftLeft(int pos)
{
    T* Ta = new T[n - 1];
    for (int i = 0; i < pos; i++) Ta[i] = a[i];
    for (int i = pos; i < n - 1; i++) Ta[i] = a[i + 1];
    delete[] a;
    a = Ta;
    n--;
}

template <class T>
TempArr<T>::TempArr(int m)
{
    a = new T[m];
    n = m;
    for (int i = 0; i < n; i++) a[i] = 0;
}

template <class T>
TempArr<T>::TempArr(T* b, int m) : n(std::max(0, m)), a(new T[n])
{
    std::copy(b, b + n, a);
}

template <class T>
TempArr<T>::TempArr(const TempArr& X): TempArr(X.a,X.n){}

template <class T>
TempArr<T>& TempArr<T>::operator= (const TempArr& X)
{
    if (*this != X)
    {
        delete[]a;
        n = X.n;
        a = new T[n];
        for (int i = 0; i < n; i++)
            a[i] = X.a[i];
    }
    return *this;
}

template <class T>
TempArr<T>::~TempArr()
{
    delete[]a;
}

template <class T>
void TempArr<T>::Scan()			
{
    int m;
    std::cout << "enter num of elements: " << std::endl;
    std::cin >> m;
    std::cout << "enter " << m << " elements: ";
    if (n != m)
    {
        delete[]a;   n = m;
        a = new T[m];
    }
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    std::cout << std::endl;
}

template <class T>
void TempArr<T>::Print()     			 
{
    for (int i = 0; i < n; i++)
        std::cout << a[i] << ' ';
    std::cout << std::endl;
}

template <class T>
T& TempArr<T>::operator [] (int k)const
{
    try {
        if (k < 0)
            throw "index <0";
        if (k > n)
            throw "index > maxindex";
        return a[k];
    }
    catch (char* s)
    {
        std::cout << s;
        return a[-1];
    }
}

template <class T>
int TempArr<T>::FindKey(int key)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key) return i;
    }
    return -1;
}

template <class T>
TempArr<T>& TempArr<T>::operator+= (T key)
{
    int i; 
    T* t = new T[n + 1];
    for (i = 0; i < n; i++)  t[i] = a[i];
    t[n] = key;
    delete[]a;
    a = t;   n++;
    return *this;
}

template <class T>
TempArr<T> TempArr<T>::operator+ (T key)
{
    TempArr<T> Res(n + 1);
    for (int i = 0; i < n; i++)
        Res.a[i] = a[i];
    Res.a[n] = key;
    return Res;
}

template <class T>
TempArr<T>& TempArr<T>::operator+= (TempArr<T>& X)
{
    TempArr<T> Temp(a, n);
    int N = n + X.n;
    delete[] a;
    a = new T[N];
    for (int i = 0; i < n; i++) a[i] = Temp.a[i];
    for (int i = n,j=0; i < N; i++,j++) a[i] = X.a[j];
    n = N;
    return *this;
}

template <class T>
TempArr<T> TempArr<T>::operator+ (TempArr<T>& X)
{
    TempArr<T> b(a, n);
    b += X;
    return b;
}

template <class T>
TempArr<T>& TempArr<T>::operator-= (T X)
{
    int ind = FindKey(X);
    ShiftLeft(ind);
    return *this;
}

template <class T>
TempArr<T> TempArr<T>::operator- (T key)
{
    TempArr<T> k(n - 1);
    int Tkey = FindKey(key);
    for (int i = 0; i < n - 1; i++)
    {
        if (i < Tkey) {
            k.a[i] = a[i];
         }
         else k.a[i] = a[i + 1];
    }
    return k;
}

template <class T>
TempArr<T>& TempArr<T>::DelPosEq(int k)
{
    ShiftLeft(k);
    return *this;
}

template <class T>
TempArr<T> TempArr<T>::DelPosNew(int k)
{
    TempArr<T> d(a, n);
    d.ShiftLeft(k);
    return d;
}

template <class T>
bool TempArr<T>::operator== (const TempArr<T>& X)const
{
    if (n == X.n)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] == X[i]);
            else return false;
        }
        return true;
    }
    else return false;
}

template <class T>
bool TempArr<T>::operator!= (const TempArr<T>& X)const
{
    //if (n != X.n)
    //{
    //    for (int i = 0; i < n; i++)
    //    {
    //        if (a[i] != X[i]);
    //        else return false;
    //    }
    //    return true;
    //}
    //else return false;
    //
    if(!(*this==X))return true;
    else return false;
}

template <class T>
int TempArr<T>::Max()
{
    if (n <= 0) return -1;
    int Mi = 0; T M = a[0];
    for (int i = 1; i < n; i++)
    {
        if (M < a[i]) { M = a[i]; Mi = i; }
    }
    return Mi;
}

template <class T>
int TempArr<T>::Min()
{
    if (n <= 0) return -1;
    int mi = 1; T m = a[0];
    for (int i = 0; i < n; i++)
    {
        if (m > a[i]) { m = a[i]; mi = i; }
    }
    return mi;
}

template <class T>
void TempArr<T>::Sorting()
{
    std::sort(a, a + n);
}

template <class T>
std::ostream& operator<< (std::ostream& r, TempArr<T>& X)
{
    r << "number of elemets: " << X.n << std::endl;
    for (int i = 0; i < X.n; i++)
    {
        r << X.a[i] << " ";
    }
    return r;
}

template <class T>
std::istream& operator>> (std::istream& r, TempArr<T>& X)
{
    std::cout << "enter the number of elements: ";
    int m;    std::cin >> m;
    if (X.n != m)
    {
        delete[]X.a;
        X.a = new T[m];  X.n = m;
    }
    std::cout << "enter " << m << " elements of TempArr: ";
    for (int i = 0; i < X.n; i++) r >> X.a[i];
    return r;
}
