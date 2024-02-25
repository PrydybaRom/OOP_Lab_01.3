#include <iostream>
#include <stdexcept>

class VectorN {
private:
    double* a;
    int N;
public:
    // Конструктор, що приймає розмірність та масив дійсних чисел
    VectorN(int size, double* values) : N(size) {
        a = new double[N];
        for (int i = 0; i < N; ++i) {
            a[i] = values[i];
        }
    }

    // Деструктор для звільнення виділеної пам'яті
    ~VectorN() {
        delete[] a;
    }

    int size() const {
        return N;
    }

    // Оператор додавання векторів
    VectorN operator+(const VectorN& other) const {
        if (size() != other.size())
            throw std::invalid_argument("Vectors must have the same dimensions for addition");
        double* resultValues = new double[N];
        for (int i = 0; i < N; ++i)
            resultValues[i] = a[i] + other.a[i];
        VectorN result(N, resultValues);
        delete[] resultValues;
        return result;
    }

    // Оператор віднімання векторів
    VectorN operator-(const VectorN& other) const {
        if (size() != other.size())
            throw std::invalid_argument("Vectors must have the same dimensions for subtraction");
        double* resultValues = new double[N];
        for (int i = 0; i < N; ++i)
            resultValues[i] = a[i] - other.a[i];
        VectorN result(N, resultValues);
        delete[] resultValues;
        return result;
    }

    // Метод для обчислення скалярного добутку векторів
    double dot_product(const VectorN& other) const {
        if (size() != other.size())
            throw std::invalid_argument("Vectors must have the same dimensions for dot product");
        double result = 0;
        for (int i = 0; i < N; ++i)
            result += a[i] * other.a[i];
        return result;
    }

    // Метод для виводу вектора на екран
    void print() const {
        std::cout << "VectorN[";
        for (int i = 0; i < N; ++i) {
            std::cout << a[i];
            if (i != N - 1)
                std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
};

int main() {
    double values1[] = { 1, 2, 3 };
    double values2[] = { 4, 5, 6 };

    VectorN v1(3, values1);
    VectorN v2(3, values2);

    std::cout << "v1: ";
    v1.print();
    std::cout << "v2: ";
    v2.print();

    VectorN addition = v1 + v2;
    std::cout << "Addition: ";
    addition.print();

    VectorN subtraction = v1 - v2;
    std::cout << "Subtraction: ";
    subtraction.print();

    double dotProduct = v1.dot_product(v2);
    std::cout << "Dot Product: " << dotProduct << std::endl;

    return 0;
}
