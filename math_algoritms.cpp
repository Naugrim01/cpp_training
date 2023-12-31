#include <iostream>
#include <cmath>
#include "math_algoritms.h"
#include "training_functions.h"


void is_prime_number()
{
    bool check = true;
    int a;
    do
    {
        std::cout << "Please insert the number, the program will check is it prime number or not\n";
        std::cin >> a;
    }while(!isRight());

    for (unsigned int i = 2; i <= sqrt(a); i++)
    {
        if (a <= 1)
        {
            check = false;
            break;
        }
        if (!(a % i))
        {
            std::cout << "this number is not prime number\n";
            check = false;
            break;
        }
    }
    if (check)
        std::cout << "this number is prime number\n";

}

void prime_number_generator()
{
    bool check = true;
    unsigned int a = 2, b = 0;
    do
    {
        std::cout << "Please enter the number of prime numbers to generate:\n";
        std::cin >> b;

    } while (!isRight());
    for (unsigned int i = 0; i < b; i++)
    {
        check = true;
        for (unsigned int j = 2; j <= sqrt(a); j++)
        {
            if (!(a % j))
            {
                check = false;
                break;
            }
        }
        if (check)
            std::cout << i + 1 << ". " << a << '\n';
        else
            i--;
        a++;
    }
}

void prime_number_generator_sieve_of_eratosthenes()
{
    unsigned int tmp, tmp2 = 1;
    unsigned int top_border;
 do
 {
    std::cout << "enter the upper range to which the generation of prime numbers is to be made:\n";
    std::cin >> top_border;
 } while (!isRight());

    bool* numbers_to_check;
    numbers_to_check = new bool[top_border + 1];

    for (unsigned int i = 2; i <= top_border; i++)
    {
        numbers_to_check[i] = true;
    }

    for (unsigned int i = 2; i <= top_border; i++)
    {
        if ((i != 2) && (i % 2 == 0))
            i++;
        tmp = i + i;
        while (tmp <= top_border)
        {
            numbers_to_check[tmp] = false;
            tmp += i;
        }
    }

    for (unsigned int i = 2; i <= top_border; i++)
    {
        if (numbers_to_check[i])
        {
            std::cout << tmp2 << ". " << i << '\n';
            tmp2++;
        }
    }

    delete[] numbers_to_check;
}

void euclidean_algorithm()
{
    int a, b;
    do
    {
        std::cout << "enter first number:\n";
        std::cin >> a;
    } while (!isRight());
    do
    {
    std::cout << "enter second number:\n";
    std::cin >> b;
    } while (!isRight());

    while (a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }

    std::cout << "the greatest common divisor is:\n" << a << '\n';
}

void euclidean_algorithm_modulo()
{
    int a, b, r;
    do
    {
        std::cout << "enter first number:\n";
        std::cin >> a;
    } while (!isRight());
    do
    {
        std::cout << "enter second number:\n";
        std::cin >> b;
    } while (!isRight());


    while (r = a % b)
    {
        a = b;
        b = r;
    }

    std::cout << "the greatest common divisor is:\n" << b << '\n';
}

void factorial_iteratively()
{
    short int a;
    unsigned long long factorial = 1;
    do
    {
    std::cout << "enter number count factorial(0-20):\n";
    std::cin >> a;
    system("cls");
    } while (!isRight() || a < 1 || a > 20);
    
    for (short int i = 1; i <= a; i++)
    {
        factorial *= i;
        std::cout << i << ". factorial " << factorial << '\n';
    }
}

unsigned long long factorial(short int n)
{
    if (n == 1)
        return 1;

    return (factorial(n - 1) * n);
}

void factorial()
{
    short int a;
    unsigned long long factorial_number = 1;
    do
    {
        std::cout << "enter number count factorial(0-20):\n";
        std::cin >> a;
        system("cls");
    } while (!isRight() || a < 1 || a > 20);

    if (factorial_number != 0)
        factorial_number = factorial(a);

    std::cout << "the factorial:\n" << factorial_number << '\n';

}

void fibonacci_iteratively()
{
    int n;
    unsigned long long left = 0, right = 1, total = 1;

    do
    {
        std::cout << "enter number of fibonacci sequence(0-93):\n";
        std::cin >> n;
        system("cls");
    } while (!isRight() || n < 0 || n > 93);

    if (n == 0)
    {
        total = 0;
        std::cout << '0' << ". fibonacci sequence is: " << total << '\n';
    }
    else if (n == 1)
    {
        total = 1;
        std::cout << '0' << ". fibonacci sequence is: " << '0' << '\n';
        std::cout << '1' << ". fibonacci sequence is: " << total << '\n';
    }
    else
    {
        std::cout << '0' << ". fibonacci sequence is: " << '0' << '\n';
        std::cout << '1' << ". fibonacci sequence is: " << total << '\n';

        for (int i = 2; i <= n; i++)
        {
            total = left + right;
            left = right;
            right = total;
            std::cout << i << ". fibonacci sequence is: " << total << '\n';
        }
    }

}

int fibonacci_recursively(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci_recursively(n - 1) + fibonacci_recursively(n - 2);
}

void fibonacci_recursively()
{
    int n;

    do
    {
        std::cout << "enter number of fibonacci sequence(0 - 40):\n";
        std::cin >> n;
        system("cls");
    }while (!isRight() || n < 0 || n > 40);

    std::cout << n << ". fibonacci sequence is: " << fibonacci_recursively(n) << '\n';
}

unsigned long long exponentiation(int base, int exponent)
{
    if (exponent == 0)
        return 1;
    else
        return base * exponentiation(base, exponent - 1);
}

void exponentiation()
{
    int base, exponent;
    do
    {
    std::cout << "enter base:\n";
    std::cin >> base;
    } while (!isRight());
    do
    {
    std::cout << "enter exponent:\n";
    std::cin >> exponent;
    } while (!isRight());
    std::cout << "exponentiation:" << exponentiation(base, exponent) << '\n';
}