#include "VectorN.h"
#include <iostream>
#include <cmath>
#include <string>
#include <sstream> 
using namespace std;

void VectorN::Display() const
{
	cout << endl;
	cout << " N = " << N << endl;
	cout << " a = ";
	for (int i = 0; i < N; ++i) {
		cout << a[i];
		if (i != N - 1)
			cout << ", ";
	}
	cout << endl;
}

//SET
void VectorN::SetN(int value)
{
	N = value;
}

void VectorN::SetA(double* values) {
	a = new double[N];
	for (int i = 0; i < N; ++i) {
		a[i] = values[i];
	}
}

//INIT
bool VectorN::Init(int x, double* y)
{
	SetN(x);
	SetA(y);
	return true;
}

//READ
void VectorN::Read()
{
	int x;
	double* y;
	std::cout << "Input complex value:" << std::endl;
	std::cout << " N = "; std::cin >> x;
	y = new double[x];
	std::cout << " a = ";
	for (int i = 0; i < x; ++i)
		std::cin >> y[i];
	Init(x, y);
	delete[] y;
}

//OPERATORS
VectorN VectorN::operator+(const VectorN & other) const {
	if (N != other.N)
		throw std::invalid_argument("Vectors must have the same dimensions for addition");
	double* resultValues = new double[N];
	for (int i = 0; i < N; ++i)
		resultValues[i] = a[i] + other.a[i];
	VectorN result;
	result.Init(N, resultValues);
	delete[] resultValues;
	return result;
}

VectorN VectorN::operator-(const VectorN& other) const {
	if (N != other.N)
		throw std::invalid_argument("Vectors must have the same dimensions for subtraction");
	double* resultValues = new double[N];
	for (int i = 0; i < N; ++i)
		resultValues[i] = a[i] - other.a[i];
	VectorN result;
	result.Init(N, resultValues);
	delete[] resultValues;
	return result;
}

double VectorN::Scaliar(const VectorN& other) const {
	if (N != other.N)
		throw std::invalid_argument("Vectors must have the same dimensions for dot product");
	double result = 0;
	for (int i = 0; i < N; ++i)
		result += a[i] * other.a[i];
	return result;
}


string VectorN::numberToWords(double scalarProduct) {
   
    int scaliar = scalarProduct;
    
    // Масиви з літерами, що використовуються для перетворення числа в слова
    const string units[] = { "", "odin", "dva", "tri", "chotiri", "piat", "shist", "sim", "visim", "deviat" };
    const string teens[] = { "desiat", "odinatsiat", "dvanatsiat", "trinadsiat", "chitirnatsiat", "piatnadsia", "sichnadsiat", "simnadsiat", "visimnadsiat", "devaitnadsiat" };
    const string tens[] = { "", "", "dvadsiat", "tridsat", "sorok", "piatdesat", "shistdesat", "simdesat", "visimdesat", "devainosto" };
    const string hundreds[] = { "", "sto", "dvista", "trista", "chotirista", "piatsot", "shisot", "simsot", "visimsot", "deviatsot" };
    const string thousands[] = { "", "tisacha", "tisachi", "tisach" };
 

    // Число в словах
    string result;

    int unit = scaliar % 10;
    int ten = (scaliar % 100) / 10;
    int hundred = (scaliar % 1000) / 100;
    int thousand = (scaliar % 10000) / 1000;

    if (thousand > 0) {
        result += hundreds[thousand] + " ";
    }
    if (hundred > 0) {
        result += hundreds[hundred] + " ";
    }
    if (ten > 1) {
        result += tens[ten] + " ";
        result += units[unit] + " ";
    }
    else if (ten == 1) {
        result += teens[unit] + " ";
    }
    else {
        result += units[unit] + " ";
    }

    return result;
}