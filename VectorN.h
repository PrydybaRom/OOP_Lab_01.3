#pragma once
#include <string>


class VectorN
{
	int N; 
	double* a;
public:
	int GetN() const { return N; }
	double GetA() const { return *a; }

	void SetN(int value);
	void SetA(double* value);

	bool Init(int, double*);
	void Read();
	void Display() const;

	VectorN operator+(const VectorN& other) const;
	VectorN operator-(const VectorN& other) const;
	double Scaliar(const VectorN& other) const;

	std::string numberToWords(double scalarProduct);

	~VectorN() {
		delete[] a;
	}
};



