#include <iostream>
#include <ostream>

// Implement your classes here

using namespace std;
class Complex
{
    public:
    Complex(double real, double imag) : 
        real{real}, imag{imag} {}

    friend ostream& operator<<(ostream& os, const Complex& complex){

        return os << complex.real << "+" << complex.imag << "i";
    }

    friend Complex operator+(const Complex& lhs, const Complex& rhs);

    friend Complex operator*(const Complex& lhs, const Complex& rhs);

    private:
    double real;
    double imag;
};

Complex operator+(const Complex& lhs, const Complex& rhs){
    return Complex{lhs.real+rhs.real, lhs.imag + rhs.imag};
}

Complex operator*(const Complex& lhs, const Complex& rhs){
    return Complex{(lhs.real * rhs.real) - (lhs.imag * rhs.imag), (lhs.real*rhs.imag) + (lhs.imag * rhs.real)};
}

// You may *NOT* modify the main function
int main()
{
    Complex a{1.0, 2.0};
    Complex const b{3.0, 4.0};

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "a + b = " << a + b << std::endl;
    std::cout << "a * b = " << a * b << std::endl;

    return 0;
}