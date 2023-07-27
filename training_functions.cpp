#include <iostream>
#include <cmath>
#include "training_functions.h"
#include "game_of_life_functions.h"
#include "sorting_lib.h"
#include "math_algoritms.h"
#include "string_algorithms.h"

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
    word_back,
    palindrome_test,
    game_of_life,
    sorting_times_check,
};

void menu_screen()
{
    short int selection;
    for (;;)
    {
        do
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
                << "    * 11. Word backwards.                              *\n"
                << "    * 12. Palindrome test.                             *\n"
                << "    * 13. Game of life.                                *\n"
                << "    * 14. Sorting times test.                          *\n"
                << "    * 15. Exit                                         *\n"
                << "    ****************************************************\n";
            std::cin >> selection;



            system("cls");
        } while (!(isRight()) || selection < 0 || selection==0 || selection > 15 );
        //system("cls");
        switch (selection)
        {
        case prime_number_check:
            {
                std::cout << "1.  Is it prime number, or not?\n\n";
                is_prime_number();
            }
        break;
        
        case prime_number_list:
        {
            std::cout << "2.  How many prime numbers for generate?\n\n";
            prime_number_generator();
        }
        break;
        
        case primeNumber_list_up_border:
        {
            std::cout << "3.  Prime numbers generation list till select.\n\n";
            prime_number_generator_sieve_of_eratosthenes();
        }
        break;

        case greatest_common_divisor:
        {
            std::cout << "4.  Greatest common divisor iteratively.\n\n";
            euclidean_algorithm();
        }
        break;

        case greatest_common_divisor2:
        {
            std::cout << "5.  Greatest common divisor recursively.\n\n";
            euclidean_algorithm_modulo();
        }
        break;

        case factorial_list:
        {
            std::cout << "6.  How many factorial numbers for generate?\n\n";
            factorial_iteratively();
        }
        break;

        case factorial_one_number:
        {
            std::cout << "7.  Which one factorial number generate?\n\n";
            factorial();
        }
        break;

        case fibonacci_list:
        {
            std::cout << "8.  How many fibonacci numbers for generate?\n\n";
            fibonacci_iteratively();
        }
        break;

        case fibonacci_one_number:
        {
            std::cout << "9.  Which one fibonacci number generate?\n\n";
            fibonacci_recursively();
        }
        break;

        case exponent:
        {
            std::cout << "10. Exponentiation calculator.\n\n";
            exponentiation();
        }
        break;

        case word_back:
        {
            std::cout << "11. Word backwards.\n\n";
            word_backwards();
        }
        break;

        case palindrome_test:
        {
            std::cout << "13. Palindrome test.\n\n";
            palindrome_word_check();
        }
        break;
        
        case game_of_life:
        {
            short_game_of_life();
        }

        break;

        case sorting_times_check:
        {
            sorting_times();
        }

        break;

        default:

            break;

        }

        system("pause");
        system("cls");
        if (selection == 15)
            break;
    }
}

bool isRight()
{
    if (std::cin.rdstate())
    {
        std::cin.clear();
        std::cin.ignore(1024, '\n');

        system("cls");

        return false;
    }

    return true;
}