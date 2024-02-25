
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "VectorN.h"
using namespace std;

VectorN makeVector(int N, double* a) {
	VectorN vec;
	vec.Init(N, a);
	return vec;
}


int main()
{
    double values1[] = { 1, 2, 3 };
    double values2[] = { 4, 5, 6 };

    // Створюємо вектори
    VectorN v1;
    v1.Init(3, values1);

    VectorN v2;
    v2.Init(3, values2);

    // Викликаємо методи
    cout << "Vector1:";
    v1.Display();
    cout << endl;

    cout << "Vector2:";
    v2.Display();
    cout << endl;

    cout << "Add:";
    VectorN addition = v1 + v2;
    addition.Display();
    cout << endl;

    cout << "Sub:";
    VectorN subtraction = v1 - v2;
    subtraction.Display();
    cout << endl;

    cout << "Scaliar:";
    double dotProduct = v1.Scaliar(v2);
    cout << dotProduct << endl;
    cout << "Scalar Product in Words: " << v1.numberToWords(dotProduct) << endl << endl;


    VectorN v3;
    VectorN v4;
    v3.Read();
    v4.Read();

    double scaliar = v3.Scaliar(v4);
    cout << scaliar << endl;
    cout << "Scalar Product in Words: " << v3.numberToWords(scaliar) << endl;


    
    
    return 0;
}