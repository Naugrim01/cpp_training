#include <iostream>
#include <cmath>
#include "training_functions.h"

void is_prime_number()
{
    bool check = true;
    int a;
    std::cout << "Please insert the number, the program will check is it prime number or not\n";
    std::cin >> a;
    std::cin.ignore();

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
    std::cout << "Please enter the number of prime numbers to generate:\n";
    std::cin >> b;
    std::cin.ignore();
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
    std::cout << "enter the upper range to which the generation of prime numbers is to be made:\n";
    std::cin >> top_border;
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
    std::cout << "enter first number:\n";
    std::cin >> a;
    std::cout << "enter second number:\n";
    std::cin >> b;


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
    std::cout << "enter first number:\n";
    std::cin >> a;
    std::cout << "enter second number:\n";
    std::cin >> b;


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
    std::cout << "enter number count factorial:\n";
    std::cin >> a;
    while (a < 0 || a > 20)
    {
        std::cout << "enter number count factorial(0-20):\n";
        std::cin >> a;
    }
    for (short int i = 1; i <= a; i++)
    {
        factorial *= i;
        //std::cout << i<<". "<<factorial << '\n';
    }
    std::cout << "the factorial:\n" << factorial << '\n';
}

unsigned long long factorial_f(int n)
{
    if (n == 1)
        return 1;

        return (factorial_f(n - 1) * n);
}

void factorial_recursively()
{
    short int a;
    unsigned long long factorial = 1;
    std::cout << "enter number count factorial:\n";
    std::cin >> a;
    while (a < 0 || a > 20)
    {
        std::cout << "enter number count factorial(0-20):\n";
        std::cin >> a;
    }
    if (factorial != 0)
        factorial = factorial_f(a);

    std::cout << "the factorial:\n" << factorial << '\n';

}