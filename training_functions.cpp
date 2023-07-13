#include <iostream>
#include <cmath>
#include "training_functions.h"

enum training_functions 
{
    prime_number_check = 1,
    prime_number_list,
    primeNumber_list_up_border,
    greatest_common_divisor,
    greatest_common_divisor2,
    factorial_list,
    factorial_one_number,
    fibonacci_list,
    fibonacci_one_number,
    exponent,
};

void menu_screen()
{
    short int selection;
    for (;;)
    {
        std::cout
            << "    ****************************************************\n"
            << "    *                      MENU                        *\n"
            << "    ****************************************************\n"
            << "    *                 select option                    *\n"
            << "    ****************************************************\n"
            << "    * 1.  Is it prime number, or not?                  *\n"
            << "    * 2.  How many prime numbers for generate?         *\n"
            << "    * 3.  Prime numbers generation list till select.   *\n"
            << "    * 4.  Greatest common divisor iteratively.         *\n"
            << "    * 5.  Greatest common divisor recursively.         *\n"
            << "    * 6.  How many factorial numbers for generate?     *\n"
            << "    * 7.  Which one factorial number generate?         *\n"
            << "    * 8.  How many fibonacci numbers for generate?     *\n"
            << "    * 9.  Which one fibonacci number generate?         *\n"
            << "    * 10. Exponentiation calculator.                   *\n"
            << "    * 11. Exit                                         *\n"
            << "    ****************************************************\n";
        std::cin >> selection;
        system("cls");
        switch (selection)
        {
        case prime_number_check:
            {
                std::cout << "1.  Is it prime number, or not?\n\n";
            }
        break;
        
        case prime_number_list:
        {
            std::cout << "2.  How many prime numbers for generate?\n\n";
        }
        break;
        
        case primeNumber_list_up_border:
        {
            std::cout << "3.  Prime numbers generation list till select.\n\n";
        }
        break;

        case greatest_common_divisor:
        {
            std::cout << "4.  Greatest common divisor iteratively.\n\n";
        }
        break;

        case greatest_common_divisor2:
        {
            std::cout << "5.  Greatest common divisor recursively.\n\n";
        }
        break;

        case factorial_list:
        {
            std::cout << "6.  How many factorial numbers for generate?\n\n";
        }
        break;

        case factorial_one_number:
        {
            std::cout << "7.  Which one factorial number generate?\n\n";
        }
        break;

        case fibonacci_list:
        {
            std::cout << "8.  How many fibonacci numbers for generate?\n\n";
        }
        break;

        case fibonacci_one_number:
        {
            std::cout << "9.  Which one fibonacci number generate?n\n";
        }
        break;

        case exponent:
        {
            std::cout << "10. Exponentiation calculator.\n\n";
        }
        break;
        
        default:
            break;

        }
        system("pause");
        system("cls");
        if (selection == 11)
            break;
    }
}

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
    std::cout << "enter number count factorial:\n";
    std::cin >> a;
    while (a < 0 || a > 20)
    {
        std::cout << "enter number count factorial(0-20):\n";
        std::cin >> a;
    }
    if (factorial_number != 0)
        factorial_number = factorial(a);

    std::cout << "the factorial:\n" << factorial_number << '\n';

}

void fibonacci_iteratively()
{
    int n;
    unsigned long long left = 0, right = 1, total = 1;

    std::cout << "enter number of fibonacci sequence:\n";
    std::cin >> n;
    while (n < 0 || n > 93)
    {
        std::cout << "enter number of fibonacci sequence(0-93):\n";
        std::cin >> n;
    }
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

    std::cout << "enter which number of fibonacci sequence to print (0 - 40):\n";
    std::cin >> n;
    while (n < 0 || n > 40)
    {
        std::cout << "enter number of fibonacci sequence(0 - 40):\n";
        std::cin >> n;
    }
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

    std::cout << "enter base:\n";
    std::cin >> base;
    std::cout << "enter exponent:\n";
    std::cin >> exponent;
    std::cout << "exponentiation:" << exponentiation(base, exponent) <<'\n';
}