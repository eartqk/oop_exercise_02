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
    Modulo(T a, T b)
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
        if (other.number == 0)
        {
            std::cout << "You can't divide by zero" << std::endl;
            return Modulo<T>(number % N, N);
        };
        return Modulo<T>((number / other.number) % N, N);
    };
    // Assignment via copy operator
    Modulo &operator=(const Modulo<T> &other)
    {
        number = other.number;
        N = other.N;
        return *this;
    };
    // Compare operators
    bool operator==(const Modulo<T> &other) const
    {
        return number == other.number;
    };
    bool operator!=(const Modulo<T> &other) const
    {
        return number != other.number;
    };
    bool operator>(const Modulo<T> &other) const
    {
        return number > other.number;
    };
    bool operator<(const Modulo<T> &other) const
    {
        return number < other.number;
    };
    bool operator>=(const Modulo<T> &other) const
    {
        return ((*this) > other) || ((*this) == other);
    };
    bool operator<=(const Modulo<T> &other) const
    {
        return ((*this) < other) || ((*this) == other);
    };
    // Output operator
    friend std::ostream &operator<<(std::ostream &out, const Modulo<T> &instance)
    {
        out << instance.number;
        return out;
    };
};

// Prints help information
void help()
{
    std::cout << "Available commands:" << std::endl;
    std::cout << "  'plus number1 number2 module'" << std::endl;
    std::cout << "  'minus number1 number2 module'" << std::endl;
    std::cout << "  'mul number1 number2 module'" << std::endl;
    std::cout << "  'div number1 number2 module'" << std::endl;
    std::cout << "Type 'help' to get this information." << std::endl;
    std::cout << "Type 'quit' or 'q' to quit." << std::endl;
};

int main()
{
    help();
    std::string cmd;

    while (true)
    {
        std::cout << ">>> ";
        std::cin >> cmd;
        // Checking for exit commands
        if (cmd == "quit" || cmd == "q")
        {
            std::cin.clear();
            std::cin.ignore();
            break;
        }
        // Checking for entering commands
        else if (cmd != "plus" && cmd != "minus" && cmd != "mul" && cmd != "div" || cmd == "help")
        {
            std::cin.clear();
            std::cin.ignore();
            help();
            continue;
        };

        // Entering numbers and checking if they are correct
        long long num1, num2, mod;
        std::cin >> num1 >> num2 >> mod;
        if (std::cin.fail() || mod == 0)
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Invalid input" << std::endl;
            continue;
        };
        // Creating three numbers by Modulo
        Modulo<long long> n1(num1, mod), n2(num2, mod), n3(0, mod);

        // Executing commands
        if (cmd == "plus")
        {
            n3 = n1 + n2;
        }
        else if (cmd == "minus")
        {
            n3 = n1 - n2;
        }
        else if (cmd == "mul")
        {
            n3 = n1 * n2;
        }
        else if (cmd == "div")
        {
            n3 = n1 / n2;
        }
        // Printing result
        std::cout << n3 << std::endl;
    };
};
