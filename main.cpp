/*
  Артамонов Олег
  https://github.com/eartqk
  Создать класс Modulo для работы с целыми числами по модулю N.
  В классе должно быть два поля: число и N. Реализовать все арифметические
  операции.
  Реализовать операции сравнения. Операции сложения, вычитания, умножения,
  деления, сравнения (на равенство, больше и меньше) должны быть выполнены в
  виде перегрузки операторов. Необходимо реализовать пользовательский литерал
  для работы с константами типа Modulo.
*/

#include <iostream>
#include <string>

template <typename T> class Modulo
{
    // Сlass fields
  private:
    T number;
    T N;

  public:
    // Class constructor
    Modulo()
    {
        number = 0;
        N = 1;
    };
    Modulo(int a, int b)
    {
        N = b;
        number = a % b;
    };
    // Arithmetical operations
    Modulo operator+(const Modulo<T> &other) const
    {
        return Modulo<T>((number + other.number) % N, N);
    };
    Modulo operator-(const Modulo<T> &other) const
    {
        return Modulo<T>((number - other.number) % N, N);
    };
    Modulo operator*(const Modulo<T> &other) const
    {
        return Modulo<T>((number * other.number) % N, N);
    };
    // Euler's theorem
    Modulo operator/(const Modulo<T> &other) const
    {
        return Modulo<T>(((*this) * pow(other, Modulo(N - 2, N))).number % N, N);
    };
    // Exponentiation modulo via recursion
    Modulo operator^(const Modulo<T> exp) const
    {
        if (exp.number == 0)
        {
            return Modulo<T>(1, N);
        };
        if (exp.number % 2 == 1)
        {
            return Modulo(((*this) ^ Modulo(exp.number - 1, N) * (*this)).number % N, N);
        };
        Modulo<T> tmp = ((*this) ^ Modulo(exp.number / 2, N));
        return Modulo<T>((tmp.number * tmp.number) % N, N);
    };
    // Copy assignment
    Modulo &operator=(const Modulo<T> &other)
    {
        number = other.number;
        N = other.N;
        return *this;
    };
};
